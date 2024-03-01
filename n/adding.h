#ifndef ADDING_H
#define ADDING_H

#include <QDialog>
#include <QMessageBox>
#include <QIODevice>
#include <QLineEdit>
#include <QDebug>
#include <QStringList>

namespace Ui {
class Adding;
}

class Adding : public QDialog
{
    Q_OBJECT

public:
    explicit Adding(QWidget *parent = nullptr);
    ~Adding();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_avaiC_clicked();

private:
    Ui::Adding *ui;

};

#endif // ADDING_H
