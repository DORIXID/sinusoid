/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widgetMain;
    QChartView *widgetPlot;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(745, 588);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        widgetMain = new QWidget(centralwidget);
        widgetMain->setObjectName("widgetMain");
        widgetMain->setGeometry(QRect(10, 10, 721, 521));
        widgetPlot = new QChartView(widgetMain);
        widgetPlot->setObjectName("widgetPlot");
        widgetPlot->setGeometry(QRect(10, 0, 701, 481));
        widgetPlot->setMouseTracking(true);
        pushButton = new QPushButton(widgetMain);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 490, 141, 24));
        pushButton->setCheckable(false);
        label = new QLabel(widgetMain);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 490, 103, 16));
        label_2 = new QLabel(widgetMain);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(280, 490, 161, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 745, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "disco", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\320\260 \321\202\320\276\321\207\320\272\320\270:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\275\320\265\320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
