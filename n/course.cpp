#include "course.h"
#include "ui_course.h"

Course::Course(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Course)
{
    ui->setupUi(this);

    setWindowTitle("Simple Student Information System");

    model = new QStandardItemModel(this);

    ui->courseT->setModel(model);

    connect(ui->courseT, &QTableView::clicked, this, &Course::on_courseT_clicked);
    ui->courseT->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

Course::~Course()
{
    delete ui;
    delete model;
}

void Course::saveModelToCSV()
{
    QFile file("/Users/catherine/Downloads/1513/n/Course2.csv");
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&file);

        for (int row = 0; row < model->rowCount(); ++row)
        {
            QStringList rowData;
            for (int col = 0; col < model->columnCount(); ++col)
            {
                QModelIndex index = model->index(row, col);
                QString value = model->data(index).toString();
                rowData.append(value);
            }
            out << rowData.join(",") << "\n";
        }

        file.close();
    }
    else
    {
        QMessageBox::critical(this, "Error", "Unable to open the CSV file for writing.");
    }
}

void Course::on_courseT_clicked(const QModelIndex &index)
{
    selectedModelIndex = index;
}

void Course::loadCSVData()
{
    qDebug() << "loadCSVData called";

    model->clear();

    QFile file("/Users/catherine/Downloads/1513/n/Course2.csv");
    if (file.open(QIODevice::ReadOnly))
    {

        QTextStream in(&file);

        // Read the header line
        QString headerLine = in.readLine();
        QStringList headerLabels = headerLine.split(',');

        // Set the header labels
        model->setHorizontalHeaderLabels(headerLabels);

        int row = 0;

        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList rLine = line.split(',');
            for (int i = 0 ; i < rLine.size() ; i++)
            {
                QString value = rLine.at(i);
                QStandardItem *item = new QStandardItem(value);
                model->setItem(row, i, item);
            }
            row++;
        }
        file.close();
    }
}

void Course::on_showC_clicked()
{
    loadCSVData();
}

void Course::on_addC_clicked()
{
    QString cC = ui->courseC->text().trimmed();
    QString cN = ui->courseN->text().trimmed();

    // Check if both course code and course name are not empty
    if (cC.isEmpty() || cN.isEmpty()) {
        QMessageBox::warning(this, "Missing Information", "Please enter both course code and course name.");
        return;
    }

    // Check if the course already exists in the file
    QFile file("/Users/catherine/Downloads/1513/n/Course2.csv");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields.size() >= 2 && fields[0] == cC && fields[1] == cN) {
                QMessageBox::warning(this, "Duplicate Course", "The course already exists in the file.");
                file.close();
                return;
            }
        }
        file.close();
    } else {
        QMessageBox::critical(this, "Error", "Unable to open the CSV file for reading.");
        return;
    }

    // If the course does not exist, proceed to add it to the file
    QFile courseFile("/Users/catherine/Downloads/1513/n/Course2.csv");
    if (!courseFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QMessageBox::critical(this, "Error", "Unable to open the CSV file for writing.");
        return;
    }
    QTextStream stream(&courseFile);
    stream << cC << "," << cN;
    courseFile.close();

    // Reload data after adding the course
    loadCSVData();

    QMessageBox::information(this, "Data Added", "Data added to the CSV file.");
}

void Course::on_deleteC_clicked()
{
    if (!selectedModelIndex.isValid())
    {
        QMessageBox::warning(this, "Warning", "No item selected for deletion.");
        return;
    }

    int rowToDelete = selectedModelIndex.row();

    QString cC = model->data(model->index(selectedModelIndex.row(), 0)).toString();

    model->removeRow(rowToDelete);

    saveModelToCSV();

    // Clear the selected index
    selectedModelIndex = QModelIndex();

    // Open the second CSV file
    QFile secondFile("/Users/catherine/Downloads/1513/n/Students1.csv");
    if (secondFile.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QTextStream stream(&secondFile);
        QStringList lines;
        bool dataRemoved = false;

        // Read and process each line of the second CSV file
        while (!stream.atEnd())
        {
            QString line = stream.readLine();
            QStringList parts = line.split(',');

            if (parts.size() >= 7 && parts[6] == cC)
            {
                dataRemoved = true;
                continue;
            }

            lines.append(line);
        }

        secondFile.resize(0);

        for (const QString &line : lines)
        {
            stream << line;
        }

        secondFile.close();

        if (dataRemoved)
        {
            QMessageBox::information(this, "Data Removed", "Data removed from the second CSV file.");
        }
        else
        {
            QMessageBox::information(this, "Data Not Found", "Data not found in the second CSV file.");
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "Unable to open the second CSV file for reading: " + secondFile.errorString());
    }
}



