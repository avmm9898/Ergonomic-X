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
    ui->Label_Score->setText("Waiting for connection");
    ui->groupBox->hide();

    myLpms.head = &head;
    myLpms.body = &body;
    myLpms.rUpperArm=&rUpperArm;
    myLpms.rLowerArm=&rLowerArm;
    myLpms.rWrist=&rWrist;
    myLpms.lUpperArm=&lUpperArm;
    myLpms.lLowerArm=&lLowerArm;
    myLpms.lWrist=&lWrist;

    myLpms.rUpperLeg=&rUpperLeg;
    myLpms.rLowerLeg=&rLowerLeg;
    myLpms.lUpperLeg=&lUpperLeg;
    myLpms.lLowerLeg=&lLowerLeg;

    myLpms.body->address="00:04:3E:9B:A2:8E";
    myLpms.body->id=0;//should be at first to update for the following models updating altitude at the same frame
    myLpms.body->type="body";

    myLpms.head->address="00:04:3E:4B:33:67";
    myLpms.head->id=1;
    myLpms.head->type="head";

    myLpms.rUpperArm->address="00:04:3E:9B:A2:BE";
    myLpms.rUpperArm->id=2;
    myLpms.rUpperArm->type="rUpperArm";
    myLpms.rUpperArm->viewZ+=90;
    myLpms.rUpperArm->viewX-=90;


    myLpms.rLowerArm->address="00:04:3E:9B:A3:62";
    myLpms.rLowerArm->id=3;
    myLpms.rLowerArm->type="rLowerArm";
    myLpms.rLowerArm->viewZ+=90;
    myLpms.rLowerArm->viewX-=90;

    myLpms.rWrist->address="";
    myLpms.rWrist->id=4;
    myLpms.rWrist->type="rWrist";
    myLpms.rWrist->viewZ+=90;
    myLpms.rWrist->viewX-=90;

    myLpms.lUpperArm->address="";
    myLpms.lUpperArm->id=5;
    myLpms.lUpperArm->type="lUpperArm";
    myLpms.lUpperArm->viewZ-=90;
    myLpms.lUpperArm->viewX-=90;

    myLpms.lLowerArm->address="";
    myLpms.lLowerArm->id=6;
    myLpms.lLowerArm->type="lLowerArm";
    myLpms.lLowerArm->viewZ-=90;
    myLpms.lLowerArm->viewX-=90;

    myLpms.lWrist->address="";
    myLpms.lWrist->id=7;
    myLpms.lWrist->type="lWrist";
    myLpms.lWrist->viewZ-=90;
    myLpms.lWrist->viewX-=90;

    myLpms.rUpperLeg->address="00:04:3E:4B:33:98";
    myLpms.rUpperLeg->id=8;
    myLpms.rUpperLeg->type="rUpperLeg";

    myLpms.rLowerLeg->address="";
    myLpms.rLowerLeg->id=9;
    myLpms.rLowerLeg->type="rLowerLeg";

    myLpms.lUpperLeg->address="";
    myLpms.lUpperLeg->id=10;
    myLpms.lUpperLeg->type="lUpperLeg";

    myLpms.lLowerLeg->address="";
    myLpms.lLowerLeg->id=11;
    myLpms.lLowerLeg->type="lLowerLeg";

    lpmsList.push_back(&head);
    lpmsList.push_back(&body);
    lpmsList.push_back(&rUpperArm);
    lpmsList.push_back(&rLowerArm);
    lpmsList.push_back(&rWrist);
    lpmsList.push_back(&lUpperArm);
    lpmsList.push_back(&lLowerArm);
    lpmsList.push_back(&lWrist);
    lpmsList.push_back(&rUpperLeg);
    lpmsList.push_back(&rLowerLeg);
    lpmsList.push_back(&lUpperLeg);
    lpmsList.push_back(&lLowerLeg);

    QString modelfolder="C:/body_part/";
    QString file = modelfolder+"body-1.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.body);
    file = modelfolder+"head.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.head);
    file = modelfolder+"R_upper_arm.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.rUpperArm);
    file = modelfolder+"R_lower_arm.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.rLowerArm);
    file = modelfolder+"R_wrist.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.rWrist);
    file = modelfolder+"L_upper_arm.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.lUpperArm);
    file = modelfolder+"L_lower_arm.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.lLowerArm);
    file = modelfolder+"L_wrist.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.lWrist);
    file = modelfolder+"L_lower_leg.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.lLowerLeg);
    file = modelfolder+"L_upper_leg.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.lUpperLeg);
    file = modelfolder+"R_lower_leg.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.rLowerLeg);
    file = modelfolder+"R_upper_leg.obj";
    ui->widget->loadObjFile(file.toStdString(), myLpms.rUpperLeg);
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
    QString text=QString( QString::fromStdString(m_lpms->type)+" roll=%1 pitch=%2 yaw=%3").arg(roll).arg(pitch).arg(yaw);
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


        if(temp.r[0]<0){
            temp.r[0]=360+temp.r[0];
        }

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

    m_lpms->function->setConfigurationPrm(PRM_ACC_RANGE, SELECT_STREAM_FREQ_25HZ);
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

    QVector3D temp;  //for 少量的IMU用來測試RULA, REBA等分數
    //get data
    for (it = lpmsList.begin(); it != lpmsList.end(); ++it) {
        if((*it)->type=="lUpperArm"){

            temp.setX(myLpms.rUpperArm->quat_raw.toEulerAngles().x());
            temp.setY(-myLpms.rUpperArm->quat_raw.toEulerAngles().y());
            temp.setZ(-myLpms.rUpperArm->quat_raw.toEulerAngles().z());
            (*it)->quat_raw=QQuaternion::fromEulerAngles(temp);

        }
        else if((*it)->type=="lLowerArm"){
            temp.setX(myLpms.rLowerArm->quat_raw.toEulerAngles().x());
            temp.setY(-myLpms.rLowerArm->quat_raw.toEulerAngles().y());
            temp.setZ(-myLpms.rLowerArm->quat_raw.toEulerAngles().z());
            (*it)->quat_raw=QQuaternion::fromEulerAngles(temp);
        }
        else if((*it)->type=="rWrist"){
            (*it)->quat_raw=myLpms.rLowerArm->quat_raw;
        }
        else if((*it)->type=="lWrist"){
            temp.setX(myLpms.rWrist->quat_raw.toEulerAngles().x());
            temp.setY(-myLpms.rWrist->quat_raw.toEulerAngles().y());
            temp.setZ(-myLpms.rWrist->quat_raw.toEulerAngles().z());
            (*it)->quat_raw=QQuaternion::fromEulerAngles(temp);
        }
        else if((*it)->type=="lUpperLeg"){
            temp.setX(myLpms.rUpperLeg->quat_raw.toEulerAngles().x());
            temp.setY(-myLpms.rUpperLeg->quat_raw.toEulerAngles().y());
            temp.setZ(-myLpms.rUpperLeg->quat_raw.toEulerAngles().z());
            (*it)->quat_raw=QQuaternion::fromEulerAngles(temp);
        }
        else if((*it)->type=="rLowerLeg"){
            temp.setX(-myLpms.rUpperLeg->quat_raw.toEulerAngles().x());
            temp.setY(myLpms.rUpperLeg->quat_raw.toEulerAngles().y());
            temp.setZ(myLpms.rUpperLeg->quat_raw.toEulerAngles().z());
            (*it)->quat_raw=QQuaternion::fromEulerAngles(temp);
        }
        else if((*it)->type=="lLowerLeg"){
            temp.setX(myLpms.rLowerLeg->quat_raw.toEulerAngles().x());
            temp.setY(-myLpms.rLowerLeg->quat_raw.toEulerAngles().y());
            temp.setZ(-myLpms.rLowerLeg->quat_raw.toEulerAngles().z());
            (*it)->quat_raw=QQuaternion::fromEulerAngles(temp);
        }
        else{
            data_receive(*it);
            data_display(*it);
        }
    }
    //rula_calc();
    if(ui->tabWidget->currentIndex()==0){
        ui->label->setText("RULA Score");
        ui->Label_Score->setText(QString::number(rula_calc()));
    }
    else if(ui->tabWidget->currentIndex()==1){
        ui->label->setText("REBA Score");
        ui->Label_Score->setText(QString::number(reba_calc()));
    }
    else if(ui->tabWidget->currentIndex()==2){
        ui->label->setText("AWBA Score");
    }



}

