#include "mainwindow.h"
#include "ui_mainwindow.h"


using namespace std;

list<LpmsDevice *> MainWindow::lpmsList;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->textbrowser->setText("Ready to start.");
    //Gets a LpmsSensorManager instance0
    manager = LpmsSensorManagerFactory();
    ui->Label_WristArmScore->setText("0");

    myLpms.head = &head;
    myLpms.body = &body;
    myLpms.rUpperArm=&rUpperArm;
    myLpms.rLowerArm=&rLowerArm;
    myLpms.rWrist=&rWrist;
    myLpms.lUpperArm=&lUpperArm;
    myLpms.lLowerArm=&lLowerArm;
    myLpms.lWrist=&lWrist;

    myLpms.body->address="00:04:3E:9B:A3:62";
    myLpms.body->id=0;//should be at first to update for the following models updating altitude at the same frame
    myLpms.body->type="body";

    myLpms.head->address="";
    myLpms.head->id=1;
    myLpms.head->type="head";

    myLpms.rUpperArm->address="00:04:3E:9B:A2:BE";
    myLpms.rUpperArm->id=2;
    myLpms.rUpperArm->type="rUpperArm";
    myLpms.rUpperArm->viewZ+=90;

    myLpms.rLowerArm->address="00:04:3E:9B:A2:8E";
    myLpms.rLowerArm->id=3;
    myLpms.rLowerArm->type="rLowerArm";
    myLpms.rLowerArm->viewZ+=90;

    myLpms.rWrist->address="00:04:3E:9B:A2:EF";
    myLpms.rWrist->id=4;
    myLpms.rWrist->type="rWrist";
    myLpms.rWrist->viewZ+=90;

    myLpms.lUpperArm->address="";
    myLpms.lUpperArm->id=5;
    myLpms.lUpperArm->type="lUpperArm";
    myLpms.lUpperArm->viewZ-=90;

    myLpms.lLowerArm->address="";
    myLpms.lLowerArm->id=6;
    myLpms.lLowerArm->type="lLowerArm";
    myLpms.lLowerArm->viewZ-=90;

    myLpms.lWrist->address="";
    myLpms.lWrist->id=7;
    myLpms.lWrist->type="lWrist";
    myLpms.lWrist->viewZ-=90;


    lpmsList.push_back(&head);
    lpmsList.push_back(&body);
    lpmsList.push_back(&rUpperArm);
    lpmsList.push_back(&rLowerArm);
    lpmsList.push_back(&rWrist);
    lpmsList.push_back(&lUpperArm);
    lpmsList.push_back(&lLowerArm);
    lpmsList.push_back(&lWrist);

    QString file = "C:/Users/goodman-home/Desktop/body_part/body-1.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.body);
    file = "C:/Users/goodman-home/Desktop/body_part/head.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.head);
    file = "C:/Users/goodman-home/Desktop/body_part/R_upper_arm.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.rUpperArm);
    file = "C:/Users/goodman-home/Desktop/body_part/R_lower_arm.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.rLowerArm);
    file = "C:/Users/goodman-home/Desktop/body_part/R_wrist.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.rWrist);
    file = "C:/Users/goodman-home/Desktop/body_part/L_upper_arm.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.lUpperArm);
    file = "C:/Users/goodman-home/Desktop/body_part/L_lower_arm.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.lLowerArm);
    file = "C:/Users/goodman-home/Desktop/body_part/L_wrist.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.lWrist);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionclose_triggered()
{
    close();
}

void MainWindow::data_display(LpmsDevice *m_lpms){

    /* ps1
    m_lpms->quat_ajusted=m_lpms->quat_raw*m_lpms->quat_ajust;
    */

    auto EulerEngle=m_lpms->euler_raw;


    /*
     * When using QQuaternion to euler angles,
     * y is roll, x is pitch, z is yaw
    */

    // y is yaw, z is roll, x is pitch
    int roll=static_cast<int>(EulerEngle.x());
    int pitch=static_cast<int>(EulerEngle.y());
    int yaw=static_cast<int>(EulerEngle.z());

    //QQuaternion a;
    //a.fromEulerAngles(pitch,yaw,roll);
    //m_lpms->quat_raw=a;
    //QString text1=QString("roll1=%1 \npitch1=%2 \nyaw1=%3").arg(m_lpms->euler_raw.x()).arg(m_lpms->euler_raw.y()).arg(m_lpms->euler_raw.z());
    //ui->textbrowser->append(text1);
    QString text=QString("roll=%1 \npitch=%2 \nyaw=%3").arg(roll).arg(pitch).arg(yaw);
    ui->textbrowser->append(text);

}




