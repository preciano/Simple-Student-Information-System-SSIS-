#ifndef COURSE_H
#define COURSE_H

#include <QDialog>
#include <QIODevice>
#include <QStandardItemModel>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QStringList>
#include <QLineEdit>
#include <QModelIndex>
#include <QInputDialog>

namespace Ui {
class Course;
}

class Course : public QDialog
{
    Q_OBJECT

public:
    explicit Course(QWidget *parent = nullptr);
    ~Course();

private slots:
    void on_showC_clicked();

    void on_addC_clicked();

    void on_deleteC_clicked();

    void on_courseT_clicked(const QModelIndex &index);

private:
    Ui::Course *ui;

    QStandardItemModel *model;

    void loadCSVData();

    void saveModelToCSV();

    QModelIndex selectedModelIndex;
};

#endif // COURSE_H