int MainWindow::rula_calc()
{
    QVector3D EulerEngleUpArm=myLpms.rUpperArm->euler_raw;
    QVector3D EulerEngleLowArm=myLpms.rLowerArm->euler_raw;
    QVector3D EulerEngleWrist=myLpms.rLowerArm->euler_raw;
    QVector3D EulerEngleHead=myLpms.head->euler_raw;
    QVector3D EulerEngleTrunk=myLpms.body->euler_raw;
    QVector3D EulerEngleLeg=myLpms.rUpperLeg->euler_raw;


    //(int) is old-style cast
    int UpperArm_roll=static_cast<int>(EulerEngleUpArm.x());//roll
    int UpperArm_pitch=static_cast<int>(EulerEngleUpArm.y());//pitch
    //int UpperArmPos_yaw=static_cast<int>(EulerEngleUpArm.z());
    int LowerArm_roll=static_cast<int>(EulerEngleLowArm.x());//roll
    int LowerArm_pitch=static_cast<int>(EulerEngleLowArm.y());//pitch
    int LowerArm_yaw=static_cast<int>(EulerEngleLowArm.z());
    int Wrist_roll=static_cast<int>(EulerEngleWrist.x());
    int Wrist_pitch=static_cast<int>(EulerEngleWrist.y());
    int Wrist_yaw=static_cast<int>(EulerEngleWrist.z());//z, if wrist is bent from the midline
    int Neck_roll=static_cast<int>(EulerEngleHead.x());//roll
    int Neck_pitch=static_cast<int>(EulerEngleHead.y());
    int Neck_yaw=static_cast<int>(EulerEngleHead.z());
    int Trunk_roll=static_cast<int>(EulerEngleTrunk.x());
    int Trunk_pitch=static_cast<int>(EulerEngleTrunk.y());
    int Trunk_yaw=static_cast<int>(EulerEngleTrunk.z());
    int Leg_roll=static_cast<int>(EulerEngleLeg.x());
    int Leg_pitch=static_cast<int>(EulerEngleLeg.y());
    int Leg_yaw=static_cast<int>(EulerEngleLeg.z());

    int WristTwistScore=0;
    int UpperArmScore=0;
    int LowerArmScore=0;
    int WristScore=0;
    int NeckScore=0;
    int TrunkScore=0;
    int LegScore=0;

    //    ui->textbrowser->append("UpperArm_roll: "+QString::number(UpperArm_roll));
    //    ui->textbrowser->append("UpperArm_pitch: "+QString::number(UpperArm_pitch));
    //    ui->textbrowser->append("LowerArm_roll: "+QString::number(LowerArm_roll));
    //    ui->textbrowser->append("LowerArm_pitch: "+QString::number(LowerArm_pitch));
    //    ui->textbrowser->append("LowerArm_yaw: "+QString::number(LowerArm_yaw));
    //    ui->textbrowser->append("Wrist_roll: "+QString::number(Wrist_roll));
    //    ui->textbrowser->append("Wrist_pitch: "+QString::number(Wrist_pitch));
    //    ui->textbrowser->append("Wrist_yaw: "+QString::number(Wrist_yaw));
    //    ui->textbrowser->append("Neck_roll: "+QString::number(Neck_roll));
    //    ui->textbrowser->append("Trunk_roll: "+QString::number(Trunk_roll));

    //step1 test upper arm
    if(UpperArm_roll<20 && UpperArm_roll>-20){
        UpperArmScore=1;
    }
    else if (UpperArm_roll>=20 && UpperArm_roll<45) {
        UpperArmScore=2;
    }
    else if (UpperArm_roll>=45 && UpperArm_roll<90) {
        UpperArmScore=3;
    }
    else if (UpperArm_roll>=90 && UpperArm_roll<180) {
        UpperArmScore=4;
    }
    else UpperArmScore=1;
    if(ui->check_rula_1->isChecked()){
        UpperArmScore+=1;
    }
    if(ui->check_rula_2->isChecked()){
        UpperArmScore+=1;
    }
    if(ui->check_rula_3->isChecked()){
        if(UpperArm_roll!=1)
            UpperArmScore-=1;
    }

    //step2 test lower arm
    if(LowerArm_roll<100 && LowerArm_roll>60){
        LowerArmScore=1;
    }
    else if ((LowerArm_roll<=60 && LowerArm_roll>0 )||(LowerArm_roll<180 && LowerArm_roll>=100)) {
        LowerArmScore=2;
    }
    else LowerArmScore=1;
    if (abs(LowerArm_yaw-Trunk_yaw) >5) {
        LowerArmScore+=1;
    }

    //step3 test wrist
    if(abs(Wrist_roll-LowerArm_roll)<=5){
        WristScore=1;
    }
    else if (abs(Wrist_roll-LowerArm_roll)>5 && abs(Wrist_roll-LowerArm_roll)<=15) {
        WristScore=2;
    }
    else if (abs(Wrist_roll-LowerArm_roll)>15) {
        WristScore=3;
    }
    else WristScore=1;
    if(abs(Wrist_yaw-LowerArm_yaw)>3){
        WristScore+=1;
    }

    //step4 test wrist twist
    if(abs(Wrist_pitch-LowerArm_pitch)<10){
        WristTwistScore=1;
    }
    else if (abs(Wrist_pitch-LowerArm_pitch)>=10 && abs(Wrist_pitch-LowerArm_pitch)<180) {
        WristTwistScore=2;
    }
    else WristTwistScore=1;

    //table A

    int tableA[18][8]={
        {1,2,2,2,2,3,3,3},
        {2,2,2,2,3,3,3,3},
        {2,3,3,3,3,3,4,4},
        {2,3,3,3,3,4,4,4},
        {3,3,3,3,3,4,4,4},
        {3,4,4,4,4,4,5,5},
        {3,3,4,4,4,4,5,5},
        {3,4,4,4,4,4,5,5},
        {4,4,4,4,4,5,5,5},
        {4,4,4,4,4,5,5,5},
        {4,4,4,4,4,5,5,5},
        {4,4,4,5,5,5,6,6},
        {5,5,5,5,5,6,6,7},
        {5,6,6,6,6,7,7,7},
        {6,6,6,7,7,7,7,8},
        {7,7,7,7,7,8,8,9},
        {8,8,8,8,8,9,9,9},
        {9,9,9,9,9,9,9,9},
    };

    int tableA_y=(UpperArmScore-1)*3+(LowerArmScore-1);
    int tableA_x=(WristScore-1)*2+(WristTwistScore-1);
    int tableAScore=tableA[tableA_y][tableA_x];
    if(ui->load_choose2->isChecked()){
        tableAScore+=1;
        if(ui->check_rula_4->isChecked())
            tableAScore+=1;
    }
    else if(ui->load_choose3->isChecked()){
        tableAScore+=3;
    }
    if (ui->check_rula_4->isChecked()){
        tableAScore+=1;
    }



    //step9 Neck score
    if(Neck_roll<360&&Neck_roll>=350){
        NeckScore=1;
    }
    else if(Neck_roll<350&&Neck_roll>=340){
        NeckScore=2;
    }
    else if(Neck_roll<340 && Neck_roll>=180){
        NeckScore=3;
    }
    else if(Neck_roll<180 && Neck_roll>5){
        NeckScore=4;
    }
    else NeckScore=1;
    if(abs(Neck_yaw-Trunk_yaw)>5)
        NeckScore+=1;
    if(abs(Neck_pitch)>5)
        NeckScore+=1;

    //step10 Trunk score
    if(Trunk_roll==0){
        TrunkScore=1;
    }
    else if(Trunk_roll<360&&Trunk_roll>=340){
        TrunkScore=2;
    }
    else if(Trunk_roll<340 && Trunk_roll>=300){
        TrunkScore=3;
    }
    else if(Trunk_roll<300 && Trunk_roll>=180){
        TrunkScore=4;
    }
    else TrunkScore=1;

    if(abs(Trunk_pitch)>5)
        TrunkScore+=1;

    //step11 Leg score
    if(ui->check_rula_5->isChecked())
        LegScore=1;
    else
        LegScore=2;

    int tabelB[6][12]={
        {1,3,2,3,3,4,5,5,6,6,7,7},
        {2,3,2,3,4,5,5,5,6,7,7,7},
        {3,3,3,4,4,5,5,6,6,7,7,7},
        {5,5,5,6,6,7,7,7,7,7,8,8},
        {7,7,7,7,7,8,8,8,8,8,8,8},
        {8,8,8,8,8,8,8,9,9,9,9,9},
    };

    int tableB_y=(NeckScore-1);
    int tableB_x=(TrunkScore-1)*2+(LegScore-1);
    int tableBScore=tabelB[tableB_y][tableB_x];
    if(ui->load_choose2->isChecked()){
        tableBScore+=1;
        if(ui->check_rula_4->isChecked())
            tableBScore+=1;
    }
    else if(ui->load_choose3->isChecked()){
        tableBScore+=3;
    }
    if (ui->check_rula_4->isChecked()){
        tableBScore+=1;
    }


    int tableC[8][7]={
        {1,2,3,3,4,5,5},
        {2,2,3,4,4,5,5},
        {3,3,3,4,4,5,6},
        {3,3,3,4,5,6,6},
        {4,4,4,5,6,7,7},
        {4,4,5,6,6,7,7},
        {5,5,6,6,7,7,7},
        {5,5,6,7,7,7,7}
    };
    int tableCScore=tableC[tableAScore-1][tableBScore-1];

    ui->textbrowser->append(QString::number(tableAScore));
    ui->textbrowser->append(QString::number(tableBScore));
    ui->textbrowser->append(QString::number(tableCScore));

    return tableCScore;
}