void MainWindow::data_receive(LpmsDevice *m_lpms)
{

    // Check if sensor is connected
    if ( m_lpms->function->getConnectionStatus() == SENSOR_CONNECTION_CONNECTED &&
         m_lpms->function->hasImuData())
    {
        //Get all data to temp
        ImuData temp=   m_lpms->function->getCurrentData();
        // Get quaternion data
        m_lpms->quat_raw.setScalar(temp.q[0]);
        m_lpms->quat_raw.setX(temp.q[1]);
        m_lpms->quat_raw.setY(temp.q[2]);
        m_lpms->quat_raw.setZ(temp.q[3]);

        m_lpms->euler_raw.setX(temp.r[0]);
        m_lpms->euler_raw.setY(temp.r[1]);
        m_lpms->euler_raw.setZ(temp.r[2]);

        // QQuaternion fromEuler=QQuaternion::fromEulerAngles(-temp.r[1],temp.r[2],temp.r[0]);
        // m_lpms->quat_raw=fromEuler;

    }
}

void MainWindow::lpms_connect(LpmsDevice *m_lpms)
{
    /*
    LPMSaddress[0]="00:04:3E:9B:A2:EF";
    LPMSaddress[1]="00:04:3E:9B:A3:62";
    LPMSaddress[2]="00:04:3E:9B:A2:BE";
    LPMSaddress[3]="00:04:3E:9B:A2:8E";
    LPMSaddress[4]="00:04:3E:9F:E1:2A";
    */

    m_lpms->function=manager->addSensor(DEVICE_LPMS_B, m_lpms->address);
    m_lpms->function->setConfigurationPrm(PRM_ACC_RANGE, SELECT_ACC_RANGE_2G);

    m_lpms->function->setConfigurationPrm(PRM_ACC_RANGE, SELECT_STREAM_FREQ_50HZ);
    int hi;
    m_lpms->function->getConfigurationPrm(PRM_ACC_RANGE, &hi);
    while(1){
        if(m_lpms->function->getConnectionStatus() == SENSOR_CONNECTION_CONNECTED)
        {

            ui->textbrowser->append("IMU connect "+ QString::fromStdString(m_lpms->type));
            break;
        }
    }


}


void MainWindow::timer_loop()
{
    std::list<LpmsDevice *>::iterator it;
    //get data
    for (it = lpmsList.begin(); it != lpmsList.end(); ++it) {
        if((*it)->type=="head"){
            (*it)->quat_raw=myLpms.rUpperArm->quat_raw;
        }
        else if((*it)->type=="lUpperArm"){
            (*it)->quat_raw=myLpms.rUpperArm->quat_raw;
        }
        else if((*it)->type=="lLowerArm"){
            (*it)->quat_raw=myLpms.rLowerArm->quat_raw;
        }
        else if((*it)->type=="lWrist"){
            (*it)->quat_raw=myLpms.rWrist->quat_raw;
        }
        else{
            data_receive(*it);
            data_display(*it);
        }
    }

    //LPMS_SEARCH_ID[myLpms.head->id]=myLpms.head;
    //LPMS_SEARCH_ID[myLpms.body->id]=myLpms.body;
    //int AScore=rula_calc();
    //ui->Label_WristArmScore->setText(QString::number(AScore));

}

