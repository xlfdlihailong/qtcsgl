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
    QFont font;
    pmap<pstring,ptcp*> mapHostTcp;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    pmap<pstring,pstring> mapconf;//配置项的详细解释
    ptcp* ptcpControlSC=NULL;//专门控制总控重启停止开始查询的ptcp,因为重复会导致数据失败
    QString strTabNow="";
    CSGLAll gallcsgl;
    pstring strSystemNow="";
    pstring strStationNow="";
    QAction* pbutDel=NULL;
    QAction* pbutSet=NULL;
    QAction* pbutRestartSC=NULL;
    QString strConditionConf="";
    QAction* pbutStartSC=NULL;
    QAction* pbutStopSC=NULL;
    QAction* pbutSSH=NULL;
signals:
    void sigMessageBox(QString info);
    void sigShowLabel(QString info);
    void sigShowLineEdit(QString info);
    void sigShowStatusBar(QString info,int time=0);
    void sigUpdateTable(plist<pliststring>,int);
    void sigUpdateTableTask(plist<pliststring>, int);
    void sigUpdateTableJK(plist<pliststring>,int);
private slots:
    void slotSSH();
    void slotStopSC();
    void slotThreadStopSC();
    void slotStartSC();
    void slotThreadStartSC();

    void slotThreadRestartSC();
    void slotMessageBox(QString info);
    void slotRestartSC();
    void slotThreadGetRootDiskUsage();
    void slotGetConf();
    void slotGetTask();
    void slotDelConf();
    void slotSetConf();
    void slotUpdateConf();

    void slotClickTree(pstring strSystem,pstring strStation);
    void on_pushButtonAddConf_clicked();

    void on_ptab_currentChanged(int index);

    void on_lineEditQuery_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    pstring host="x5glk6u6td.54http.tech";
    int port=40527;
};

#endif // MAINWINDOW_H
