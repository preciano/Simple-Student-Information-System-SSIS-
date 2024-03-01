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
    QString Cou = ui->coursecode->text().trimmed();  // Trim whitespace
    QString Gen = ui->gender->currentText();
    QString year = ui->yerlvl->currentText();
    //QString CourseCode;

    static const QRegularExpression lineSeparator("[\r\n]");

    QFile file1("/Users/catherine/Downloads/1513/n/Course2.csv");
    if (file1.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file1);

        // Read the entire CSV content into a QStringList and handle different line endings
        QStringList csvData = in.readAll().split(lineSeparator);

        // Remove empty strings from the list
        csvData.removeAll(QString());

        qDebug() << "CSV Data:" << csvData;

        bool found = false;
        for (const QString& line : csvData) {
            QStringList cells = line.split(","); // Assuming comma-separated CSV
            if (cells.contains(Cou)) {
                found = true;
                break;
            }
        }

if (found) {
        QMessageBox::information(this, "Match Found", "Data found in the CSV file.");

        QFile studentsFile("/Users/catherine/Downloads/1513/n/Students1.csv");  // Change the path accordingly
        if (!studentsFile.open(QIODevice::ReadWrite | QIODevice::Append)) {
            QMessageBox::critical(this, "Error", "Unable to open the CSV file for writing.");
            return;
        }

        QTextStream stream(&studentsFile);

        // Append the entered data to the CSV file
        stream << "\n" << Sur << "," << Fir << "," << Mid << "," << ID << "," << Gen << "," << year << "," << Cou;

        //emit dataAdded(Sur, Fir, Mid, ID, Gen, year, Cou);

        QMessageBox::information(this, "Data Added", "Data added to the CSV file.");
        studentsFile.close();  // Close the file after writing

        close();

        } else {
            QMessageBox::information(this, "No Match", "Data not found in the CSV file.");
        }
    }
}

void Adding::on_avaiC_clicked()
{
    Course cou;
    cou.setModal(true);
    cou.exec();
}

