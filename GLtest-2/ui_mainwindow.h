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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
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
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFormLayout *formLayout;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QCheckBox *check_rula_1;
    QCheckBox *check_rula_2;
    QCheckBox *check_rula_3;
    QLabel *label_8;
    QCheckBox *check_rula_4;
    QCheckBox *check_rula_5;
    QLabel *label_2;
    QRadioButton *load_choose1;
    QRadioButton *load_choose2;
    QRadioButton *load_choose3;
    QWidget *tab_2;
    QFormLayout *formLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *reba_weight1;
    QRadioButton *reba_weight2;
    QRadioButton *reba_weight3;
    QLabel *label_5;
    QCheckBox *check_reba_1;
    QCheckBox *check_reba_2;
    QCheckBox *check_reba_3;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_4;
    QRadioButton *Cp4;
    QRadioButton *Cp1;
    QRadioButton *Cp2;
    QRadioButton *Cp3;
    QLabel *label_7;
    QCheckBox *check_reba_act1;
    QCheckBox *check_reba_act2;
    QCheckBox *check_reba_act3;
    QWidget *tab_3;
    QWidget *tab_4;
    QTextBrowser *textbrowser;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLabel *Label_Score;
    QGridLayout *gridLayout_2;
    ThreeDWindow *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *BTN_set_origin;
    QPushButton *BTN_StartAllLpms;
    QGroupBox *groupBox;
    QPushButton *btn_x_plus;
    QPushButton *btn_y_plus;
    QPushButton *btn_z_plus;
    QMenuBar *menuBar;
    QMenu *menuwindow;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1163, 723);
        MainWindow->setStyleSheet(QStringLiteral(""));
        actionclose = new QAction(MainWindow);
        actionclose->setObjectName(QStringLiteral("actionclose"));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Devanagari"));
        font.setPointSize(10);
        actionclose->setFont(font);
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
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, 0, -1);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font1;
        font1.setFamily(QStringLiteral("Adobe Devanagari"));
        font1.setPointSize(14);
        tabWidget->setFont(font1);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        formLayout = new QFormLayout(tab);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font2;
        font2.setFamily(QStringLiteral("Adobe Devanagari"));
        font2.setPointSize(16);
        label_3->setFont(font2);

        verticalLayout_2->addWidget(label_3);

        check_rula_1 = new QCheckBox(tab);
        check_rula_1->setObjectName(QStringLiteral("check_rula_1"));
        QFont font3;
        font3.setFamily(QStringLiteral("Adobe Devanagari"));
        font3.setPointSize(12);
        check_rula_1->setFont(font3);

        verticalLayout_2->addWidget(check_rula_1);

        check_rula_2 = new QCheckBox(tab);
        check_rula_2->setObjectName(QStringLiteral("check_rula_2"));
        check_rula_2->setFont(font3);

        verticalLayout_2->addWidget(check_rula_2);

        check_rula_3 = new QCheckBox(tab);
        check_rula_3->setObjectName(QStringLiteral("check_rula_3"));
        check_rula_3->setFont(font3);

        verticalLayout_2->addWidget(check_rula_3);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        check_rula_4 = new QCheckBox(tab);
        check_rula_4->setObjectName(QStringLiteral("check_rula_4"));
        check_rula_4->setFont(font3);

        verticalLayout_2->addWidget(check_rula_4);

        check_rula_5 = new QCheckBox(tab);
        check_rula_5->setObjectName(QStringLiteral("check_rula_5"));
        check_rula_5->setFont(font3);

        verticalLayout_2->addWidget(check_rula_5);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font2);

        verticalLayout_2->addWidget(label_2);

        load_choose1 = new QRadioButton(tab);
        load_choose1->setObjectName(QStringLiteral("load_choose1"));
        load_choose1->setFont(font3);

        verticalLayout_2->addWidget(load_choose1);

        load_choose2 = new QRadioButton(tab);
        load_choose2->setObjectName(QStringLiteral("load_choose2"));
        load_choose2->setFont(font3);

        verticalLayout_2->addWidget(load_choose2);

        load_choose3 = new QRadioButton(tab);
        load_choose3->setObjectName(QStringLiteral("load_choose3"));
        load_choose3->setFont(font3);

        verticalLayout_2->addWidget(load_choose3);


        gridLayout_4->addLayout(verticalLayout_2, 0, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::LabelRole, gridLayout_4);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        formLayout_2 = new QFormLayout(tab_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        reba_weight1 = new QRadioButton(groupBox_2);
        reba_weight1->setObjectName(QStringLiteral("reba_weight1"));
        QFont font4;
        font4.setPointSize(12);
        reba_weight1->setFont(font4);

        verticalLayout_4->addWidget(reba_weight1);

        reba_weight2 = new QRadioButton(groupBox_2);
        reba_weight2->setObjectName(QStringLiteral("reba_weight2"));
        reba_weight2->setFont(font4);

        verticalLayout_4->addWidget(reba_weight2);

        reba_weight3 = new QRadioButton(groupBox_2);
        reba_weight3->setObjectName(QStringLiteral("reba_weight3"));
        reba_weight3->setFont(font4);

        verticalLayout_4->addWidget(reba_weight3);


        verticalLayout->addWidget(groupBox_2);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font2);

        verticalLayout->addWidget(label_5);

        check_reba_1 = new QCheckBox(tab_2);
        check_reba_1->setObjectName(QStringLiteral("check_reba_1"));
        check_reba_1->setFont(font4);

        verticalLayout->addWidget(check_reba_1);

        check_reba_2 = new QCheckBox(tab_2);
        check_reba_2->setObjectName(QStringLiteral("check_reba_2"));
        check_reba_2->setFont(font4);

        verticalLayout->addWidget(check_reba_2);

        check_reba_3 = new QCheckBox(tab_2);
        check_reba_3->setObjectName(QStringLiteral("check_reba_3"));
        check_reba_3->setFont(font4);

        verticalLayout->addWidget(check_reba_3);

        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        formLayout_4 = new QFormLayout(groupBox_3);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        Cp4 = new QRadioButton(groupBox_3);
        Cp4->setObjectName(QStringLiteral("Cp4"));
        Cp4->setFont(font4);

        formLayout_4->setWidget(5, QFormLayout::LabelRole, Cp4);

        Cp1 = new QRadioButton(groupBox_3);
        Cp1->setObjectName(QStringLiteral("Cp1"));
        Cp1->setFont(font4);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, Cp1);

        Cp2 = new QRadioButton(groupBox_3);
        Cp2->setObjectName(QStringLiteral("Cp2"));
        Cp2->setFont(font4);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, Cp2);

        Cp3 = new QRadioButton(groupBox_3);
        Cp3->setObjectName(QStringLiteral("Cp3"));
        Cp3->setFont(font4);

        formLayout_4->setWidget(2, QFormLayout::LabelRole, Cp3);


        verticalLayout->addWidget(groupBox_3);

        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font2);

        verticalLayout->addWidget(label_7);

        check_reba_act1 = new QCheckBox(tab_2);
        check_reba_act1->setObjectName(QStringLiteral("check_reba_act1"));
        check_reba_act1->setFont(font4);

        verticalLayout->addWidget(check_reba_act1);

        check_reba_act2 = new QCheckBox(tab_2);
        check_reba_act2->setObjectName(QStringLiteral("check_reba_act2"));
        check_reba_act2->setFont(font4);

        verticalLayout->addWidget(check_reba_act2);

        check_reba_act3 = new QCheckBox(tab_2);
        check_reba_act3->setObjectName(QStringLiteral("check_reba_act3"));
        check_reba_act3->setFont(font4);

        verticalLayout->addWidget(check_reba_act3);


        formLayout_2->setLayout(0, QFormLayout::SpanningRole, verticalLayout);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        textbrowser = new QTextBrowser(tab_4);
        textbrowser->setObjectName(QStringLiteral("textbrowser"));
        textbrowser->setGeometry(QRect(50, 60, 349, 446));
        tabWidget->addTab(tab_4, QString());

        verticalLayout_3->addWidget(tabWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 20, -1, -1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font2);

        horizontalLayout_5->addWidget(label);

        Label_Score = new QLabel(centralWidget);
        Label_Score->setObjectName(QStringLiteral("Label_Score"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Label_Score->sizePolicy().hasHeightForWidth());
        Label_Score->setSizePolicy(sizePolicy1);
        QFont font5;
        font5.setFamily(QStringLiteral("Adobe Devanagari"));
        font5.setPointSize(18);
        Label_Score->setFont(font5);

        horizontalLayout_5->addWidget(Label_Score);


        horizontalLayout_4->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_3, 0, 4, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        widget = new ThreeDWindow(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(500, 500));

        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        BTN_set_origin = new QPushButton(centralWidget);
        BTN_set_origin->setObjectName(QStringLiteral("BTN_set_origin"));

        horizontalLayout->addWidget(BTN_set_origin);

        BTN_StartAllLpms = new QPushButton(centralWidget);
        BTN_StartAllLpms->setObjectName(QStringLiteral("BTN_StartAllLpms"));

        horizontalLayout->addWidget(BTN_StartAllLpms);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        btn_x_plus = new QPushButton(groupBox);
        btn_x_plus->setObjectName(QStringLiteral("btn_x_plus"));
        btn_x_plus->setGeometry(QRect(10, 0, 115, 24));
        btn_y_plus = new QPushButton(groupBox);
        btn_y_plus->setObjectName(QStringLiteral("btn_y_plus"));
        btn_y_plus->setGeometry(QRect(80, 0, 145, 24));
        btn_z_plus = new QPushButton(groupBox);
        btn_z_plus->setObjectName(QStringLiteral("btn_z_plus"));
        btn_z_plus->setGeometry(QRect(170, 0, 196, 24));

        horizontalLayout->addWidget(groupBox);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1163, 27));
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

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ergonomic-X", Q_NULLPTR));
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
        label_3->setText(QApplication::translate("MainWindow", "Detail Confuguration:", Q_NULLPTR));
        check_rula_1->setText(QApplication::translate("MainWindow", "shoulder is raised", Q_NULLPTR));
        check_rula_2->setText(QApplication::translate("MainWindow", "upper arm is abducted", Q_NULLPTR));
        check_rula_3->setText(QApplication::translate("MainWindow", "arm is supported or person is leaning", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Muscle Use", Q_NULLPTR));
        check_rula_4->setText(QApplication::translate("MainWindow", "hold > 10 mins or 4 times/min", Q_NULLPTR));
        check_rula_5->setText(QApplication::translate("MainWindow", "the legs are supported", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Weight of Object:", Q_NULLPTR));
        load_choose1->setText(QApplication::translate("MainWindow", "<2 kg", Q_NULLPTR));
        load_choose2->setText(QApplication::translate("MainWindow", "2~10 kg", Q_NULLPTR));
        load_choose3->setText(QApplication::translate("MainWindow", ">10 kg", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "RULA", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Weight of Object", Q_NULLPTR));
        reba_weight1->setText(QApplication::translate("MainWindow", "<5 kg", Q_NULLPTR));
        reba_weight2->setText(QApplication::translate("MainWindow", "5~10 kg", Q_NULLPTR));
        reba_weight3->setText(QApplication::translate("MainWindow", ">10 kg", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Details of Arms:", Q_NULLPTR));
        check_reba_1->setText(QApplication::translate("MainWindow", "Shoulder is raised.", Q_NULLPTR));
        check_reba_2->setText(QApplication::translate("MainWindow", "Upper arm is abducted.", Q_NULLPTR));
        check_reba_3->setText(QApplication::translate("MainWindow", "Arm is supported or person is leaning.", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Coulping of Hand Hold Score", Q_NULLPTR));
        Cp4->setText(QApplication::translate("MainWindow", "Unacceptable", Q_NULLPTR));
        Cp1->setText(QApplication::translate("MainWindow", "Fitting handle", Q_NULLPTR));
        Cp2->setText(QApplication::translate("MainWindow", "Acceptable but nit ideal hold", Q_NULLPTR));
        Cp3->setText(QApplication::translate("MainWindow", "Not acceptable but possible", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Activity Score", Q_NULLPTR));
        check_reba_act1->setText(QApplication::translate("MainWindow", "1 or more body parts are held for longer than 1 minute.", Q_NULLPTR));
        check_reba_act2->setText(QApplication::translate("MainWindow", "Repeated small range actions (more than 4x per minute).", Q_NULLPTR));
        check_reba_act3->setText(QApplication::translate("MainWindow", "Action causes rapid large range changes in postures or unstable base.", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "REBA", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "AWBA", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Debug", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "RULA Score : ", Q_NULLPTR));
        Label_Score->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        BTN_set_origin->setText(QApplication::translate("MainWindow", "Set Origin", Q_NULLPTR));
        BTN_StartAllLpms->setText(QApplication::translate("MainWindow", "Connect All", Q_NULLPTR));
        groupBox->setTitle(QString());
        btn_x_plus->setText(QApplication::translate("MainWindow", "X+90", Q_NULLPTR));
        btn_y_plus->setText(QApplication::translate("MainWindow", "Y+90", Q_NULLPTR));
        btn_z_plus->setText(QApplication::translate("MainWindow", "Z+90", Q_NULLPTR));
        menuwindow->setTitle(QApplication::translate("MainWindow", "Load Model", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