int MainWindow::rula_calc()
{

    auto EulerEngleUpArm=myLpms.head->quat_raw.toEulerAngles();
    auto EulerEngleLowArm=myLpms.head->quat_raw.toEulerAngles();
    auto EulerEngleWrist=myLpms.head->quat_raw.toEulerAngles();
    auto EulerEngleHead=myLpms.head->quat_raw.toEulerAngles();
    auto EulerEngleTrunk=myLpms.body->quat_raw.toEulerAngles();

    //(int) is old-style cast
    int UpperArmPos_roll=static_cast<int>(EulerEngleUpArm.y())+90;//roll
    int UpperArmPos_pitch=static_cast<int>(EulerEngleUpArm.x());//pitch
    //int UpperArmPos_yaw=static_cast<int>(EulerEngleUpArm.z());
    int LowerArmPos_roll=static_cast<int>(EulerEngleLowArm.y())+90;//roll
    int LowerArmPos_pitch=static_cast<int>(EulerEngleLowArm.x());//pitch
    int LowerArmPos_yaw=static_cast<int>(EulerEngleLowArm.z());
    int WristPos_roll=static_cast<int>(EulerEngleWrist.y())+90;
    int WristPos_pitch=static_cast<int>(EulerEngleWrist.x());
    int WristPos_yaw=static_cast<int>(EulerEngleWrist.z());//z, if wrist is bent from the midline
    int NeckPos_roll=static_cast<int>(EulerEngleHead.y())+90;//roll
    int TrunkPos_roll=static_cast<int>(EulerEngleTrunk.y())+90;
    int TrunkPos_yaw=static_cast<int>(EulerEngleTrunk.z());
    int WristTwistScore=0;
    int UpperArmScore=0;
    int LowerArmScore=0;
    int WristScore=0;

    ui->textbrowser->append("UpperArmPos_roll: "+QString::number(UpperArmPos_roll));
    ui->textbrowser->append("UpperArmPos_pitch: "+QString::number(UpperArmPos_pitch));
    ui->textbrowser->append("LowerArmPos_roll: "+QString::number(LowerArmPos_roll));
    ui->textbrowser->append("LowerArmPos_pitch: "+QString::number(LowerArmPos_pitch));
    ui->textbrowser->append("LowerArmPos_yaw: "+QString::number(LowerArmPos_yaw));
    ui->textbrowser->append("WristPos_roll: "+QString::number(WristPos_roll));
    ui->textbrowser->append("WristPos_pitch: "+QString::number(WristPos_pitch));
    ui->textbrowser->append("WristPos_yaw: "+QString::number(WristPos_yaw));




    //step1 test upper arm
    if(UpperArmPos_roll<20 && UpperArmPos_roll>-20){
        UpperArmScore=1;
    }
    else if (UpperArmPos_roll<=-20) {
        UpperArmScore=2;
    }
    else if (UpperArmPos_roll>=20 && UpperArmPos_roll<45) {
        UpperArmScore=3;
    }
    else if (UpperArmPos_roll>=45 && UpperArmPos_roll<90) {
        UpperArmScore=3;
    }
    else if (UpperArmPos_roll>=90 && UpperArmPos_roll<180) {
        UpperArmScore=4;
    }
    if(ui->check_rula_1->isChecked()){
        UpperArmScore+=1;
    }
    if(ui->check_rula_2->isChecked()){
        UpperArmScore+=1;
    }
    if(ui->check_rula_3->isChecked()){
        UpperArmScore-=1;
    }
    ui->textbrowser->append(QString::number(UpperArmScore));
    //step2 test lower arm
    if(LowerArmPos_roll<120 && UpperArmPos_roll>80){
        LowerArmScore=1;
    }
    else if ((LowerArmPos_roll<=80 && LowerArmPos_roll>0 )||(LowerArmPos_roll<180 && LowerArmPos_roll>=120)) {
        LowerArmScore=2;
    }
    if (LowerArmPos_yaw-TrunkPos_yaw >10) {
        LowerArmScore+=1;
    }
    ui->textbrowser->append(QString::number(LowerArmScore));
    //step3 test wrist
    if(abs(WristPos_roll-LowerArmPos_roll)<=5){
        WristScore=1;
    }
    else if (abs(WristPos_roll-LowerArmPos_roll)>5 && abs(WristPos_roll-LowerArmPos_roll)<=15) {
        WristScore=2;
    }
    else if (abs(WristPos_roll-LowerArmPos_roll)>15) {
        WristScore=3;
    }
    if(abs(WristPos_yaw-LowerArmPos_yaw)>3){
        WristScore+=1;
    }
    ui->textbrowser->append(QString::number(WristScore));
    //step4 test wrist twist
    if(abs(WristPos_pitch-UpperArmPos_pitch)<20){
        WristTwistScore=1;
    }
    else if (abs(WristPos_pitch-LowerArmPos_pitch)>=20 && abs(WristPos_pitch-LowerArmPos_pitch)<180) {
        WristTwistScore=2;
    }

    //table A
    int PosScoreA=0;

    switch (UpperArmScore) {
    case 1:
        switch (LowerArmScore) {
        case 1:
            switch (WristScore) {
            case 1:
                if(WristTwistScore==1)
                    PosScoreA=1;
                else if (WristTwistScore==2)
                    PosScoreA=2;
                break;
            case 2:
                PosScoreA=2;
                break;
            case 3:
                if(WristTwistScore==1)
                    PosScoreA=2;
                else if (WristTwistScore==2)
                    PosScoreA=3;
                break;
            case 4:
                PosScoreA=3;
                break;
            }
            break;
        case 2:
            switch (WristScore) {
            case 1:
                PosScoreA=2;
                break;
            case 2:
                PosScoreA=2;
                break;
            case 3:
                PosScoreA=3;
                break;
            case 4:
                PosScoreA=3;
                break;
            }
            break;
        case 3:
            switch (WristScore) {
            case 1:
                if(WristTwistScore==1)
                    PosScoreA=2;
                else if (WristTwistScore==2)
                    PosScoreA=3;
                break;
            case 2:
                if(WristTwistScore==1)
                    PosScoreA=3;
                else if (WristTwistScore==2)
                    PosScoreA=3;
                break;
            case 3:
                if(WristTwistScore==1)
                    PosScoreA=3;
                else if (WristTwistScore==2)
                    PosScoreA=3;
                break;
            case 4:
                if(WristTwistScore==1)
                    PosScoreA=4;
                else if (WristTwistScore==2)
                    PosScoreA=4;
                break;
            }
            break;

        }
        break;
    case 2:
        switch (LowerArmScore) {
        case 1:
            switch (WristScore) {
            case 1:
                if(WristTwistScore==1)
                    PosScoreA=2;
                else if (WristTwistScore==2)
                    PosScoreA=3;
                break;
            case 2:
                PosScoreA=3;
                break;
            case 3:
                if(WristTwistScore==1)
                    PosScoreA=3;
                else if (WristTwistScore==2)
                    PosScoreA=4;
                break;
            case 4:
                PosScoreA=4;
                break;
            }
            break;
        case 2:
            switch (WristScore) {
            case 1:
                PosScoreA=3;
                break;
            case 2:
                PosScoreA=3;
                break;
            case 3:
                if(WristTwistScore==1)
                    PosScoreA=3;
                else if (WristTwistScore==2)
                    PosScoreA=4;
                break;
            case 4:
                PosScoreA=4;
                break;
            }
            break;
        case 3:
            switch (WristScore) {
            case 1:
                if(WristTwistScore==1)
                    PosScoreA=3;
                else if (WristTwistScore==2)
                    PosScoreA=4;
                break;
            case 2:
                PosScoreA=4;
                break;
            case 3:
                PosScoreA=4;
                break;
            case 4:
                PosScoreA=5;
                break;
            }
            break;

        }
        break;
    case 3:
        switch (LowerArmScore) {
        case 1:
            switch (WristScore) {
            case 1:
                if(WristTwistScore==1)
                    PosScoreA=3;
                else if (WristTwistScore==2)
                    PosScoreA=3;
                break;
            case 2:
                PosScoreA=4;
                break;
            case 3:
                PosScoreA=4;
                break;
            case 4:
                PosScoreA=5;
                break;
            }
            break;
        case 2:
            switch (WristScore) {
            case 1:
                if(WristTwistScore==1)
                    PosScoreA=3;
                else if (WristTwistScore==2)
                    PosScoreA=4;
                break;
            case 2:
                PosScoreA=4;
                break;
            case 3:
                PosScoreA=4;
                break;
            case 4:
                PosScoreA=5;
                break;
            }
            break;
        case 3:
            switch (WristScore) {
            case 1:
                PosScoreA=4;
                break;
            case 2:
                PosScoreA=4;
                break;
            case 3:
                if(WristTwistScore==1)
                    PosScoreA=4;
                else if (WristTwistScore==2)
                    PosScoreA=5;
                break;
            case 4:
                PosScoreA=5;
                break;
            }
            break;

        }
        break;
    case 4:
        switch (LowerArmScore) {
        case 1:
            switch (WristScore) {
            case 1:
                PosScoreA=4;
                break;
            case 2:
                PosScoreA=4;
                break;
            case 3:
                if(WristTwistScore==1)
                    PosScoreA=4;
                else if (WristTwistScore==2)
                    PosScoreA=5;
                break;
            case 4:
                PosScoreA=5;
                break;
            }
            break;
        case 2:
            switch (WristScore) {
            case 1:
                PosScoreA=4;
                break;
            case 2:
                PosScoreA=4;
                break;
            case 3:
                if(WristTwistScore==1)
                    PosScoreA=4;
                else if (WristTwistScore==2)
                    PosScoreA=5;
                break;
            case 4:
                PosScoreA=5;
                break;
            }
            break;
        case 3:
            switch (WristScore) {
            case 1:
                PosScoreA=4;
                break;
            case 2:
                if(WristTwistScore==1)
                    PosScoreA=4;
                else if (WristTwistScore==2)
                    PosScoreA=5;
                break;
            case 3:
                PosScoreA=5;
                break;
            case 4:
                PosScoreA=6;
                break;
            }
            break;

        }
        break;
    case 5:
        switch (LowerArmScore) {
        case 1:
            switch (WristScore) {
            case 1:
                PosScoreA=5;
                break;
            case 2:
                PosScoreA=5;
                break;
            case 3:
                if(WristTwistScore==1)
                    PosScoreA=5;
                else if (WristTwistScore==2)
                    PosScoreA=6;
                break;
            case 4:
                if(WristTwistScore==1)
                    PosScoreA=6;
                else if (WristTwistScore==2)
                    PosScoreA=7;
                break;
            }
            break;
        case 2:
            switch (WristScore) {
            case 1:
                if(WristTwistScore==1)
                    PosScoreA=5;
                else if (WristTwistScore==2)
                    PosScoreA=6;
                break;
            case 2:
                PosScoreA=6;
                break;
            case 3:
                if(WristTwistScore==1)
                    PosScoreA=6;
                else if (WristTwistScore==2)
                    PosScoreA=7;
                break;
            case 4:
                PosScoreA=7;
                break;
            }
            break;
        case 3:
            switch (WristScore) {
            case 1:
                PosScoreA=6;
                break;
            case 2:
                if(WristTwistScore==1)
                    PosScoreA=6;
                else if (WristTwistScore==2)
                    PosScoreA=7;
                break;
            case 3:
                PosScoreA=7;
                break;
            case 4:
                if(WristTwistScore==1)
                    PosScoreA=7;
                else if (WristTwistScore==2)
                    PosScoreA=8;
                break;
            }
            break;

        }
        break;
    case 6:
        switch (LowerArmScore) {
        case 1:
            switch (WristScore) {
            case 1:
                PosScoreA=7;
                break;
            case 2:
                PosScoreA=7;
                break;
            case 3:
                if(WristTwistScore==1)
                    PosScoreA=7;
                else if (WristTwistScore==2)
                    PosScoreA=8;
                break;
            case 4:
                if(WristTwistScore==1)
                    PosScoreA=8;
                else if (WristTwistScore==2)
                    PosScoreA=9;
                break;
            }
            break;
        case 2:
            switch (WristScore) {
            case 1:
                PosScoreA=8;
                break;
            case 2:
                PosScoreA=8;
                break;
            case 3:
                if(WristTwistScore==1)
                    PosScoreA=8;
                else if (WristTwistScore==2)
                    PosScoreA=9;
                break;
            case 4:
                PosScoreA=9;
                break;
            }
            break;
        case 3:
            PosScoreA=9;
            break;
        }
        break;
    }

    return PosScoreA;
}

