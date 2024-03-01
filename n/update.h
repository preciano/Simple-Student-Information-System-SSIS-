#ifndef UPDATE_H
#define UPDATE_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class Update;
}

class Update : public QDialog
{
    Q_OBJECT

public:
    explicit Update(QWidget *parent = nullptr);
    ~Update();

private slots:
    void on_pushButton_clicked();

    void on_EditButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    //void saveToCsv(const QList<QStringList>& data);

    void on_DeleteButton_clicked();

private:
    Ui::Update *ui;

    QStandardItemModel *model;

    //QList<QStringList> originalData;

    QModelIndex selectedModelIndex;  // Store information about the selected item
};

#endif // UPDATE_H
