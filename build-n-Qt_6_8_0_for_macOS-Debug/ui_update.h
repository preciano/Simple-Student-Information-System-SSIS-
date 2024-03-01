/********************************************************************************
** Form generated from reading UI file 'update.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATE_H
#define UI_UPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Update
{
public:
    QGroupBox *groupBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *DeleteButton;
    QPushButton *EditButton;

    void setupUi(QDialog *Update)
    {
        if (Update->objectName().isEmpty())
            Update->setObjectName("Update");
        Update->resize(621, 401);
        groupBox = new QGroupBox(Update);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 601, 381));
        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 30, 581, 341));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(widget);
        tableView->setObjectName("tableView");

        verticalLayout_2->addWidget(tableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        DeleteButton = new QPushButton(widget);
        DeleteButton->setObjectName("DeleteButton");

        horizontalLayout_2->addWidget(DeleteButton);

        EditButton = new QPushButton(widget);
        EditButton->setObjectName("EditButton");

        horizontalLayout_2->addWidget(EditButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Update);

        QMetaObject::connectSlotsByName(Update);
    } // setupUi

    void retranslateUi(QDialog *Update)
    {
        Update->setWindowTitle(QCoreApplication::translate("Update", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Update", "Update", nullptr));
        pushButton->setText(QCoreApplication::translate("Update", "Search ID #", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("Update", "e.g. 2022-0001", nullptr));
        DeleteButton->setText(QCoreApplication::translate("Update", "Delete", nullptr));
        EditButton->setText(QCoreApplication::translate("Update", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Update: public Ui_Update {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATE_H
