#include "update.h"
#include "ui_update.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QInputDialog>

Update::Update(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::Update)
{
    ui->setupUi(this);

    setWindowTitle("Simple Student Information System");

    // Set up your table view (assuming you have a QTableView named tableView)
    QStandardItemModel *model = new QStandardItemModel(this);
    ui->tableView->setModel(model);

    connect(ui->tableView, &QTableView::clicked, this, &Update::on_tableView_clicked);
}

Update::~Update()
{
    delete ui;
}

void Update::on_pushButton_clicked()
{
    // Get the search query from the user
    QString searchQuery = ui->lineEdit->text().trimmed();  // Assuming you have a QLineEdit named searchLineEdit

    // Check if the search query is not empty
    if (searchQuery.isEmpty()) {
        QMessageBox::information(this, "Empty Search", "Please enter a search query.");
        return;
    }

    // Read the CSV file and search for the data
    QFile file("/Users/catherine/Downloads/1513/n/Students1.csv");  // Replace with the actual path to your CSV file
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);

        // Assuming a comma-separated CSV file, update the delimiter if needed
        QStringList headerLabels;
        if (!in.atEnd()) {
            QString headerLine = in.readLine();
            headerLabels = headerLine.split(',');
        }

        // Create a new model to temporarily store the matched row
        QStandardItemModel *newModel = new QStandardItemModel(this);
        newModel->setColumnCount(headerLabels.size());
        newModel->setHorizontalHeaderLabels(headerLabels);

        // Process each line in the CSV file
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList cells = line.split(',');

            // Check if the search query matches any cell in the current line
            if (cells.contains(searchQuery)) {
                QList<QStandardItem*> newRow;
                // Populate the cells in the new model (matched row)
                for (const QString& cell : cells) {
                    QStandardItem* item = new QStandardItem(cell);
                    newRow.append(item);
                }
                newModel->appendRow(newRow);
            }
        }

        // Reset the file position to the beginning
        file.seek(0);

        // Create the main model
        QStandardItemModel *model = new QStandardItemModel(this);
        model->setColumnCount(headerLabels.size());
        model->setHorizontalHeaderLabels(headerLabels);

        // Process each line in the CSV file again
        bool isFirstRowReplaced = false;
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList cells = line.split(',');

            // Populate the cells in the main model (excluding the matched row)
            if (!cells.contains(searchQuery)) {
                QList<QStandardItem*> newRow;
                for (const QString& cell : cells) {
                    QStandardItem* item = new QStandardItem(cell);
                    newRow.append(item);
                }
                model->appendRow(newRow);

                if (!isFirstRowReplaced) {
                    // Replace the first row with the matched row
                    for (int i = 0; i < newModel->columnCount(); ++i) {
                        model->setItem(0, i, newModel->item(0, i)->clone());
                    }
                    isFirstRowReplaced = true;
                }
            }
        }

        file.close();

        // If no match is found
        if (!isFirstRowReplaced) {
            QMessageBox::information(this, "No Match", "Data not found in the CSV file.");
        } else {
            // Set the first row as selected (the matched row)
            QModelIndex index = model->index(0, 0);
            ui->tableView->selectionModel()->setCurrentIndex(index, QItemSelectionModel::Select);
        }

        // Update the table view with the new model
        ui->tableView->setModel(model);
    }
}

void Update::on_tableView_clicked(const QModelIndex &index)
{
    // Store information about the selected item (row and column)
    selectedModelIndex = index;
}

void Update::on_EditButton_clicked()
{
    // Check if an item is selected
    if (!selectedModelIndex.isValid()) {
        QMessageBox::information(this, "No Selection", "Please select an item to edit.");
        return;
    }

    // Get the selected item from the model
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView->model());
    QStandardItem *selectedItem = model->itemFromIndex(selectedModelIndex);

    // Get the new value from the user
    bool ok;
    QString newValue = QInputDialog::getText(this, "Edit Value", "Enter new value:", QLineEdit::Normal, selectedItem->text(), &ok);

    // Check if the user pressed OK and the new value is not empty
    if (ok && !newValue.isEmpty()) {
        // Update the model with the new value
        selectedItem->setText(newValue);

        // Save the changes to the CSV file (if needed)
        QFile file("/Users/catherine/Downloads/1513/n/Students1.csv");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);

            // Write the header line
            QStringList headerLabels;
            for (int column = 0; column < model->columnCount(); ++column) {
                headerLabels << model->horizontalHeaderItem(column)->text();
            }
            out << headerLabels.join(",") << "\n";

            // Write the data
            for (int row = 0; row < model->rowCount(); ++row) {
                QStringList rowData;
                for (int column = 0; column < model->columnCount(); ++column) {
                    QStandardItem *item = model->item(row, column);
                    rowData << item->text();
                }
                out << rowData.join(",") << "\n";
            }

            file.close();
            QMessageBox::information(this, "Data Updated", "Changes saved to the CSV file.");
        }
    }
}

void Update::on_DeleteButton_clicked()
{
    // Check if an item is selected
    if (!selectedModelIndex.isValid()) {
        QMessageBox::information(this, "No Selection", "Please select an item to delete.");
        return;
    }

    // Get the selected item from the model
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView->model());
    int rowIndex = selectedModelIndex.row();

    // Remove the selected row only if it's within the model's range
    if (rowIndex >= 0 && rowIndex < model->rowCount()) {
        model->removeRow(rowIndex);

        // Reset selectedModelIndex to avoid potential issues
        selectedModelIndex = QModelIndex();

        // Save the changes to the CSV file
        QFile file("/Users/catherine/Downloads/1513/n/Students1.csv");
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);

            // Write the header line
            QStringList headerLabels;
            for (int column = 0; column < model->columnCount(); ++column) {
                headerLabels << model->horizontalHeaderItem(column)->text();
            }
            out << headerLabels.join(",") << "\n";

            // Write all data (both searched and non-searched)
            for (int row = 0; row < model->rowCount(); ++row) {
                QStringList rowData;
                for (int column = 0; column < model->columnCount(); ++column) {
                    QStandardItem *item = model->item(row, column);
                    rowData << item->text();
                }
                out << rowData.join(",") << "\n";
            }

            file.close();
            QMessageBox::information(this, "Data Deleted", "Selected data and the entire row deleted. Changes saved to the CSV file.");
        } else {
            QMessageBox::warning(this, "File Error", "Unable to open the CSV file for writing.");
        }
    } else {
        QMessageBox::information(this, "Invalid Selection", "Selected item is not valid.");
    }
}

