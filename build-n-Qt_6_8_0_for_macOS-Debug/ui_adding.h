/********************************************************************************
** Form generated from reading UI file 'adding.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDING_H
#define UI_ADDING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Adding
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *surname;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *firstname;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *middlename;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QComboBox *gender;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *idnum;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *coursecode;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QComboBox *yerlvl;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *avaiC;

    void setupUi(QDialog *Adding)
    {
        if (Adding->objectName().isEmpty())
            Adding->setObjectName("Adding");
        Adding->resize(410, 310);
        groupBox = new QGroupBox(Adding);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 10, 391, 286));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"                           background-color: black;\n"
"                        \n"
"                         }"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        surname = new QLineEdit(groupBox);
        surname->setObjectName("surname");

        horizontalLayout->addWidget(surname);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        firstname = new QLineEdit(groupBox);
        firstname->setObjectName("firstname");

        horizontalLayout_2->addWidget(firstname);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        middlename = new QLineEdit(groupBox);
        middlename->setObjectName("middlename");

        horizontalLayout_3->addWidget(middlename);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        gender = new QComboBox(groupBox);
        gender->addItem(QString());
        gender->addItem(QString());
        gender->setObjectName("gender");

        horizontalLayout_5->addWidget(gender);


        horizontalLayout_8->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        idnum = new QLineEdit(groupBox);
        idnum->setObjectName("idnum");

        horizontalLayout_4->addWidget(idnum);


        horizontalLayout_8->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");

        horizontalLayout_7->addWidget(label_7);

        coursecode = new QLineEdit(groupBox);
        coursecode->setObjectName("coursecode");

        horizontalLayout_7->addWidget(coursecode);


        horizontalLayout_9->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        yerlvl = new QComboBox(groupBox);
        yerlvl->addItem(QString());
        yerlvl->addItem(QString());
        yerlvl->addItem(QString());
        yerlvl->addItem(QString());
        yerlvl->setObjectName("yerlvl");

        horizontalLayout_6->addWidget(yerlvl);


        horizontalLayout_9->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");

        horizontalLayout_10->addWidget(pushButton);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_10->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout_10);

        avaiC = new QPushButton(groupBox);
        avaiC->setObjectName("avaiC");

        verticalLayout_2->addWidget(avaiC);


        retranslateUi(Adding);

        QMetaObject::connectSlotsByName(Adding);
    } // setupUi

    void retranslateUi(QDialog *Adding)
    {
        Adding->setWindowTitle(QCoreApplication::translate("Adding", "Dialog", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("Adding", "Surname:", nullptr));
        label_2->setText(QCoreApplication::translate("Adding", "First Name:", nullptr));
        label_3->setText(QCoreApplication::translate("Adding", "Middle Name:", nullptr));
        label_5->setText(QCoreApplication::translate("Adding", "Gender:", nullptr));
        gender->setItemText(0, QCoreApplication::translate("Adding", "Male", nullptr));
        gender->setItemText(1, QCoreApplication::translate("Adding", "Female", nullptr));

        label_4->setText(QCoreApplication::translate("Adding", "ID #:", nullptr));
        idnum->setPlaceholderText(QCoreApplication::translate("Adding", "e.g. 2022-0001", nullptr));
        label_7->setText(QCoreApplication::translate("Adding", "Course:", nullptr));
        coursecode->setPlaceholderText(QCoreApplication::translate("Adding", "e.g. BSCS", nullptr));
        label_6->setText(QCoreApplication::translate("Adding", "Year Level:", nullptr));
        yerlvl->setItemText(0, QCoreApplication::translate("Adding", "1st Year", nullptr));
        yerlvl->setItemText(1, QCoreApplication::translate("Adding", "2nd Year", nullptr));
        yerlvl->setItemText(2, QCoreApplication::translate("Adding", "3rd Year", nullptr));
        yerlvl->setItemText(3, QCoreApplication::translate("Adding", "4th Year", nullptr));

        pushButton->setText(QCoreApplication::translate("Adding", "Add", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Adding", "Cancel", nullptr));
        avaiC->setText(QCoreApplication::translate("Adding", "Available Courses", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Adding: public Ui_Adding {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDING_H
