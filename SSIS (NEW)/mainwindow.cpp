#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    populateTableWidgets();

    ui->saveButton->hide();
    ui->cancelButton1->hide();

    ui->saveButton2->hide();
    ui->cancelButton2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::populateTableWidgets()
{
    // Populate courseT
    QFile courseFile("/Users/catherine/Downloads/new CSV/SSIS/Course2.csv");
    if (courseFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&courseFile);

        // Read and set the headers
        if (!in.atEnd()) {
            QString headerLine = in.readLine();
            QStringList headers = headerLine.split(",");
            ui->courseT->setColumnCount(headers.size());
            ui->courseT->setHorizontalHeaderLabels(headers);
        }

        // Read and set the data rows
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            int currentRow = ui->courseT->rowCount();
            ui->courseT->insertRow(currentRow);
            for (int i = 0; i < fields.size(); ++i) {
                QTableWidgetItem *item = new QTableWidgetItem(fields[i]);
                ui->courseT->setItem(currentRow, i, item);
            }
        }
        courseFile.close();

        // Stretch the columns
        ui->courseT->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    } else {
        qDebug() << "Failed to open courses.csv. Error:" << courseFile.errorString();
    }

    // Populate studentT
    QFile studentFile("/Users/catherine/Downloads/new CSV/SSIS/Students1.csv");
    if (studentFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&studentFile);

        // Read and set the headers
        if (!in.atEnd()) {
            QString headerLine = in.readLine();
            QStringList headers = headerLine.split(",");
            ui->studentT->setColumnCount(headers.size());
            ui->studentT->setHorizontalHeaderLabels(headers);
        }

        // Read and set the data rows
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            int currentRow = ui->studentT->rowCount();
            ui->studentT->insertRow(currentRow);
            for (int i = 0; i < fields.size(); ++i) {
                QTableWidgetItem *item = new QTableWidgetItem(fields[i]);
                ui->studentT->setItem(currentRow, i, item);
            }
        }
        studentFile.close();
    } else {
        qDebug() << "Failed to open students.csv. Error:" << studentFile.errorString();
    }
}

void MainWindow::populateCourseTable()
{
    // Clear the current content
    ui->courseT->setRowCount(0);

    QFile courseFile("/Users/catherine/Downloads/new CSV/SSIS/Course2.csv");
    if (courseFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&courseFile);

        // Read and set the headers
        if (!in.atEnd()) {
            QString headerLine = in.readLine();
            QStringList headers = headerLine.split(",");
            ui->courseT->setColumnCount(headers.size());
            ui->courseT->setHorizontalHeaderLabels(headers);
        }

        // Read and set the data rows
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            int currentRow = ui->courseT->rowCount();
            ui->courseT->insertRow(currentRow);
            for (int i = 0; i < fields.size(); ++i) {
                QTableWidgetItem *item = new QTableWidgetItem(fields[i]);
                ui->courseT->setItem(currentRow, i, item);
            }
        }
        courseFile.close();
    } else {
        qDebug() << "Failed to open students.csv. Error:" << courseFile.errorString();
    }
}

void MainWindow::populateStudentTable()
{
    // Clear the current content
    ui->studentT->setRowCount(0);

    QFile studentFile("/Users/catherine/Downloads/new CSV/SSIS/Students1.csv");
    if (studentFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&studentFile);

        // Read and set the headers
        if (!in.atEnd()) {
            QString headerLine = in.readLine();
            QStringList headers = headerLine.split(",");
            ui->studentT->setColumnCount(headers.size());
            ui->studentT->setHorizontalHeaderLabels(headers);
        }

        // Read and set the data rows
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            int currentRow = ui->studentT->rowCount();
            ui->studentT->insertRow(currentRow);
            for (int i = 0; i < fields.size(); ++i) {
                QTableWidgetItem *item = new QTableWidgetItem(fields[i]);
                ui->studentT->setItem(currentRow, i, item);
            }
        }
        studentFile.close();
    } else {
        qDebug() << "Failed to open students.csv. Error:" << studentFile.errorString();
    }
}

void MainWindow::clearStudentContents()
{
    ui->lastName->clear();
    ui->middleName->clear();
    ui->firstName->clear();
    ui->ID->clear();
    ui->course->clear();
}

void MainWindow::clearCourseContents()
{
    ui->cC->clear();
    ui->cN->clear();
}

