#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <LpmsSensorI.h>
#include <LpmsSensorManagerI.h>
#include <QTimer>
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
struct LpmsDevice{
    const char *address=nullptr;
    int id;
    std::string type;

    QQuaternion quat_raw;
    /*ps1
    QQuaternion quat_ajust;
    QQuaternion quat_ajusted;
    */

    LpmsSensorI *function;
    int viewX=90,viewY=0,viewZ=0;
    struct LpmsDevice *head;
    struct LpmsDevice *body;
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

    static LpmsDevice *LPMS_SEARCH_ID[];
    std::list<LpmsDevice *>lpmsList;
    std::list<LpmsDevice *>::iterator it;

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
    void timer_loop();
    void on_BTN_set_origin_clicked();

    void on_btn_x_plus_clicked();

    void on_btn_y_plus_clicked();

    void on_btn_z_plus_clicked();

    void on_OpenHead_triggered();

    void on_OpenBody_triggered();

private:
    Ui::MainWindow *ui;

    LpmsSensorManagerI *manager;

    QTimer *dataTimer;

    LpmsDevice myLpms,head,body;

    int ActiveModelID=0;


};

#endif // MAINWINDOW_H