int MainWindow::reba_calc()
{
    QVector3D EulerEngleUpArm=myLpms.rUpperArm->euler_raw;
    QVector3D EulerEngleLowArm=myLpms.rLowerArm->euler_raw;
    QVector3D EulerEngleWrist=myLpms.rLowerArm->euler_raw;
    QVector3D EulerEngleHead=myLpms.head->euler_raw;
    QVector3D EulerEngleTrunk=myLpms.body->euler_raw;
    QVector3D EulerEngleLeg=myLpms.rUpperLeg->euler_raw;

    //(int) is old-style cast
    int UpperArm_roll=static_cast<int>(EulerEngleUpArm.x());//roll
    int UpperArm_pitch=static_cast<int>(EulerEngleUpArm.y());//pitch
    //int UpperArmPos_yaw=static_cast<int>(EulerEngleUpArm.z());
    int LowerArm_roll=static_cast<int>(EulerEngleLowArm.x());//roll
    int LowerArm_pitch=static_cast<int>(EulerEngleLowArm.y());//pitch
    int LowerArm_yaw=static_cast<int>(EulerEngleLowArm.z());
    int Wrist_roll=static_cast<int>(EulerEngleWrist.x());
    int Wrist_pitch=static_cast<int>(EulerEngleWrist.y());
    int Wrist_yaw=static_cast<int>(EulerEngleWrist.z());//z, if wrist is bent from the midline
    int Neck_roll=static_cast<int>(EulerEngleHead.x());
    int Neck_pitch=static_cast<int>(EulerEngleHead.y());
    int Neck_yaw=static_cast<int>(EulerEngleHead.z());
    int Trunk_roll=static_cast<int>(EulerEngleTrunk.x());
    int Trunk_pitch=static_cast<int>(EulerEngleTrunk.y());
    int Trunk_yaw=static_cast<int>(EulerEngleTrunk.z());
    int Leg_roll=static_cast<int>(EulerEngleLeg.x());
    int Leg_pitch=static_cast<int>(EulerEngleLeg.y());
    int Leg_yaw=static_cast<int>(EulerEngleLeg.z());

    int WristTwistScore=0;
    int UpperArmScore=0;
    int LowerArmScore=0;
    int WristScore=0;
    int NeckScore=0;
    int TrunkScore=0;
    int LegScore=0;

    //step1. Locate Neck Position
    if(Neck_roll>340 && Neck_roll<=350)
        NeckScore=1;
    else if(Neck_roll>180 && Neck_roll<=340)
        NeckScore=2;
    else if(Neck_roll>10 && Neck_roll<=180)
        NeckScore=2;
    else
        NeckScore=1;
    if(abs(Neck_yaw-Trunk_yaw)>5)
        NeckScore+=1;
    if(abs(Neck_pitch)>5)
        NeckScore+=1;
    //step2. Locate Trunk Position
    if(Trunk_roll==0){
        TrunkScore=1;
    }
    else if(Trunk_roll<360&&Trunk_roll>=340){
        TrunkScore=2;
    }
    else if(Trunk_roll<340 && Trunk_roll>=300){
        TrunkScore=3;
    }
    else if(Trunk_roll<300 && Trunk_roll>=180){
        TrunkScore=4;
    }
    else if(Trunk_roll>0 && Trunk_roll<180){
        TrunkScore=2;
    }
    else TrunkScore=1;

    if(abs(Trunk_pitch)>5)
        TrunkScore+=1;

    //step3. Leg score
    if(Leg_roll>30 && Leg_roll<=60)
        LegScore=2;
    else if(Leg_roll>60 && Leg_roll<300)
        LegScore=3;
    else
        LegScore=1;
    //step3. table A
    int tableA[5][12]={
        {1,2,3,4,1,2,3,4,3,3,5,6},
        {2,3,4,5,3,4,5,6,4,5,6,7},
        {2,4,5,6,4,5,6,7,5,6,7,8},
        {3,5,6,7,5,6,7,8,6,7,8,9},
        {4,6,7,8,6,7,8,9,7,8,9,9},
    };

    int tableAScore=tableA[TrunkScore-1][(NeckScore-1)*4+LegScore-1];

    //step5. force
    int ScoreA=tableAScore+int(ui->reba_weight2->isChecked())*1+int(ui->reba_weight3->isChecked())*2;

    //step7. upper arm
    if(UpperArm_roll<20 && (UpperArm_roll-360)>-20){
        UpperArmScore=1;
    }
    else if ((UpperArm_roll>=20 && UpperArm_roll<45) || (UpperArm_roll<=340 && UpperArm_roll>180)) {
        UpperArmScore=2;
    }
    else if (UpperArm_roll>=45 && UpperArm_roll<90) {
        UpperArmScore=3;
    }
    else if (UpperArm_roll>=90 && UpperArm_roll<180) {
        UpperArmScore=4;
    }
    else UpperArmScore=1;


    if(ui->check_reba_1->isChecked()){
        UpperArmScore+=1;
    }
    if(ui->check_reba_2->isChecked()){
        UpperArmScore+=1;
    }
    if(ui->check_reba_3->isChecked()){
        if(UpperArm_roll!=1)
            UpperArmScore-=1;
    }

    //step8. test lower arm
    if(LowerArm_roll<100 && LowerArm_roll>60){
        LowerArmScore=1;
    }
    else if ((LowerArm_roll<=60 && LowerArm_roll>0 )||(LowerArm_roll<180 && LowerArm_roll>=100)) {
        LowerArmScore=2;
    }
    else LowerArmScore=1;

    //step9.Wrist
    WristScore=2;
    //step11, 12
    int tableB[6][6]={
        {1,2,2,1,2,3},
        {1,2,3,2,3,4},
        {3,4,5,4,5,5},
        {6,7,8,7,8,8},
        {7,8,8,8,9,9}
    };

    int ScoreB=tableB[UpperArmScore-1][(LowerArmScore-1)*3+WristScore-1]
            +int(ui->Cp2->isChecked())
            +int(ui->Cp3->isChecked())*2
            +int(ui->Cp4->isChecked())*3;

    int tableC[12][12]={
        {1,1,1,2,3,3,4,5,6,7,7,7},
        {1,2,2,3,4,4,5,6,6,7,7,8},
        {2,3,3,3,4,5,6,7,7,8,8,8},
        {3,4,4,4,5,6,7,8,8,9,9,9},
        {4,4,4,5,6,7,8,8,9,9,9,9},
        {6,6,6,7,8,8,9,9,10,10,10,10},
        {7,7,7,8,9,9,910,10,11,11,11},
        {8,8,8,9,10,10,10,10,10,11,11,11},
        {9,9,9,10,10,10,11,11,11,12,12,12},
        {10,10,10,11,11,11,11,12,12,12,12,12},
        {11,11,11,11,12,12,12,12,12,12,12,12},
        {12,12,12,12,12,12,12,12,12,12,12,12},
    };

    int ScoreC=tableC[ScoreA-1][ScoreB-1]
            +int(ui->check_reba_act1->isChecked())
            +int(ui->check_reba_act2->isChecked())
            +int(ui->check_reba_act2->isChecked());
    return ScoreC;
}