void MainWindow::on_BTN_StartAllLpms_clicked()
{
    std::list<LpmsDevice *>::iterator it;
    for (it = lpmsList.begin(); it != lpmsList.end(); ++it) {
        if((*it)->id<=4&&(*it)->id>=1)
            lpms_connect(*it);
    }


    dataTimer = new QTimer(this);
    dataTimer->start(20);
    connect(dataTimer,SIGNAL(timeout()),this,SLOT(timer_loop()));

}


void MainWindow::on_BTN_set_origin_clicked()
{
    std::list<LpmsDevice *>::iterator it;
    for (it = lpmsList.begin(); it != lpmsList.end(); ++it) {
        if((*it)->type=="head"){

        }
        else if((*it)->type=="lUpperArm"){

        }
        else if((*it)->type=="lLowerArm"){

        }
        else if((*it)->type=="lWrist"){

        }
        else{
             (*it)->getme()->function->setOrientationOffset(0);
        }
    }

    /*ps1
    myLpms.head->quat_ajust=myLpms.head->quat_raw.inverted();
    myLpms.body->quat_ajust=myLpms.body->quat_raw.inverted();
    */
}

void MainWindow::on_btn_x_plus_clicked()
{   
    std::list<LpmsDevice *>::iterator it;
    for (it = lpmsList.begin(); it != lpmsList.end(); ++it) {
        if((*it)->getme()->id==ActiveModelID){
            (*it)->getme()->viewX+=90;
        }
    }
}

