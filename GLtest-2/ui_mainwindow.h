/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "threedwindow.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionclose;
    QAction *OpenHead;
    QAction *OpenRightUpperArm;
    QAction *OpenRightLowerArm;
    QAction *OpenRightWrist;
    QAction *OpenLeftUpperArm;
    QAction *OpenLeftLowerArm;
    QAction *OpenLeftWrist;
    QAction *OpenBody;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    ThreeDWindow *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *BTN_set_origin;
    QPushButton *btn_x_plus;
    QPushButton *btn_y_plus;
    QPushButton *btn_z_plus;
    QVBoxLayout *verticalLayout_3;
    QPushButton *BTN_StartAllLpms;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *load_choose3;
    QRadioButton *load_choose2;
    QRadioButton *load_choose1;
    QCheckBox *check_rula_2;
    QCheckBox *check_rula_3;
    QCheckBox *check_rula_1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *Label_WristArmScore;
    QTextBrowser *textbrowser;
    QMenuBar *menuBar;
    QMenu *menuwindow;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1233, 714);
        actionclose = new QAction(MainWindow);
        actionclose->setObjectName(QString::fromUtf8("actionclose"));
        OpenHead = new QAction(MainWindow);
        OpenHead->setObjectName(QString::fromUtf8("OpenHead"));
        OpenRightUpperArm = new QAction(MainWindow);
        OpenRightUpperArm->setObjectName(QString::fromUtf8("OpenRightUpperArm"));
        OpenRightLowerArm = new QAction(MainWindow);
        OpenRightLowerArm->setObjectName(QString::fromUtf8("OpenRightLowerArm"));
        OpenRightWrist = new QAction(MainWindow);
        OpenRightWrist->setObjectName(QString::fromUtf8("OpenRightWrist"));
        OpenLeftUpperArm = new QAction(MainWindow);
        OpenLeftUpperArm->setObjectName(QString::fromUtf8("OpenLeftUpperArm"));
        OpenLeftLowerArm = new QAction(MainWindow);
        OpenLeftLowerArm->setObjectName(QString::fromUtf8("OpenLeftLowerArm"));
        OpenLeftWrist = new QAction(MainWindow);
        OpenLeftWrist->setObjectName(QString::fromUtf8("OpenLeftWrist"));
        OpenBody = new QAction(MainWindow);
        OpenBody->setObjectName(QString::fromUtf8("OpenBody"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        widget = new ThreeDWindow(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(500, 500));

        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        BTN_set_origin = new QPushButton(centralWidget);
        BTN_set_origin->setObjectName(QString::fromUtf8("BTN_set_origin"));

        horizontalLayout->addWidget(BTN_set_origin);

        btn_x_plus = new QPushButton(centralWidget);
        btn_x_plus->setObjectName(QString::fromUtf8("btn_x_plus"));

        horizontalLayout->addWidget(btn_x_plus);

        btn_y_plus = new QPushButton(centralWidget);
        btn_y_plus->setObjectName(QString::fromUtf8("btn_y_plus"));

        horizontalLayout->addWidget(btn_y_plus);

        btn_z_plus = new QPushButton(centralWidget);
        btn_z_plus->setObjectName(QString::fromUtf8("btn_z_plus"));

        horizontalLayout->addWidget(btn_z_plus);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        BTN_StartAllLpms = new QPushButton(centralWidget);
        BTN_StartAllLpms->setObjectName(QString::fromUtf8("BTN_StartAllLpms"));

        verticalLayout_3->addWidget(BTN_StartAllLpms);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        load_choose3 = new QRadioButton(centralWidget);
        load_choose3->setObjectName(QString::fromUtf8("load_choose3"));

        horizontalLayout_2->addWidget(load_choose3);

        load_choose2 = new QRadioButton(centralWidget);
        load_choose2->setObjectName(QString::fromUtf8("load_choose2"));

        horizontalLayout_2->addWidget(load_choose2);

        load_choose1 = new QRadioButton(centralWidget);
        load_choose1->setObjectName(QString::fromUtf8("load_choose1"));

        horizontalLayout_2->addWidget(load_choose1);


        verticalLayout_3->addLayout(horizontalLayout_2);

        check_rula_2 = new QCheckBox(centralWidget);
        check_rula_2->setObjectName(QString::fromUtf8("check_rula_2"));

        verticalLayout_3->addWidget(check_rula_2);

        check_rula_3 = new QCheckBox(centralWidget);
        check_rula_3->setObjectName(QString::fromUtf8("check_rula_3"));

        verticalLayout_3->addWidget(check_rula_3);

        check_rula_1 = new QCheckBox(centralWidget);
        check_rula_1->setObjectName(QString::fromUtf8("check_rula_1"));

        verticalLayout_3->addWidget(check_rula_1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        Label_WristArmScore = new QLabel(centralWidget);
        Label_WristArmScore->setObjectName(QString::fromUtf8("Label_WristArmScore"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font.setPointSize(20);
        Label_WristArmScore->setFont(font);

        horizontalLayout_3->addWidget(Label_WristArmScore);


        verticalLayout_3->addLayout(horizontalLayout_3);

        textbrowser = new QTextBrowser(centralWidget);
        textbrowser->setObjectName(QString::fromUtf8("textbrowser"));

        verticalLayout_3->addWidget(textbrowser);


        horizontalLayout_4->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1233, 24));
        menuwindow = new QMenu(menuBar);
        menuwindow->setObjectName(QString::fromUtf8("menuwindow"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuwindow->menuAction());
        menuwindow->addAction(actionclose);
        menuwindow->addSeparator();
        menuwindow->addAction(OpenHead);
        menuwindow->addAction(OpenRightUpperArm);
        menuwindow->addAction(OpenRightLowerArm);
        menuwindow->addAction(OpenRightWrist);
        menuwindow->addAction(OpenLeftUpperArm);
        menuwindow->addAction(OpenLeftLowerArm);
        menuwindow->addAction(OpenLeftWrist);
        menuwindow->addAction(OpenBody);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionclose->setText(QApplication::translate("MainWindow", "Close", nullptr));
        OpenHead->setText(QApplication::translate("MainWindow", "Head", nullptr));
        OpenRightUpperArm->setText(QApplication::translate("MainWindow", "Right Upper Arm", nullptr));
        OpenRightLowerArm->setText(QApplication::translate("MainWindow", "Right Lower Arm", nullptr));
        OpenRightWrist->setText(QApplication::translate("MainWindow", "Right Wrist", nullptr));
        OpenLeftUpperArm->setText(QApplication::translate("MainWindow", "Left Upper Arm", nullptr));
        OpenLeftLowerArm->setText(QApplication::translate("MainWindow", "Left Lower Arm", nullptr));
        OpenLeftWrist->setText(QApplication::translate("MainWindow", "Left Wrist", nullptr));
        OpenBody->setText(QApplication::translate("MainWindow", "Body", nullptr));
        BTN_set_origin->setText(QApplication::translate("MainWindow", "Set Origin", nullptr));
        btn_x_plus->setText(QApplication::translate("MainWindow", "X+90", nullptr));
        btn_y_plus->setText(QApplication::translate("MainWindow", "Y+90", nullptr));
        btn_z_plus->setText(QApplication::translate("MainWindow", "Z+90", nullptr));
        BTN_StartAllLpms->setText(QApplication::translate("MainWindow", "Connect All", nullptr));
        load_choose3->setText(QApplication::translate("MainWindow", ">10 kg", nullptr));
        load_choose2->setText(QApplication::translate("MainWindow", "2~10 kg", nullptr));
        load_choose1->setText(QApplication::translate("MainWindow", "<2 kg", nullptr));
        check_rula_2->setText(QApplication::translate("MainWindow", "upper arm is abducted", nullptr));
        check_rula_3->setText(QApplication::translate("MainWindow", "arm is supported or person is leaning", nullptr));
        check_rula_1->setText(QApplication::translate("MainWindow", "shoulder is raised", nullptr));
        label->setText(QApplication::translate("MainWindow", "Wrist & Arm Score", nullptr));
        Label_WristArmScore->setText(QApplication::translate("MainWindow", "0", nullptr));
        menuwindow->setTitle(QApplication::translate("MainWindow", "window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
