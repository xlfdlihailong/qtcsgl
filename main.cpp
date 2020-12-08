#include "mainwindow.h"
#include <QApplication>
#include "qlib/qlib.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qlib::initLog();
    qlib::loadQss(&a);
    MainWindow w;
    w.show();

    return a.exec();
}
