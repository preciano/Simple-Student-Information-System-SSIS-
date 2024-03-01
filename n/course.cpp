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
    // Store information about the selected item (row and column)
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
    QString cC = ui->courseC->text();
    QString cN = ui->courseN->text();

    QFile studentsFile("/Users/catherine/Downloads/1513/n/Course2.csv");  // Change the path accordingly
    if (!studentsFile.open(QIODevice::ReadWrite | QIODevice::Append)) {
        QMessageBox::critical(this, "Error", "Unable to open the CSV file for writing.");
        return;
    }
    QTextStream stream(&studentsFile);

    // Append the entered data to the CSV file
    stream << "\n" << cC << "," << cN;

    QMessageBox::information(this, "Data Added", "Data added to the CSV file.");
    studentsFile.close();  // Close the file after writing
}

void Course::on_deleteC_clicked()
{
    // Check if any item is selected
    if (!selectedModelIndex.isValid())
    {
        QMessageBox::warning(this, "Warning", "No item selected for deletion.");
        return;
    }

    // Get the row from the selected index
    int rowToDelete = selectedModelIndex.row();

    // Get the data from the selected row in the first file
    QString cC = model->data(model->index(selectedModelIndex.row(), 0)).toString();

    // Remove the selected row from the model
    model->removeRow(rowToDelete);

    // Save the changes back to the CSV file
    saveModelToCSV();

    // Clear the selected index
    selectedModelIndex = QModelIndex();

    // Open the second CSV file
    QFile secondFile("/Users/catherine/Downloads/1513/n/Students1.csv"); // Change the path accordingly
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

            // Check if the line matches the data to be deleted in the 7th column
            if (parts.size() >= 7 && parts[6] == cC)
            {
                dataRemoved = true;
                continue; // Skip this line, don't add it to the lines list
            }

            lines.append(line); // Add the line to the list
        }

        secondFile.resize(0); // Clear the content of the file

        // Rewrite the remaining lines back to the second CSV file
        for (const QString &line : lines)
        {
            stream << line;
        }

        secondFile.close(); // Close the second file

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



