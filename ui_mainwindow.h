/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "xtablewidget.h"
#include "xtreewidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    xTreeWidget *ptree;
    QTabWidget *tabWidget;
    QWidget *tabconf;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_host;
    QLineEdit *lineEdit;
    QPushButton *pushButtonAddConf;
    xTableWidget *ptable;
    QWidget *tabTask;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1342, 976);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        centralWidget->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ptree = new xTreeWidget(centralWidget);
        ptree->setObjectName(QStringLiteral("ptree"));
        ptree->setMinimumSize(QSize(150, 55));
        ptree->setMaximumSize(QSize(150, 16777215));
        ptree->setFont(font);

        horizontalLayout->addWidget(ptree);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        tabWidget->setFont(font1);
        tabconf = new QWidget();
        tabconf->setObjectName(QStringLiteral("tabconf"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        tabconf->setFont(font2);
        horizontalLayout_4 = new QHBoxLayout(tabconf);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_host = new QLabel(tabconf);
        label_host->setObjectName(QStringLiteral("label_host"));
        label_host->setMinimumSize(QSize(0, 0));
        QFont font3;
        font3.setPointSize(14);
        label_host->setFont(font3);

        horizontalLayout_3->addWidget(label_host);

        lineEdit = new QLineEdit(tabconf);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);

        pushButtonAddConf = new QPushButton(tabconf);
        pushButtonAddConf->setObjectName(QStringLiteral("pushButtonAddConf"));
        QFont font4;
        font4.setPointSize(13);
        font4.setBold(true);
        font4.setWeight(75);
        pushButtonAddConf->setFont(font4);

        horizontalLayout_3->addWidget(pushButtonAddConf);


        verticalLayout->addLayout(horizontalLayout_3);

        ptable = new xTableWidget(tabconf);
        ptable->setObjectName(QStringLiteral("ptable"));
        ptable->setMinimumSize(QSize(55, 55));

        verticalLayout->addWidget(ptable);


        horizontalLayout_4->addLayout(verticalLayout);

        tabWidget->addTab(tabconf, QString());
        tabTask = new QWidget();
        tabTask->setObjectName(QStringLiteral("tabTask"));
        tabTask->setFont(font2);
        tabWidget->addTab(tabTask, QString());

        horizontalLayout->addWidget(tabWidget);


        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1342, 23));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_host->setText(QString());
        pushButtonAddConf->setText(QApplication::translate("MainWindow", "\345\242\236\345\212\240\351\205\215\347\275\256", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabconf), QApplication::translate("MainWindow", "\351\205\215\347\275\256\346\226\207\344\273\266", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabTask), QApplication::translate("MainWindow", "\344\273\273\345\212\241\351\230\237\345\210\227", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