void MainWindow::on_addButton1_clicked()
{
    QString lastN = ui->lastName->text();
    QString midN = ui->middleName->text();
    QString firstN = ui->firstName->text();
    QString gen = ui->gender->currentText();
    QString level = ui->yrLvl->currentText();
    QString id = ui->ID->text();
    QString course = ui->course->text();

    // Check if the course code exists in the Course2.csv file
    QFile courseFile("/Users/catherine/Downloads/new CSV/SSIS/Course2.csv");
    if (!courseFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open the Course file for reading.");
        return;
    }

    QTextStream courseStream(&courseFile);
    bool foundCourse = false;
    while (!courseStream.atEnd()) {
        QString line = courseStream.readLine();
        QStringList fields = line.split(",");
        if (fields.size() >= 1 && fields[0] == course) {
            foundCourse = true;
            break;
        }
    }
    courseFile.close();

    if (!foundCourse) {
        QMessageBox::warning(this, "Invalid Course", "The entered course code does not exist.");
        return;
    }

    // Check if the ID already exists in the file
    QFile studentFile("/Users/catherine/Downloads/new CSV/SSIS/Students1.csv");
    if (studentFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&studentFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields.size() >= 4 && fields[3] == id) {
                QMessageBox::warning(this, "Duplicate ID", "ID already exists in the file. Please enter a different ID.");
                studentFile.close();
                return; // Exit the function without adding the data
            }
        }
        studentFile.close();
    } else {
        QMessageBox::critical(this, "Error", "Unable to open the file for reading.");
        return;
    }

    // If the ID is not found and the course code is valid, proceed to add the data
    QFile studentsFile("/Users/catherine/Downloads/new CSV/SSIS/Students1.csv");
    if (!studentsFile.open(QIODevice::ReadWrite | QIODevice::Append)) {
        QMessageBox::critical(this, "Error", "Unable to open the CSV file for writing.");
        return;
    }

    QTextStream stream(&studentsFile);
    stream << "\n" << lastN << "," << firstN << "," << midN << "," << id << "," << gen << "," << level << "," << course;

    QMessageBox::information(this, "Data Added", "Data added to the CSV file.");
    studentsFile.close();
    clearStudentContents();
    populateStudentTable();
}

void MainWindow::on_deleteButton1_clicked()
{
    int currentRow = ui->studentT->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Selection Error", "Please select a row to delete.");
        return;
    }

    QString id = ui->studentT->item(currentRow, 3)->text();

    QFile studentFile("/Users/catherine/Downloads/new CSV/SSIS/Students1.csv");
    if (!studentFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open the file for reading.");
        return;
    }

    QStringList lines;
    QTextStream in(&studentFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() >= 4 && fields[3] != id) {
            lines.append(line);
        }
    }
    studentFile.close();

    if (!studentFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::critical(this, "Error", "Unable to open the file for writing.");
        return;
    }

    QTextStream out(&studentFile);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    studentFile.close();

    populateStudentTable();
    QMessageBox::information(this, "Data Deleted", "Selected row has been deleted.");
}

void MainWindow::on_editButton1_clicked()
{
    int currentRow = ui->studentT->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Selection Error", "Please select a row to edit.");
        return;
    }

    // Extract data from the selected row
    QString lastName = ui->studentT->item(currentRow, 0)->text();
    QString firstName = ui->studentT->item(currentRow, 1)->text();
    QString middleName = ui->studentT->item(currentRow, 2)->text();
    QString id = ui->studentT->item(currentRow, 3)->text();
    QString gender = ui->studentT->item(currentRow, 4)->text();
    QString yearLevel = ui->studentT->item(currentRow, 5)->text();
    QString course = ui->studentT->item(currentRow, 6)->text();

    // Populate line edits with the extracted data
    ui->lastName->setText(lastName);
    ui->firstName->setText(firstName);
    ui->middleName->setText(middleName);
    ui->ID->setText(id);
    ui->gender->setCurrentText(gender);
    ui->yrLvl->setCurrentText(yearLevel);
    ui->course->setText(course);

    // Show save and cancel buttons for editing
    ui->saveButton->show();
    ui->cancelButton1->show();
}