void MainWindow::on_btn_y_plus_clicked()
{
    std::list<LpmsDevice *>::iterator it;
    for (it = lpmsList.begin(); it != lpmsList.end(); ++it) {
        if((*it)->getme()->id==ActiveModelID){
            (*it)->getme()->viewY+=90;
        }
    }
}

void MainWindow::on_btn_z_plus_clicked()
{
    std::list<LpmsDevice *>::iterator it;
    for (it = lpmsList.begin(); it != lpmsList.end(); ++it) {
        if((*it)->getme()->id==ActiveModelID){
            (*it)->getme()->viewZ+=90;
        }
    }
}

void MainWindow::on_OpenHead_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                "Open Head",
                                                QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).at(0),
                                                "*.obj");
    if(QFile(file).exists())
    {
        std::cout << file.toStdString() << std::endl;
        ui->widget->loadObjFile(file.toStdString(), myLpms.head);
        ActiveModelID=myLpms.head->id;
    }
}

void MainWindow::on_OpenBody_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                "Open Body",
                                                QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).at(0),
                                                "*.obj");

    if(QFile(file).exists())
    {
        std::cout << file.toStdString() << std::endl;
        ui->widget->loadObjFile(file.toStdString(), myLpms.body);
        ActiveModelID=myLpms.body->id;
    }
}


