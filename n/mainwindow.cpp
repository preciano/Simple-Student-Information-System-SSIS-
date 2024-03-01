#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QMovie>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Simple Student Information System");

    model = new QStandardItemModel(this);

    ui->tableView->setModel(model);    
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
}

void MainWindow::loadCSVData()
{
    qDebug() << "loadCSVData called";

    model->clear();

    QFile file("/Users/catherine/Downloads/1513/n/Students1.csv");
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

void MainWindow::on_pushButton_clicked()
{
    loadCSVData();
}

void MainWindow::on_pushButton_3_clicked()
{
    Adding add;
    add.setModal(true);
    add.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    Update up;
    up.setModal(true);
    up.exec();
}