void MainWindow::on_saveButton_clicked()
{
    QString lastName = ui->lastName->text();
    QString firstName = ui->firstName->text();
    QString middleName = ui->middleName->text();
    QString id = ui->ID->text();
    QString gender = ui->gender->currentText();
    QString yearLevel = ui->yrLvl->currentText();
    QString course = ui->course->text();

    // Check if the course code exists in the Course2.csv file
    QFile courseFile("/Users/catherine/Downloads/new CSV/SSIS/Course2.csv");
    if (!courseFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open the Course file for reading.");
        return;
    }

    QTextStream courseStream(&courseFile);
    bool foundCourse = false;
    while (!courseStream.atEnd()) {
        QString line = courseStream.readLine();
        QStringList fields = line.split(",");
        if (fields.size() >= 1 && fields[0] == course) {
            foundCourse = true;
            break;
        }
    }
    courseFile.close();

    if (!foundCourse) {
        QMessageBox::warning(this, "Invalid Course", "The entered course code does not exist.");
        return;
    }

    // Check if the ID exists in the file
    QFile studentFile("/Users/catherine/Downloads/new CSV/SSIS/Students1.csv");
    if (!studentFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open the file for reading and writing.");
        return;
    }

    QStringList lines;
    QTextStream in(&studentFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() >= 4 && fields[3] == id) {
            // Update the row with the edited data
            line = lastName + "," + firstName + "," + middleName + "," + id + "," + gender + "," + yearLevel + "," + course;
        }
        lines.append(line);
    }
    studentFile.close();

    if (!studentFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::critical(this, "Error", "Unable to open the file for writing.");
        return;
    }

    QTextStream out(&studentFile);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    studentFile.close();

    // Update the table widget
    populateStudentTable();

    ui->saveButton->hide();
    ui->cancelButton1->hide();

    QMessageBox::information(this, "Data Updated", "Data has been successfully updated.");
}

void MainWindow::on_cancelButton1_clicked()
{
    clearStudentContents();

    ui->saveButton->hide();
    ui->cancelButton1->hide();
}

