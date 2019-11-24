/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
    QAction *actionLeft_Upper_Leg;
    QAction *actionLeft_Lower_Leg;
    QAction *actionRight_Upper_Leg;
    QAction *actionRight_Lower_Leg;
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
    QRadioButton *load_choose1;
    QRadioButton *load_choose2;
    QRadioButton *load_choose3;
    QRadioButton *load_choose4;
    QCheckBox *check_rula_1;
    QCheckBox *check_rula_2;
    QCheckBox *check_rula_3;
    QCheckBox *check_rula_4;
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1233, 714);
        actionclose = new QAction(MainWindow);
        actionclose->setObjectName(QStringLiteral("actionclose"));
        OpenHead = new QAction(MainWindow);
        OpenHead->setObjectName(QStringLiteral("OpenHead"));
        OpenRightUpperArm = new QAction(MainWindow);
        OpenRightUpperArm->setObjectName(QStringLiteral("OpenRightUpperArm"));
        OpenRightLowerArm = new QAction(MainWindow);
        OpenRightLowerArm->setObjectName(QStringLiteral("OpenRightLowerArm"));
        OpenRightWrist = new QAction(MainWindow);
        OpenRightWrist->setObjectName(QStringLiteral("OpenRightWrist"));
        OpenLeftUpperArm = new QAction(MainWindow);
        OpenLeftUpperArm->setObjectName(QStringLiteral("OpenLeftUpperArm"));
        OpenLeftLowerArm = new QAction(MainWindow);
        OpenLeftLowerArm->setObjectName(QStringLiteral("OpenLeftLowerArm"));
        OpenLeftWrist = new QAction(MainWindow);
        OpenLeftWrist->setObjectName(QStringLiteral("OpenLeftWrist"));
        OpenBody = new QAction(MainWindow);
        OpenBody->setObjectName(QStringLiteral("OpenBody"));
        actionLeft_Upper_Leg = new QAction(MainWindow);
        actionLeft_Upper_Leg->setObjectName(QStringLiteral("actionLeft_Upper_Leg"));
        actionLeft_Lower_Leg = new QAction(MainWindow);
        actionLeft_Lower_Leg->setObjectName(QStringLiteral("actionLeft_Lower_Leg"));
        actionRight_Upper_Leg = new QAction(MainWindow);
        actionRight_Upper_Leg->setObjectName(QStringLiteral("actionRight_Upper_Leg"));
        actionRight_Lower_Leg = new QAction(MainWindow);
        actionRight_Lower_Leg->setObjectName(QStringLiteral("actionRight_Lower_Leg"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        widget = new ThreeDWindow(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(500, 500));

        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        BTN_set_origin = new QPushButton(centralWidget);
        BTN_set_origin->setObjectName(QStringLiteral("BTN_set_origin"));

        horizontalLayout->addWidget(BTN_set_origin);

        btn_x_plus = new QPushButton(centralWidget);
        btn_x_plus->setObjectName(QStringLiteral("btn_x_plus"));

        horizontalLayout->addWidget(btn_x_plus);

        btn_y_plus = new QPushButton(centralWidget);
        btn_y_plus->setObjectName(QStringLiteral("btn_y_plus"));

        horizontalLayout->addWidget(btn_y_plus);

        btn_z_plus = new QPushButton(centralWidget);
        btn_z_plus->setObjectName(QStringLiteral("btn_z_plus"));

        horizontalLayout->addWidget(btn_z_plus);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        BTN_StartAllLpms = new QPushButton(centralWidget);
        BTN_StartAllLpms->setObjectName(QStringLiteral("BTN_StartAllLpms"));

        verticalLayout_3->addWidget(BTN_StartAllLpms);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        load_choose1 = new QRadioButton(centralWidget);
        load_choose1->setObjectName(QStringLiteral("load_choose1"));

        horizontalLayout_2->addWidget(load_choose1);

        load_choose2 = new QRadioButton(centralWidget);
        load_choose2->setObjectName(QStringLiteral("load_choose2"));

        horizontalLayout_2->addWidget(load_choose2);

        load_choose3 = new QRadioButton(centralWidget);
        load_choose3->setObjectName(QStringLiteral("load_choose3"));

        horizontalLayout_2->addWidget(load_choose3);

        load_choose4 = new QRadioButton(centralWidget);
        load_choose4->setObjectName(QStringLiteral("load_choose4"));

        horizontalLayout_2->addWidget(load_choose4);


        verticalLayout_3->addLayout(horizontalLayout_2);

        check_rula_1 = new QCheckBox(centralWidget);
        check_rula_1->setObjectName(QStringLiteral("check_rula_1"));

        verticalLayout_3->addWidget(check_rula_1);

        check_rula_2 = new QCheckBox(centralWidget);
        check_rula_2->setObjectName(QStringLiteral("check_rula_2"));

        verticalLayout_3->addWidget(check_rula_2);

        check_rula_3 = new QCheckBox(centralWidget);
        check_rula_3->setObjectName(QStringLiteral("check_rula_3"));

        verticalLayout_3->addWidget(check_rula_3);

        check_rula_4 = new QCheckBox(centralWidget);
        check_rula_4->setObjectName(QStringLiteral("check_rula_4"));

        verticalLayout_3->addWidget(check_rula_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        Label_WristArmScore = new QLabel(centralWidget);
        Label_WristArmScore->setObjectName(QStringLiteral("Label_WristArmScore"));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Devanagari"));
        font.setPointSize(20);
        Label_WristArmScore->setFont(font);

        horizontalLayout_3->addWidget(Label_WristArmScore);


        verticalLayout_3->addLayout(horizontalLayout_3);

        textbrowser = new QTextBrowser(centralWidget);
        textbrowser->setObjectName(QStringLiteral("textbrowser"));

        verticalLayout_3->addWidget(textbrowser);


        horizontalLayout_4->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1233, 25));
        menuwindow = new QMenu(menuBar);
        menuwindow->setObjectName(QStringLiteral("menuwindow"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
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
        menuwindow->addAction(actionLeft_Upper_Leg);
        menuwindow->addAction(actionLeft_Lower_Leg);
        menuwindow->addAction(actionRight_Upper_Leg);
        menuwindow->addAction(actionRight_Lower_Leg);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionclose->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        OpenHead->setText(QApplication::translate("MainWindow", "Head", Q_NULLPTR));
        OpenRightUpperArm->setText(QApplication::translate("MainWindow", "Right Upper Arm", Q_NULLPTR));
        OpenRightLowerArm->setText(QApplication::translate("MainWindow", "Right Lower Arm", Q_NULLPTR));
        OpenRightWrist->setText(QApplication::translate("MainWindow", "Right Wrist", Q_NULLPTR));
        OpenLeftUpperArm->setText(QApplication::translate("MainWindow", "Left Upper Arm", Q_NULLPTR));
        OpenLeftLowerArm->setText(QApplication::translate("MainWindow", "Left Lower Arm", Q_NULLPTR));
        OpenLeftWrist->setText(QApplication::translate("MainWindow", "Left Wrist", Q_NULLPTR));
        OpenBody->setText(QApplication::translate("MainWindow", "Body", Q_NULLPTR));
        actionLeft_Upper_Leg->setText(QApplication::translate("MainWindow", "Left Upper Leg", Q_NULLPTR));
        actionLeft_Lower_Leg->setText(QApplication::translate("MainWindow", "Left Lower Leg", Q_NULLPTR));
        actionRight_Upper_Leg->setText(QApplication::translate("MainWindow", "Right Upper Leg", Q_NULLPTR));
        actionRight_Lower_Leg->setText(QApplication::translate("MainWindow", "Right Lower Leg", Q_NULLPTR));
        BTN_set_origin->setText(QApplication::translate("MainWindow", "Set Origin", Q_NULLPTR));
        btn_x_plus->setText(QApplication::translate("MainWindow", "X+90", Q_NULLPTR));
        btn_y_plus->setText(QApplication::translate("MainWindow", "Y+90", Q_NULLPTR));
        btn_z_plus->setText(QApplication::translate("MainWindow", "Z+90", Q_NULLPTR));
        BTN_StartAllLpms->setText(QApplication::translate("MainWindow", "Connect All", Q_NULLPTR));
        load_choose1->setText(QApplication::translate("MainWindow", "<2 kg", Q_NULLPTR));
        load_choose2->setText(QApplication::translate("MainWindow", "2~10 kg intermittent", Q_NULLPTR));
        load_choose3->setText(QApplication::translate("MainWindow", "2~10 kg repeated", Q_NULLPTR));
        load_choose4->setText(QApplication::translate("MainWindow", ">10 kg", Q_NULLPTR));
        check_rula_1->setText(QApplication::translate("MainWindow", "shoulder is raised", Q_NULLPTR));
        check_rula_2->setText(QApplication::translate("MainWindow", "upper arm is abducted", Q_NULLPTR));
        check_rula_3->setText(QApplication::translate("MainWindow", "arm is supported or person is leaning", Q_NULLPTR));
        check_rula_4->setText(QApplication::translate("MainWindow", "hold > 10 mins or 4 times/min", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Wrist & Arm Score", Q_NULLPTR));
        Label_WristArmScore->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        menuwindow->setTitle(QApplication::translate("MainWindow", "window", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
