#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("传输系统总控监控by李海龙");
    ui->ptable->setHeaderText(QStringList()<<"配置项"<<"值");
    ui->ptable->setColWidth(0,400);
    connect(ui->ptree,SIGNAL(sigTransSystemNameAndStationName(pstring,pstring)),this,SLOT(slotClickTree(pstring,pstring)));
    connect(this,SIGNAL(sigShowStatusBar(QString,int)),ui->statusBar,SLOT(showMessage(QString,int)));
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(slotLineEditChanged(QString)));
    //开始就连接到服务器端//线程操作
    ptc=new ptcp("x5glk6u6td.54http.tech",40527);
    std::thread(&MainWindow::slotThreadConnect,this).detach();

    pbutDel=new QAction("删除",this);
    ui->ptable->addAction(pbutDel);
    connect(pbutDel,SIGNAL(triggered(bool)),this,SLOT(slotDelConf()));
    pbutSet=new QAction("修改",this);
    ui->ptable->addAction(pbutSet);
    connect(pbutSet,SIGNAL(triggered(bool)),this,SLOT(slotSetConf()));

    //每秒自动更新conf
    std::thread(&MainWindow::slotUpdateConf,this).detach();
    connect(this,SIGNAL(sigUpdateTable(plist<pliststring>,int)),
            ui->ptable,SLOT(slotUpdateTable(plist<pliststring>,int)));
}
void MainWindow::slotSetConf()
{
    QString key=ui->ptable->getItemText(ui->ptable->getRowNow(),"配置项");
    QString val=ui->ptable->getItemText(ui->ptable->getRowNow(),"值");
    pstring strIPStation=gallcsgl.getStation(this->strSystemNow,this->strStationNow).strip;
    QString input;
    if(qlib::inputbox(input,key))
    {
        pliststring lconf;
        lconf.append(key.toStdString());
        lconf.append(input.toStdString());
        lconf.append(strIPStation);
        if(this->ptc->sendx("setconf",lconf)<0)
        {
            sigShowStatusBar((pstring()<<"修改配置"<<key.toStdString()<<"失败").c_str());
        }
        if(ptc->recvx(1)<0)
        {
            sigShowStatusBar((pstring()<<"修改配置"<<key.toStdString()<<"失败").c_str());
        }
        bool bResAddConf=ptc->getClass<bool>();
        hlog(bResAddConf);
        if(bResAddConf)
        {
            sigShowStatusBar((pstring()<<"修改配置"<<key.toStdString()<<"成功").c_str());
//            slotClickTree(this->strSystemNow,this->strStationNow);
        }
        else
            sigShowStatusBar((pstring()<<"修改配置"<<key.toStdString()<<"失败").c_str());
    }
}
void MainWindow::slotDelConf()
{
    QString key=ui->ptable->getItemText(ui->ptable->getRowNow(),"配置项");
    if(qlib::confirmbox((pstring()<<"确定删除配置项"<<key.toStdString()<<"吗").c_str()))
    {
        pstring strIPStation=gallcsgl.getStation(this->strSystemNow,this->strStationNow).strip;
        pliststring ldel;
        ldel.append(key.toStdString());
        ldel.append(strIPStation);
        if(ptc->sendx("delconf",ldel)<0)
        {
            sigShowStatusBar("发送配置查询信息失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
            return;
        }
        if(ptc->recvx(1)<0)
        {
            sigShowStatusBar("接收配置信息数据失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
            return;
        }
        sigShowStatusBar("接收数据成功");
    }
}


void MainWindow::slotUpdateConf()
{
    while(1)
    {
        if(this->strStationNow==""||this->strSystemNow=="")
        {
            plib::sleep(2000);
            continue;
        }
        slotClickTree(this->strSystemNow,this->strStationNow);
        plib::sleep(2000);
    }
}
void MainWindow::slotClickTree(pstring strSystem, pstring strStation)
{
//    hlog(strSystem,strStation);
    this->strStationNow=strStation;
    this->strSystemNow=strSystem;
    pstring strIPStation=gallcsgl.getStation(strSystem,strStation).strip;
    //    hlog(gallcsgl.getStation(strSystem,strStation));
    //    hlog(gallcsgl.getSystemByName(strSystem));
    //    hlog(gallcsgl.mapSystem[strSystem]);
    //    hlog(gallcsgl.mapSystem);
    //    cout<<gallcsgl<<endl;
//    hlog(strIPStation);

    //向该ip发送查询配置信息
    if(ptc->sendx("getconf",strIPStation)<0)
    {
        sigShowStatusBar("发送配置查询信息失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
        return;
    }
    if(ptc->recvx(1)<0)
    {
        sigShowStatusBar("接收配置信息数据失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
        return;
    }
    sigShowStatusBar("接收数据成功");


    mapConfStation=ptc->getClass<pmap<pstring,pstring>>();


    plist<pliststring> lmres;
    for(int i=0;i<mapConfStation.size();i++)
    {
        pstring key=mapConfStation.getKey(i);
        pstring val=mapConfStation.getValue(i);
        if(key=="aaaa")
            hlog(key,val);
        lmres.append(pliststring()<<key<<val);
    }
    sigUpdateTable(lmres,0);

    //最后更新服务器信息
    ui->label_host->setText((strSystem+" "+strStation+" "+strIPStation).c_str());
}
MainWindow::~MainWindow()
{
    ptc->close();
    delete ptc;
    delete pbutDel;
    delete pbutSet;
    delete ui;
}





void MainWindow::slotLineEditChanged(QString str)
{
    hlog(str);
    //查找table里面key中包含这字符串不,包含就显示,不包含的去掉

    pmap<pstring,pstring> mapres;
    for(int i=0;i<mapConfStation.size();i++)
    {
        if(mapConfStation.getKey(i).contain(str.toStdString()))
        {
            mapres.add(mapConfStation.getKey(i),mapConfStation.getValue(i));
        }
    }
    hlog(mapres.size());
    ui->ptable->setRowCount(mapres.size());
    for(int i=0;i<mapres.size();i++)
    {
        ui->ptable->setItemText(i,0,mapres.getKey(i).c_str());
        ui->ptable->setItemText(i,1,mapres.getValue(i).c_str());
    }
}

void MainWindow::slotThreadConnect()
{
    if(ptc->connect()<0)
    {
        sigShowStatusBar("连接服务器失败!重连中......");
        ptc->reconnect();
    }
    sigShowStatusBar("连接服务器成功");
}



void MainWindow::on_pushButtonAddConf_clicked()
{
    if(ui->label_host->text()=="")
    {
        qlib::messageBox("请先双击树节点选择一个接收站");
        return;
    }
    pstring strhost=ui->label_host->text().toStdString();
    hlog(strhost);
    pstring strIp=strhost.split(" ").getDataEnd();
    hlog(strIp);
    QString strInput;
    if(qlib::inputbox(strInput,"配置项(key=value)"))
    {
        hlog(strInput);

        pliststring lsplit=pstring(strInput.toStdString()).split("=");
        if(lsplit.size()!=2)
        {
            qlib::messageBox("请按格式输入配置项参数(key=value)");
            return;
        }
        //        pstring key=lsplit[0];
        //        pstring val=lsplit[1];
        //        hlog(key,val);
        //后边加上ip
        lsplit.append(strIp);
        if(this->ptc->sendx("addconf",lsplit)<0)
        {
            sigShowStatusBar((pstring()<<"增加配置"<<strInput.toStdString()<<"失败").c_str());
        }
        if(ptc->recvx(1)<0)
        {
            sigShowStatusBar((pstring()<<"增加配置"<<strInput.toStdString()<<"失败").c_str());
        }
        bool bResAddConf=ptc->getClass<bool>();
        hlog(bResAddConf);
        if(bResAddConf)
        {
            sigShowStatusBar((pstring()<<"增加配置"<<strInput.toStdString()<<"成功").c_str());
//            slotClickTree(this->strSystemNow,this->strStationNow);
        }
        else
            sigShowStatusBar((pstring()<<"增加配置"<<strInput.toStdString()<<"失败").c_str());
    }
}