int MainWindow::awba_calc()
{
    QVector3D EulerEngleUpArm=myLpms.rUpperArm->euler_raw;
    QVector3D EulerEngleLowArm=myLpms.rLowerArm->euler_raw;
    QVector3D EulerEngleWrist=myLpms.rLowerArm->euler_raw;
    QVector3D EulerEngleHead=myLpms.head->euler_raw;
    QVector3D EulerEngleTrunk=myLpms.body->euler_raw;
    QVector3D EulerEngleLeg=myLpms.rUpperLeg->euler_raw;

    //(int) is old-style cast
    int UpperArm_roll=static_cast<int>(EulerEngleUpArm.x());//roll
    int LowerArm_roll=static_cast<int>(EulerEngleLowArm.x());//roll
    int Wrist_roll=static_cast<int>(EulerEngleWrist.x());
    int Neck_roll=static_cast<int>(EulerEngleHead.x());
    int Trunk_roll=static_cast<int>(EulerEngleTrunk.x());
    int Leg_roll=static_cast<int>(EulerEngleLeg.x());


    int AULAScore=0;
    //step AULA
    if(Trunk_roll<5||Trunk_roll>355){
        if( UpperArm_roll>350 || UpperArm_roll<45){
            AULAScore=1;
        }
        else if(UpperArm_roll>=45 && UpperArm_roll<90){
            AULAScore=2;
        }
        else if(UpperArm_roll>=90 && UpperArm_roll<125){
            AULAScore=3;
        }
        else{
            AULAScore=4;
        }
    }
    else if(Trunk_roll<=315 &&Trunk_roll>275){
        if(LowerArm_roll>355 || LowerArm_roll<45){
            AULAScore=2;
        }
        else {
            AULAScore=3;
        }
    }
    else if(Trunk_roll<=275 &&Trunk_roll>180){
        AULAScore=2;
    }
    //undefined
    else
        return 0;

    //ALLA step
    int ALLAScore=0;
    if(Leg_roll<3||Leg_roll>357){
        ALLAScore=2;
    }
    else if(Leg_roll<30&&Leg_roll>=3)
        ALLAScore=3;
    else if(Leg_roll<100&&Leg_roll>=30)
        ALLAScore=4;
    else if(Leg_roll>=100)
        ALLAScore=3;

}

