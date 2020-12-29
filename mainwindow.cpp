#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    font.setFamily(QStringLiteral("DejaVu Sans Mono"));
    font.setPointSize(12);
    ui->label_host->setFont(font);
    ui->label_host_2->setFont(font);
    ui->lineEditQuery->setFont(font);
    ui->pushButtonAddConf->setFont(font);
    setWindowState(Qt::WindowMaximized);
    this->setWindowTitle("传输系统总控监控by李海龙");
    mapconf.add("IP_LOCAL","本机地址");
    mapconf.add("AGENT_NUM","传输代理服务器个数");
    mapconf.add("AGENT_IP1","传输代理服务器地址1");
    mapconf.add("AGENT_IP2","传输代理服务器地址2");
    mapconf.add("AGENT_IP3","传输代理服务器地址3");
    mapconf.add("AGENT_IP4","传输代理服务器地址4");
    mapconf.add("AGENT_IP5","传输代理服务器地址5");
    mapconf.add("AGENT_IP6","传输代理服务器地址6");
    mapconf.add("AGENT_IP7","传输代理服务器地址7");
    mapconf.add("AGENT_IP8","传输代理服务器地址8");
    mapconf.add("AGENT_IP9","传输代理服务器地址9");
    mapconf.add("SYSTEM_TONGYI","本系统与哪个系统是统一带宽分配,这个决定了本系统和哪个系统要一起分配带宽,如果不需要统一带宽分配,则不要配这个参数就可以了");
    mapconf.add("SYSTEM","本站属于哪个系统");
    mapconf.add("NORMAL_PERCENT","带宽分配算法中的加权平均算法中的中优先级所占中低带宽的比例,加权平均算法仅在中优先级任务中有非实时且有低优先级任务的情况下才会触发");
    mapconf.add("FILE_DEADLINE","传输数据文件保存期限,单位为天");
    mapconf.add("FAST_MODE","传输模式,0为非快速传输,1为快速传输,非快速传输指非实时任务总控要等到找到OK文件才给传输代理发送任务,而快速传输总控只要找到DESC文件就会给传输代理发送任务");
    mapconf.add("FILE_SAVE_PATH","实时任务数据存储路径");
    mapconf.add("WORK_PATH","非实时任务数据存储路径");
    mapconf.add("DISK_USAGE","传输数据目录所在磁盘最高占用率,当磁盘使用超过该值时,总控会自动删除过期实时和非实时数据以释放空间保证磁盘充足");
    mapconf.add("SCSERVICE_UDP_PORT","总控服务与传输代理的UDP单播通信端口");


    ui->ptable->setHeaderText(QStringList()<<"配置项"<<"值"<<"描述");
    ui->ptable->setColWidth(0,400);
    ui->ptable->setColWidth(1,300);
    connect(ui->ptree,SIGNAL(sigTransSystemNameAndStationName(pstring,pstring)),this,SLOT(slotClickTree(pstring,pstring)));
    connect(this,SIGNAL(sigShowStatusBar(QString,int)),ui->statusBar,SLOT(showMessage(QString,int)));


    ptcpControlSC=new ptcp(host,port);
    ptcpControlSC->connectx();
    for(int i=0;i<gallcsgl.size();i++)
    {
        CSGLSystem sys=gallcsgl.getSystemByIndex(i);
        for(int j=0;j<sys.size();j++)
        {
            CSGLStation stationj=sys.getStationByIndex(j);
            ptcp* pj=new ptcp(host,port);
            mapHostTcp.add(stationj.strip,pj);
            pj->connectx();
        }
    }
    hlog(mapHostTcp);


    pbutDel=new QAction("删除",this);
    ui->ptable->addAction(pbutDel);
    connect(pbutDel,SIGNAL(triggered(bool)),this,SLOT(slotDelConf()));

    pbutSet=new QAction("修改",this);
    ui->ptable->addAction(pbutSet);
    connect(pbutSet,SIGNAL(triggered(bool)),this,SLOT(slotSetConf()));

    pbutRestartSC=new QAction("重启总控",this);
    ui->ptablejk->addAction(pbutRestartSC);
    connect(pbutRestartSC,SIGNAL(triggered(bool)),this,SLOT(slotRestartSC()));

    pbutStartSC=new QAction("启动总控",this);
    ui->ptablejk->addAction(pbutStartSC);
    connect(pbutStartSC,SIGNAL(triggered(bool)),this,SLOT(slotStartSC()));

    pbutStopSC=new QAction("停止总控",this);
    ui->ptablejk->addAction(pbutStopSC);
    connect(pbutStopSC,SIGNAL(triggered(bool)),this,SLOT(slotStopSC()));

    pbutSSH=new QAction("SSH远程",this);
    ui->ptablejk->addAction(pbutSSH);
    connect(pbutSSH,SIGNAL(triggered(bool)),this,SLOT(slotSSH()));


    connect(this,SIGNAL(sigShowLabel(QString)),ui->label_host,SLOT(setText(QString)));
    //每秒自动更新conf
    std::thread(&MainWindow::slotUpdateConf,this).detach();
    connect(this,SIGNAL(sigUpdateTable(plist<pliststring>,int)),
            ui->ptable,SLOT(slotUpdateTable(plist<pliststring>,int)));

    connect(this,SIGNAL(sigUpdateTableTask(plist<pliststring>,int)),
            ui->ptableTask,SLOT(slotUpdateTable(plist<pliststring>,int)));
    connect(this,SIGNAL(sigUpdateTableJK(plist<pliststring>,int)),
            ui->ptablejk,SLOT(slotUpdateTable(plist<pliststring>,int)));

    ui->ptableTask->setHeaderText(
                QStringList()<<"任务流水号"<<"作业任务编号"<<"卫星名称"<<"数据源地址"<<"传输级别"<<"作业方式"
                <<"执行状态"<<"预计开始时间");
    ui->ptableTask->setColWidth("任务流水号",250);
    ui->ptableTask->setColWidth("作业任务编号",200);
    ui->ptableTask->setColWidth("卫星名称",150);

    pbutCopyTaskSerialNum=new QAction("复制任务流水号",this);
    ui->ptableTask->addAction(pbutCopyTaskSerialNum);
    connect(pbutCopyTaskSerialNum,SIGNAL(triggered(bool)),this,SLOT(slotCopyTaskSerialNum()));
    pbutCopyJobTaskID=new QAction("复制作业任务编号",this);
    ui->ptableTask->addAction(pbutCopyJobTaskID);
    connect(pbutCopyJobTaskID,SIGNAL(triggered(bool)),this,SLOT(slotCopyJobTaskID()));


    ui->ptablejk->setHeaderText(QStringList()<<"服务器信息"<<"根目录占用"<<"总控状态"<<"总控cpu占用"<<"总控内存占用");
    ui->ptablejk->setColWidth("服务器信息",300);
    ui->ptablejk->setColWidth("总控cpu占用",150);
    std::thread (&MainWindow::slotThreadGetRootDiskUsage,this).detach();
    connect(this,SIGNAL(sigMessageBox(QString)),this,SLOT(slotMessageBox(QString)));

}
void MainWindow::slotSetConf()
{
    QString key=ui->ptable->getItemText(ui->ptable->getRowNow(),"配置项");
    QString val=ui->ptable->getItemText(ui->ptable->getRowNow(),"值");
    pstring strIPStation=gallcsgl.getStation(this->strSystemNow,this->strStationNow).strip;
    ptcp* ptc=this->mapHostTcp[strIPStation];
    QString input;
    if(qlib::inputbox(input,key))
    {
        pliststring lconf;
        lconf.append(key.toStdString());
        lconf.append(input.toStdString());
        lconf.append(strIPStation);
        if(ptc->sendx("setconf",lconf)<0)
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
        ptcp* ptc=this->mapHostTcp[strIPStation];
        pliststring ldel;
        ldel.append(key.toStdString());
        ldel.append(strIPStation);
        if(ptc->sendx("delconf",ldel)<0)
        {
            sigShowStatusBar("发送配置查询信息失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
            return;
        }
        if(ptc->recvx(3)<0)
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
            plib::sleep(500);
            continue;
        }
        //用同一个tcp
        if(strTabNow=="配置文件")
            slotGetConf();
        if(strTabNow=="任务队列")
            slotGetTask();

        plib::sleep(500);
    }
}
void MainWindow::slotClickTree(pstring strSystem, pstring strStation)
{
    this->strStationNow=strStation;
    this->strSystemNow=strSystem;
    this->strTabNow=ui->ptab->tabText(ui->ptab->currentIndex());
}
MainWindow::~MainWindow()
{

    delete pbutDel;
    delete pbutSet;
    delete ui;
}

