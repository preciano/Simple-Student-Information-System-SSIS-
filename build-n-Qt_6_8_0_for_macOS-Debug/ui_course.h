/********************************************************************************
** Form generated from reading UI file 'course.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSE_H
#define UI_COURSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Course
{
public:
    QGroupBox *groupBox;
    QPushButton *addC;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *courseC;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *courseN;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QTableView *courseT;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *showC;
    QPushButton *deleteC;

    void setupUi(QDialog *Course)
    {
        if (Course->objectName().isEmpty())
            Course->setObjectName("Course");
        Course->resize(640, 548);
        groupBox = new QGroupBox(Course);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 621, 161));
        addC = new QPushButton(groupBox);
        addC->setObjectName("addC");
        addC->setGeometry(QRect(210, 120, 191, 32));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(7, 50, 601, 58));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        courseC = new QLineEdit(layoutWidget);
        courseC->setObjectName("courseC");

        horizontalLayout_2->addWidget(courseC);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        courseN = new QLineEdit(layoutWidget);
        courseN->setObjectName("courseN");

        horizontalLayout->addWidget(courseN);


        verticalLayout->addLayout(horizontalLayout);

        layoutWidget1 = new QWidget(Course);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 170, 621, 371));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        courseT = new QTableView(layoutWidget1);
        courseT->setObjectName("courseT");

        verticalLayout_2->addWidget(courseT);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        showC = new QPushButton(layoutWidget1);
        showC->setObjectName("showC");

        horizontalLayout_3->addWidget(showC);

        deleteC = new QPushButton(layoutWidget1);
        deleteC->setObjectName("deleteC");

        horizontalLayout_3->addWidget(deleteC);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(Course);

        QMetaObject::connectSlotsByName(Course);
    } // setupUi

    void retranslateUi(QDialog *Course)
    {
        Course->setWindowTitle(QCoreApplication::translate("Course", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Course", "Add Course?", nullptr));
        addC->setText(QCoreApplication::translate("Course", "Add", nullptr));
        label->setText(QCoreApplication::translate("Course", "Course Code:", nullptr));
        label_2->setText(QCoreApplication::translate("Course", "Course Name:", nullptr));
        showC->setText(QCoreApplication::translate("Course", "Show", nullptr));
        deleteC->setText(QCoreApplication::translate("Course", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Course: public Ui_Course {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSE_H
