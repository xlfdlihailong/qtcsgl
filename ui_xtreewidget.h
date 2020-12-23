/********************************************************************************
** Form generated from reading UI file 'xtreewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XTREEWIDGET_H
#define UI_XTREEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qtreewidgetexx.h"

QT_BEGIN_NAMESPACE

class Ui_xTreeWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidgetExx *treeWidget;

    void setupUi(QWidget *xTreeWidget)
    {
        if (xTreeWidget->objectName().isEmpty())
            xTreeWidget->setObjectName(QString::fromUtf8("xTreeWidget"));
        xTreeWidget->resize(751, 640);
        verticalLayout = new QVBoxLayout(xTreeWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidgetExx(xTreeWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        verticalLayout->addWidget(treeWidget);


        retranslateUi(xTreeWidget);

        QMetaObject::connectSlotsByName(xTreeWidget);
    } // setupUi

    void retranslateUi(QWidget *xTreeWidget)
    {
        xTreeWidget->setWindowTitle(QCoreApplication::translate("xTreeWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class xTreeWidget: public Ui_xTreeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XTREEWIDGET_H