void MainWindow::slotCopyTaskSerialNum()
{
    QString strTaskSerialNum=ui->ptableTask->getItemText(ui->ptableTask->getRowNow(),"任务流水号");
    hlog(strTaskSerialNum);
    qlib::setCopyInClipboard(strTaskSerialNum);
}

void MainWindow::slotCopyJobTaskID()
{
    QString strJobID=ui->ptableTask->getItemText(ui->ptableTask->getRowNow(),"作业任务编号");
    hlog(strJobID);
    qlib::setCopyInClipboard(strJobID);
}

void MainWindow::slotSSH()
{
    pstring strinfo=ui->ptablejk->getItemText(ui->ptablejk->getRowNow(),"服务器信息").toStdString();
    hlog(strinfo);
    pstring strIPStation=strinfo.split(" ").getDataEnd();
    hlog(strIPStation);
    hlog(plib::pwd());
    //    plib::sshThread(strIPStation);
    plib::sshzkyThread(strIPStation);
}

void MainWindow::slotStopSC()
{
    std::thread(&MainWindow::slotThreadStopSC,this).detach();
}

void MainWindow::slotThreadStopSC()
{
    pstring strinfo=ui->ptablejk->getItemText(ui->ptablejk->getRowNow(),"服务器信息").toStdString();
    hlog(strinfo);
    pstring strIPStation=strinfo.split(" ").getDataEnd();
    hlog(strIPStation);

    //    //向该ip发送查询配置信息
    //    if(ptcpControlSC->sendx("stopSC",strIPStation)<0)
    //    {
    //        sigShowStatusBar("发送停止总控信息失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
    //        return;
    //    }
    //    if(ptcpControlSC->recvx(3)<0)
    //    {
    //        sigShowStatusBar("接收停止总控数据失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
    //        return;
    //    }
    //    sigShowStatusBar("接收停止总控结果成功");
    //    bool bres=ptcpControlSC->getClass<bool>();
    bool bres=plib::xk(strIPStation);
    hlog(bres);
    if(bres)
        sigMessageBox((pstring()<<"停止"<<strinfo<<"上的总控成功").c_str());
    else
        sigMessageBox((pstring()<<"停止"<<strinfo<<"上的总控失败").c_str());
}