void MainWindow::on_BTN_StartAllLpms_clicked()
{
    std::list<LpmsDevice *>::iterator it;
    for (it = lpmsList.begin(); it != lpmsList.end(); ++it) {
        if((*it)->type=="lUpperArm"){
        }
        else if((*it)->type=="lLowerArm"){
        }
        else if((*it)->type=="rWrist"){
        }
        else if((*it)->type=="lWrist"){
        }
        else if((*it)->type=="lUpperLeg"){
        }
        else if((*it)->type=="rLowerLeg"){
        }
        else if((*it)->type=="lLowerLeg"){
        }
        else{
            lpms_connect(*it);
        }
    }


    dataTimer = new QTimer(this);
    dataTimer->start(20);
    connect(dataTimer,SIGNAL(timeout()),this,SLOT(timer_loop()));

}

void MainWindow::on_BTN_set_origin_clicked()
{
    std::list<LpmsDevice *>::iterator it;
    for (it = lpmsList.begin(); it != lpmsList.end(); ++it) {
        if((*it)->type=="lUpperArm"){
        }
        else if((*it)->type=="lLowerArm"){
        }
        else if((*it)->type=="rWrist"){
        }
        else if((*it)->type=="lWrist"){
        }
        else if((*it)->type=="lUpperLeg"){
        }
        else if((*it)->type=="rLowerLeg"){
        }
        else if((*it)->type=="lLowerLeg"){
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

void MainWindow::on_actionLeft_Upper_Leg_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                "Open LeftUpperLeg",
                                                QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).at(0),
                                                "*.obj");
    qDebug()<<file;
    if(QFile(file).exists())
    {
        std::cout << file.toStdString() << std::endl;
        ui->widget->loadObjFile(file.toStdString(), myLpms.lUpperLeg);
        ActiveModelID=myLpms.lUpperLeg->id;
    }
}

