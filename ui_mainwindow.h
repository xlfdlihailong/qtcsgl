/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
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
    QTabWidget *ptab;
    QWidget *tabconf;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_host;
    QLineEdit *lineEditQuery;
    QPushButton *pushButtonAddConf;
    xTableWidget *ptable;
    QWidget *tabTask;
    QHBoxLayout *horizontalLayout_5;
    xTableWidget *ptableTask;
    QWidget *tabjk;
    QHBoxLayout *horizontalLayout_6;
    xTableWidget *ptablejk;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1582, 976);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ptree = new xTreeWidget(centralWidget);
        ptree->setObjectName(QString::fromUtf8("ptree"));
        ptree->setMinimumSize(QSize(150, 55));
        ptree->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(ptree);

        ptab = new QTabWidget(centralWidget);
        ptab->setObjectName(QString::fromUtf8("ptab"));
        tabconf = new QWidget();
        tabconf->setObjectName(QString::fromUtf8("tabconf"));
        horizontalLayout_4 = new QHBoxLayout(tabconf);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_host = new QLabel(tabconf);
        label_host->setObjectName(QString::fromUtf8("label_host"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_host->sizePolicy().hasHeightForWidth());
        label_host->setSizePolicy(sizePolicy);
        label_host->setMinimumSize(QSize(0, 0));

        horizontalLayout_3->addWidget(label_host);

        lineEditQuery = new QLineEdit(tabconf);
        lineEditQuery->setObjectName(QString::fromUtf8("lineEditQuery"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(4);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditQuery->sizePolicy().hasHeightForWidth());
        lineEditQuery->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(lineEditQuery);

        pushButtonAddConf = new QPushButton(tabconf);
        pushButtonAddConf->setObjectName(QString::fromUtf8("pushButtonAddConf"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButtonAddConf->sizePolicy().hasHeightForWidth());
        pushButtonAddConf->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(pushButtonAddConf);


        verticalLayout->addLayout(horizontalLayout_3);

        ptable = new xTableWidget(tabconf);
        ptable->setObjectName(QString::fromUtf8("ptable"));
        ptable->setMinimumSize(QSize(55, 55));

        verticalLayout->addWidget(ptable);


        horizontalLayout_4->addLayout(verticalLayout);

        ptab->addTab(tabconf, QString());
        tabTask = new QWidget();
        tabTask->setObjectName(QString::fromUtf8("tabTask"));
        horizontalLayout_5 = new QHBoxLayout(tabTask);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        ptableTask = new xTableWidget(tabTask);
        ptableTask->setObjectName(QString::fromUtf8("ptableTask"));

        horizontalLayout_5->addWidget(ptableTask);

        ptab->addTab(tabTask, QString());
        tabjk = new QWidget();
        tabjk->setObjectName(QString::fromUtf8("tabjk"));
        horizontalLayout_6 = new QHBoxLayout(tabjk);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        ptablejk = new xTableWidget(tabjk);
        ptablejk->setObjectName(QString::fromUtf8("ptablejk"));

        horizontalLayout_6->addWidget(ptablejk);

        ptab->addTab(tabjk, QString());

        horizontalLayout->addWidget(ptab);


        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1582, 22));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        ptab->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_host->setText(QString());
        pushButtonAddConf->setText(QCoreApplication::translate("MainWindow", "\345\242\236\345\212\240\351\205\215\347\275\256", nullptr));
        ptab->setTabText(ptab->indexOf(tabconf), QCoreApplication::translate("MainWindow", "\351\205\215\347\275\256\346\226\207\344\273\266", nullptr));
        ptab->setTabText(ptab->indexOf(tabTask), QCoreApplication::translate("MainWindow", "\344\273\273\345\212\241\351\230\237\345\210\227", nullptr));
        ptab->setTabText(ptab->indexOf(tabjk), QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\347\233\221\346\216\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
