#-------------------------------------------------
#
# Project created by QtCreator 2020-09-04T14:38:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtcsgl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qlib/qlib.cpp \
    qlib/plib/plib.cpp \
    xTableWidget.cpp \
    xtreewidget.cpp \
    qtreewidgetexx.cpp

HEADERS  += mainwindow.h \
    qlib/qlib.h \
    qlib/plib/plib.h \
    xTableWidget.h \
    xtreewidget.h \
    qtreewidgetexx.h

FORMS    += mainwindow.ui \
    xTableWidget.ui \
    xtreewidget.ui \
    qtreewidgetexx.ui

RESOURCES += \
    xlfd.qrc

DISTFILES += \
    xlfd.conf