void MainWindow::on_actionLeft_Lower_Leg_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                "Open LeftLowerLeg",
                                                QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).at(0),
                                                "*.obj");
    qDebug()<<file;
    if(QFile(file).exists())
    {
        std::cout << file.toStdString() << std::endl;
        ui->widget->loadObjFile(file.toStdString(), myLpms.lLowerLeg);
        ActiveModelID=myLpms.lLowerLeg->id;
    }
}

void MainWindow::on_actionRight_Upper_Leg_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                "Open RightUpperLeg",
                                                QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).at(0),
                                                "*.obj");
    qDebug()<<file;
    if(QFile(file).exists())
    {
        std::cout << file.toStdString() << std::endl;
        ui->widget->loadObjFile(file.toStdString(), myLpms.rUpperLeg);
        ActiveModelID=myLpms.rUpperLeg->id;
    }
}

void MainWindow::on_actionRight_Lower_Leg_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                "Open RightLowerLeg",
                                                QStandardPaths::standardLocations(QStandardPaths::DesktopLocation).at(0),
                                                "*.obj");
    qDebug()<<file;
    if(QFile(file).exists())
    {
        std::cout << file.toStdString() << std::endl;
        ui->widget->loadObjFile(file.toStdString(), myLpms.rLowerLeg);
        ActiveModelID=myLpms.rLowerLeg->id;
    }
}
