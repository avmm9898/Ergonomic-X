#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <LpmsSensorI.h>
#include <LpmsSensorManagerI.h>
#include <QTimer>
#include <QtMath>
#include <QString>
#include <QQuaternion>
#include <QFileDialog>
#include <QDir>
#include <QStandardPaths>
#include <QSettings>
#include "ThreeDWindow.h"

namespace Ui {
class MainWindow;
}

//宣告在class外面，其他class才能使用此struct
struct LpmsDevice{
    const char *address=nullptr;
    int id;
    std::string type;

    QQuaternion quat_raw;
    QVector3D euler_raw;
    /*ps1
    QQuaternion quat_ajust;
    QQuaternion quat_ajusted;
    */

    LpmsSensorI *function;
    int viewX=0,viewY=0,viewZ=90;
    struct LpmsDevice *head;
    struct LpmsDevice *body;
    struct LpmsDevice *rUpperArm;
    struct LpmsDevice *rLowerArm;
    struct LpmsDevice *rWrist;
    struct LpmsDevice *lUpperArm;
    struct LpmsDevice *lLowerArm;
    struct LpmsDevice *lWrist;
    struct LpmsDevice *rUpperLeg;
    struct LpmsDevice *rLowerLeg;
    struct LpmsDevice *lUpperLeg;
    struct LpmsDevice *lLowerLeg;

    LpmsDevice *getme(void){
        return this;
    }
};



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static std::list<LpmsDevice *>lpmsList;


protected:


signals:
    void send_thread_start();    //發出啟動訊號
    void send_thread_exit();     //發出結束訊號

private slots:
    void on_actionclose_triggered();
    void on_BTN_StartAllLpms_clicked();

    void data_display(LpmsDevice *);
    void data_receive(LpmsDevice *);
    void lpms_connect(LpmsDevice *);
    int rula_calc();
    int reba_calc();
    int awba_calc();
    void timer_loop();
    void on_BTN_set_origin_clicked();

    void on_btn_x_plus_clicked();

    void on_btn_y_plus_clicked();

    void on_btn_z_plus_clicked();

    void on_OpenHead_triggered();

    void on_OpenBody_triggered();

    void on_OpenRightUpperArm_triggered();

    void on_OpenRightLowerArm_triggered();

    void on_OpenRightWrist_triggered();

    void on_actionLeft_Upper_Leg_triggered();

    void on_actionLeft_Lower_Leg_triggered();

    void on_actionRight_Upper_Leg_triggered();

    void on_actionRight_Lower_Leg_triggered();

    void on_check_manual_clicked();

private:
    Ui::MainWindow *ui;

    LpmsSensorManagerI *manager;

    QTimer *dataTimer;

    LpmsDevice myLpms,head,body,rUpperArm,rLowerArm,rWrist;
    LpmsDevice lUpperArm,lLowerArm,lWrist;
    LpmsDevice lUpperLeg,lLowerLeg,rUpperLeg,rLowerLeg;

    int ActiveModelID=0;


};

#endif // MAINWINDOW_H