/**
Ps1:
    使用此方法，用新矩陣事後補償IMU的資料，所以IMU在現實空間並沒有校正，會受到pitch角影響精準度
    and old method using correction rotation matrix to set offset
    new nethod is to directly call the IMU build-in function to set offset.

**/

void MainWindow::on_OpenRightUpperArm_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                "Open RightUpperArm",
                                                QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).at(0),
                                                "*.obj");

    if(QFile(file).exists())
    {
        std::cout << file.toStdString() << std::endl;
        ui->widget->loadObjFile(file.toStdString(), myLpms.rUpperArm);
        ActiveModelID=myLpms.rUpperArm->id;
    }
}

void MainWindow::on_OpenRightLowerArm_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                "Open RightLowerArm",
                                                QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).at(0),
                                                "*.obj");

    if(QFile(file).exists())
    {
        std::cout << file.toStdString() << std::endl;
        ui->widget->loadObjFile(file.toStdString(), myLpms.rLowerArm);
        ActiveModelID=myLpms.rLowerArm->id;
    }
}

void MainWindow::on_OpenRightWrist_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                "Open RightWrist",
                                                QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).at(0),
                                                "*.obj");
    qDebug()<<file;
    if(QFile(file).exists())
    {
        std::cout << file.toStdString() << std::endl;
        ui->widget->loadObjFile(file.toStdString(), myLpms.rWrist);
        ActiveModelID=myLpms.rWrist->id;
    }
}