void MainWindow::slotStartSC()
{
    std::thread(&MainWindow::slotThreadStartSC,this).detach();
}

void MainWindow::slotThreadStartSC()
{
    pstring strinfo=ui->ptablejk->getItemText(ui->ptablejk->getRowNow(),"服务器信息").toStdString();
    hlog(strinfo);
    pstring strIPStation=strinfo.split(" ").getDataEnd();
    hlog(strIPStation);

    //    //向该ip发送查询配置信息
    //    if(ptcpControlSC->sendx("startSC",strIPStation)<0)
    //    {
    //        sigShowStatusBar("发送启动总控信息失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
    //        return;
    //    }
    //    if(ptcpControlSC->recvx(3)<0)
    //    {
    //        sigShowStatusBar("接收启动总控数据失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
    //        return;
    //    }
    //    sigShowStatusBar("接收启动总控结果成功");
    //    bool bres=ptcpControlSC->getClass<bool>();
    bool bres=plib::xs(strIPStation);
    hlog(bres);
    if(bres)
        sigMessageBox((pstring()<<"启动"<<strinfo<<"上的总控成功").c_str());
    else
        sigMessageBox((pstring()<<"启动"<<strinfo<<"上的总控失败").c_str());
}


void MainWindow::slotRestartSC()
{
    std::thread(&MainWindow::slotThreadRestartSC,this).detach();
}

