/********************************************************************************
** Form generated from reading UI file 'test001.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST001_H
#define UI_TEST001_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>

QT_BEGIN_NAMESPACE

class Ui_test001
{
public:
    QLabel *countdownLabel;
    QPushButton *pushButton1;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *test001)
    {
        if (test001->objectName().isEmpty())
            test001->setObjectName("test001");
        test001->resize(177, 142);
        countdownLabel = new QLabel(test001);
        countdownLabel->setObjectName("countdownLabel");
        countdownLabel->setTextFormat(Qt::AutoText);
        pushButton1 = new QPushButton(countdownLabel);
        pushButton1->setObjectName("pushButton1");
        pushButton1->setGeometry(QRect(10, 60, 75, 24));
        test001->setCentralWidget(countdownLabel);
        menubar = new QMenuBar(test001);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 177, 21));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        test001->setMenuBar(menubar);
        statusbar = new QStatusBar(test001);
        statusbar->setObjectName("statusbar");
        test001->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(test001);

        QMetaObject::connectSlotsByName(test001);
    } // setupUi

    void retranslateUi(QMainWindow *test001)
    {
        test001->setWindowTitle(QCoreApplication::translate("test001", "test001", nullptr));
        countdownLabel->setText(QCoreApplication::translate("test001", "\345\200\222\350\256\241\346\227\266\357\274\232", nullptr));
        pushButton1->setText(QCoreApplication::translate("test001", "\345\220\257\345\212\250\345\200\222\350\256\241\346\227\266", nullptr));
        menu->setTitle(QCoreApplication::translate("test001", "doudou", nullptr));
    } // retranslateUi

};

namespace Ui {
    class test001: public Ui_test001 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST001_H
