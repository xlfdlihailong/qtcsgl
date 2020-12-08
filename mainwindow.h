#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qlib/qlib.h"
#include "xTableWidget.h"
#include "xtreewidget.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ptcp* ptc=NULL;
    CSGLAll gallcsgl;
    pstring strSystemNow="";
    pstring strStationNow="";
    QAction* pbutDel=NULL;
    QAction* pbutSet=NULL;
signals:
    void sigShowStatusBar(QString info,int time=0);
    void sigUpdateTable(plist<pliststring>,int);
private slots:
    void slotDelConf();
    void slotSetConf();
    void slotUpdateConf();
    void slotLineEditChanged(QString str);
    void slotThreadConnect();
    void slotClickTree(pstring strSystem,pstring strStation);
    void on_pushButtonAddConf_clicked();

private:
    Ui::MainWindow *ui;
    pmap<pstring,pstring> mapConfStation;
};

#endif // MAINWINDOW_H