void MainWindow::slotThreadRestartSC()
{
    pstring strinfo=ui->ptablejk->getItemText(ui->ptablejk->getRowNow(),"服务器信息").toStdString();
    hlog(strinfo);
    pstring strIPStation=strinfo.split(" ").getDataEnd();
    hlog(strIPStation);

    //    //向该ip发送查询配置信息
    //    if(ptcpControlSC->sendx("restartSC",strIPStation)<0)
    //    {
    //        sigShowStatusBar("发送重启总控信息失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
    //        return;
    //    }
    //    if(ptcpControlSC->recvx(3)<0)
    //    {
    //        sigShowStatusBar("接收重启总控数据失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
    //        return;
    //    }
    //    sigShowStatusBar("接收重启总控结果成功");
    //    bool bres=ptcpControlSC->getClass<bool>();
    bool bres=plib::xr(strIPStation);
    hlog(bres);
    if(bres)
        sigMessageBox((pstring()<<"重启"<<strinfo<<"上的总控成功").c_str());
    else
        sigMessageBox((pstring()<<"重启"<<strinfo<<"上的总控失败").c_str());
}

void MainWindow::slotMessageBox(QString info)
{
    qlib::messageBox(info);
}



void MainWindow::slotThreadGetRootDiskUsage()
{
    ptcp tcp(host,port);
    tcp.connectx();
    while(1)
    {
        //向该ip发送查询配置信息
        if(tcp.sendx("getDiskUsage")<0)
        {
            sigShowStatusBar("发送根目录占用查询信息失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
            return;
        }
        if(tcp.recvx(3)<0)
        {
            sigShowStatusBar("接收根目录占用数据失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
            return;
        }
//        sigShowStatusBar("接收根目录占用数据成功");


        pmap<pstring,pliststring>  mapHostAndDiskUsage=tcp.getClass<pmap<pstring,pliststring>>();
        //    hlog(mapConfStation);

        plist<pliststring> lmresDiskUsage;

        //此时还要根据输入的条件进行筛选
        for(int i=0;i<mapHostAndDiskUsage.size();i++)
        {
            pstring key=mapHostAndDiskUsage.getKey(i);
            pstring keyres=gallcsgl.getSystemAndStationByHost(key).join("  ")+"  "+key;
            pliststring val=mapHostAndDiskUsage.getValue(i);

            //            hlog(val);
            pliststring lres;
            lres.append(keyres);
            for(int j=0;j<val.size();j++)
                lres.append(val[j]);

            lmresDiskUsage.append(lres);
        }

        sigUpdateTableJK(lmresDiskUsage,0);
        plib::sleep(1000);
    }
}

void MainWindow::slotGetConf()
{
    pstring strIPStation=gallcsgl.getStation(strSystemNow,strStationNow).strip;
    ptcp* ptc=this->mapHostTcp[strIPStation];

    //向该ip发送查询配置信息
    if(ptc->sendx("getconf",strIPStation)<0)
    {
        sigShowStatusBar("发送配置查询信息失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
        return;
    }
    if(ptc->recvx(3)<0)
    {
        sigShowStatusBar("接收配置信息数据失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
        return;
    }
//    sigShowStatusBar("接收配置信息数据成功");


    pmap<pstring,pstring>  mapConfStation=ptc->getClass<pmap<pstring,pstring>>();
    //    hlog(mapConfStation);

    plist<pliststring> lmresConf;

    //此时还要根据输入的条件进行筛选
    for(int i=0;i<mapConfStation.size();i++)
    {
        pstring key=mapConfStation.getKey(i);
        pstring val=mapConfStation.getValue(i);
        pstring info=this->mapconf[key];

        //根据key包含查询,key先转小写,条件也转小写
        pstring strkeyLower=key.toLower();
        pstring strInfoLower=info.toLower();
        //        hlog(strkeyLower);
        pstring strCondLower=pstring(this->strConditionConf.toStdString()).toLower();
        //        hlog(strCondLower);
        if(strCondLower!="")
        {
            if(strkeyLower.contain(strCondLower)||strInfoLower.contain(strCondLower))
                lmresConf.append(pliststring()<<key<<val<<info);
        }
        else
            lmresConf.append(pliststring()<<key<<val<<info);
    }

    sigUpdateTable(lmresConf,0);

    //最后更新服务器信息
    sigShowLabel((strSystemNow+" "+strStationNow+" "+strIPStation).c_str());
}

void MainWindow::on_lineEditQuery_textChanged(const QString &arg1)
{
    this->strConditionConf=arg1;
}

void MainWindow::slotGetTask()
{
    pstring strIPStation=gallcsgl.getStation(strSystemNow,strStationNow).strip;
    ptcp* ptc=this->mapHostTcp[strIPStation];

    //向该ip发送查询配置信息
    if(ptc->sendx("gettask",strIPStation)<0)
    {
        sigShowStatusBar("发送任务查询信息失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
        return;
    }
    if(ptc->recvx(3)<0)
    {
        sigShowStatusBar("接收任务信息数据失败,与服务器连接断开,请重试 "+qlib::toString(plib::getTimeNow()));
        return;
    }
//    sigShowStatusBar("接收任务数据成功");


    //   pmap<pstring,pstring>  mapConfStation=ptc->getClass<pmap<pstring,pstring>>();
    //    hlog(mapConfStation);
    plist<TASK_STATUS_STRUCT> lres=ptc->getClass<plist<TASK_STATUS_STRUCT>>();
    hlog(strIPStation,lres.size());
    //    hlog(lres[0].arrchTaskSerialNumber);
    //    "卫星名称"<<"数据源地址"<<"传输级别"<<"作业方式"
    //                    <<"预计开始时间
    plist<pliststring> lmres;
    for(int i=0;i<lres.size();i++)
    {
        pstring stryxj="低";
        pstring strState="未开始";
        TASK_STATUS_STRUCT task=lres[i];
        if(task.shTaskPriority==1)
            stryxj="中";
        if(task.shTaskPriority==2)
            stryxj="高";
        if(task.shInexecutingState==5)
            strState="执行中";
        if(task.shInexecutingState==9)
            strState="完成";
        if(task.shInexecutingState==10)
            strState="失败";
        lmres.append(pliststring()<<
                     task.arrchTaskSerialNumber<<task.arrchJobTaskID<<task.arrchSatelliteName
                     <<task.arrchDataSource<<stryxj<<task.arrchTaskMode
                     <<strState<<task.arrchForeseeStartTime);
    }

    sigUpdateTableTask(lmres,0);

    //    //最后更新服务器信息
    //    sigShowLabel((strSystemNow+" "+strStationNow+" "+strIPStation).c_str());
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
    ptcp* ptc=this->mapHostTcp[strIp];
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
        if(ptc->sendx("addconf",lsplit)<0)
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

void MainWindow::on_ptab_currentChanged(int index)
{
    mut.lock();
    this->strTabNow=ui->ptab->tabText(index);
    mut.unlock();
}

