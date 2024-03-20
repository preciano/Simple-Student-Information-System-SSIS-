#include "adding.h"
#include "ui_adding.h"
#include "mainwindow.h"
#include "course.h"
#include <QFile>
#include <QMovie>

Adding::Adding(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Adding)
{
    ui->setupUi(this);

    setWindowTitle("Simple Student Information System");
}

Adding::~Adding()
{
    delete ui;
}

void Adding::on_pushButton_2_clicked()
{
    close();
}


void Adding::on_pushButton_clicked()
{
    QString Sur = ui->surname->text();
    QString Fir = ui->firstname->text();
    QString Mid = ui->middlename->text();
    QString ID = ui->idnum->text();
    QString Cou = ui->coursecode->text().trimmed();
    QString Gen = ui->gender->currentText();
    QString year = ui->yerlvl->currentText();

    // Check if the course code exists in the Course2.csv file
    QFile courseFile("/Users/catherine/Downloads/1513/n/Course2.csv");
    if (!courseFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open the Course file for reading.");
        return;
    }

    QTextStream courseStream(&courseFile);
    bool foundCourse = false;
    while (!courseStream.atEnd()) {
        QString line = courseStream.readLine();
        QStringList fields = line.split(",");
        if (fields.size() >= 1 && fields[0] == Cou) {
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
    QFile studentFile("/Users/catherine/Downloads/1513/n/Students1.csv");
    if (studentFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&studentFile);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields.size() >= 4 && fields[3] == ID) {
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
    QFile studentsFile("/Users/catherine/Downloads/1513/n/Students1.csv");
    if (!studentsFile.open(QIODevice::ReadWrite | QIODevice::Append)) {
        QMessageBox::critical(this, "Error", "Unable to open the CSV file for writing.");
        return;
    }

    QTextStream stream(&studentsFile);
    stream << Sur << "," << Fir << "," << Mid << "," << ID << "," << Gen << "," << year << "," << Cou;

    QMessageBox::information(this, "Data Added", "Data added to the CSV file.");
    studentsFile.close();
    close();
}

void Adding::on_avaiC_clicked()
{
    Course cou;
    cou.setModal(true);
    cou.exec();
}

