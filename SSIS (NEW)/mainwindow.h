#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIODevice>
#include <QStandardItem>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QString>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton1_clicked();

    void on_deleteButton1_clicked();

    void on_editButton1_clicked();

    void on_saveButton_clicked();

    void on_cancelButton1_clicked();

    void on_searchButton1_clicked();

    void on_searchButton2_clicked();

    void on_addButton2_clicked();

    void on_deleteButton2_clicked();

    void on_editButton2_clicked();

    void on_saveButton2_clicked();

    void on_cancelButton2_clicked();

private:
    Ui::MainWindow *ui;

    void populateTableWidgets();
    void clearStudentContents();
    void clearCourseContents();
    void populateStudentTable();
    void populateCourseTable();
};
#endif // MAINWINDOW_H