void MainWindow::on_searchButton1_clicked()
{
    // Retrieve the search query from the line edit
    QString searchQuery = ui->lineSearch->text().trimmed();
    if (searchQuery.isEmpty()) {
        QMessageBox::warning(this, "Search Error", "Please enter a search query.");
        return;
    }

    bool found = false;
    QTableWidgetItem *item;
    // Iterate through the rows of the table widget to find the matching data
    for (int row = 0; row < ui->studentT->rowCount(); ++row) {
        for (int col = 0; col < ui->studentT->columnCount(); ++col) {
            item = ui->studentT->item(row, col);
            if (item && item->text().contains(searchQuery, Qt::CaseInsensitive)) {
                // Highlight the row if the data is found
                ui->studentT->selectRow(row);
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (!found) {
        QMessageBox::information(this, "Search Result", "No matching data found.");
    }
}

void MainWindow::on_searchButton2_clicked()
{
    // Retrieve the search query from the line edit
    QString searchQuery = ui->lineSearch2->text().trimmed();
    if (searchQuery.isEmpty()) {
        QMessageBox::warning(this, "Search Error", "Please enter a search query.");
        return;
    }

    bool found = false;
    QTableWidgetItem *item;
    // Iterate through the rows of the table widget to find the matching data
    for (int row = 0; row < ui->courseT->rowCount(); ++row) {
        for (int col = 0; col < ui->courseT->columnCount(); ++col) {
            item = ui->courseT->item(row, col);
            if (item && item->text().contains(searchQuery, Qt::CaseInsensitive)) {
                // Highlight the row if the data is found
                ui->courseT->selectRow(row);
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (!found) {
        QMessageBox::information(this, "Search Result", "No matching data found.");
    }
}

void MainWindow::on_addButton2_clicked()
{
    QString code = ui->cC->text();
    QString name = ui->cN->text();

    // Check if both course code and course name are not empty
    if (code.isEmpty() || name.isEmpty()) {
        QMessageBox::warning(this, "Missing Information", "Please enter both course code and course name.");
        return;
    }

    // Check if the course already exists in the file
    QFile file("/Users/catherine/Downloads/new CSV/SSIS/Course2.csv");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields.size() >= 2 && fields[0] == code && fields[1] == name) {
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
    QFile courseFile("/Users/catherine/Downloads/new CSV/SSIS/Course2.csv");
    if (!courseFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QMessageBox::critical(this, "Error", "Unable to open the CSV file for writing.");
        return;
    }
    QTextStream stream(&courseFile);
    stream << "\n" << code << "," << name;
    courseFile.close();

    // Reload data after adding the course
    populateCourseTable();

    clearCourseContents();

    QMessageBox::information(this, "Data Added", "Data added to the CSV file.");
}

void MainWindow::on_deleteButton2_clicked()
{
    int currentRow = ui->courseT->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Selection Error", "Please select a row to delete.");
        return;
    }

    // Retrieve the course code from the selected row
    QString courseCode = ui->courseT->item(currentRow, 0)->text();

    // Remove the course from students who are enrolled in it
    for (int row = 0; row < ui->studentT->rowCount(); ++row) {
        if (ui->studentT->item(row, 6)->text() == courseCode) {
            // Remove the course from the student's record in the table widget
            ui->studentT->item(row, 6)->setText("");
        }
    }

    // Update the CSV file to reflect the changes
    QFile studentFile("/Users/catherine/Downloads/new CSV/SSIS/Students1.csv");
    if (!studentFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open the file for reading and writing.");
        return;
    }

    QStringList lines;
    QTextStream in(&studentFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() >= 7 && fields[6] == courseCode) {
            fields[6] = ""; // Remove the course from the student's record
            line = fields.join(",");
        }
        lines.append(line);
    }
    studentFile.close();

    if (!studentFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::critical(this, "Error", "Unable to open the file for writing.");
        return;
    }

    QTextStream out(&studentFile);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    studentFile.close();

    // Remove the selected row from the course table widget
    ui->courseT->removeRow(currentRow);

    QMessageBox::information(this, "Row Deleted", "Selected row has been successfully deleted.");
}

void MainWindow::on_editButton2_clicked()
{
    int currentRow = ui->courseT->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Selection Error", "Please select a row to edit.");
        return;
    }

    // Extract data from the selected row
    QString code = ui->courseT->item(currentRow, 0)->text();
    QString name = ui->courseT->item(currentRow, 1)->text();

    // Populate line edits with the extracted data
    ui->cC->setText(code);
    ui->cN->setText(name);

    // Show save and cancel buttons for editing
    ui->saveButton2->show();
    ui->cancelButton2->show();
}

void MainWindow::on_saveButton2_clicked()
{
    QString code = ui->cC->text();
    QString name = ui->cN->text();

    int currentRow = ui->courseT->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Selection Error", "Please select a row to save.");
        return;
    }

    QString oldCode = ui->courseT->item(currentRow, 0)->text();

    // Check if the course code has been edited
    bool courseCodeEdited = (oldCode != code);

    // Check if the edited course code already exists in courseT
    for (int row = 0; row < ui->courseT->rowCount(); ++row) {
        if (row != currentRow && ui->courseT->item(row, 0)->text() == code) {
            QMessageBox::warning(this, "Duplicate Course Code", "The edited course code already exists in the table. Please enter a different course code.");
            return;
        }
    }

    // Update the data in the table widget
    ui->courseT->item(currentRow, 0)->setText(code);
    ui->courseT->item(currentRow, 1)->setText(name);

    // Update the data in the CSV file
    QFile courseFile("/Users/catherine/Downloads/new CSV/SSIS/Course2.csv");
    if (!courseFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open the file for reading and writing.");
        return;
    }

    QStringList lines;
    QTextStream in(&courseFile);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (fields.size() >= 2 && fields[0] == oldCode) {
            line = code + "," + name;
        }
        lines.append(line);
    }
    courseFile.close();

    if (!courseFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::critical(this, "Error", "Unable to open the file for writing.");
        return;
    }

    QTextStream out(&courseFile);
    for (const QString &line : lines) {
        out << line << "\n";
    }
    courseFile.close();

    // If the course code has been edited, update the course for students in studentT
    if (courseCodeEdited) {
        // Update the course for students who are enrolled in the edited course
        for (int row = 0; row < ui->studentT->rowCount(); ++row) {
            if (ui->studentT->item(row, 6)->text() == oldCode) {
                // Update the course for the student in the table widget
                ui->studentT->item(row, 6)->setText(code);
            }
        }

        // Update the course for students in the CSV file
        QFile studentFile("/Users/catherine/Downloads/new CSV/SSIS/Students1.csv");
        if (!studentFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QMessageBox::critical(this, "Error", "Unable to open the file for reading and writing.");
            return;
        }

        QStringList studentLines;
        QTextStream studentIn(&studentFile);
        while (!studentIn.atEnd()) {
            QString studentLine = studentIn.readLine();
            QStringList studentFields = studentLine.split(",");
            if (studentFields.size() >= 7 && studentFields[6] == oldCode) {
                studentFields[6] = code; // Update the course for the student
                studentLine = studentFields.join(",");
            }
            studentLines.append(studentLine);
        }
        studentFile.close();

        if (!studentFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
            QMessageBox::critical(this, "Error", "Unable to open the file for writing.");
            return;
        }

        QTextStream studentOut(&studentFile);
        for (const QString &line : studentLines) {
            studentOut << line << "\n";
        }
        studentFile.close();
    }

    clearCourseContents();

    // Hide save and cancel buttons after saving
    ui->saveButton2->hide();
    ui->cancelButton2->hide();

    QMessageBox::information(this, "Data Updated", "Data has been successfully updated.");
}

void MainWindow::on_cancelButton2_clicked()
{
    clearCourseContents();

    ui->saveButton2->hide();
    ui->cancelButton2->hide();
}

