/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave_txt;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_readData;
    QPushButton *pushButton_clear;
    QGroupBox *groupBox_2;
    QLabel *label_7;
    QPushButton *pushButton_velocity;
    QLineEdit *lineEdit_setpoint;
    QPushButton *pushButton_position;
    QGroupBox *groupBox_4;
    QPushButton *pushButton_disconnect;
    QLabel *label_2;
    QComboBox *comboBox_COM;
    QComboBox *comboBox_Baud;
    QLabel *label_6;
    QPushButton *Select_COM;
    QPushButton *pushButton_reload;
    QLabel *label_status_com;
    QGroupBox *groupBox_5;
    QPushButton *pushButton_reset;
    QPushButton *pushButton_run;
    QGroupBox *groupBox_3;
    QLabel *label_Kd;
    QLineEdit *lineEdit_Kp;
    QLineEdit *lineEdit_Ki;
    QLabel *label_Kp;
    QLineEdit *lineEdit_Kd;
    QLabel *label_Ki;
    QPushButton *sendPID;
    QPushButton *PID2;
    QPushButton *PID1;
    QGroupBox *groupBox_7;
    QTextBrowser *textBrowser_command;
    QPushButton *pushButton_clear_2;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGroupBox *groupBox_6;
    QCustomPlot *customPlot1;
    QPushButton *pushButton_plot;
    QPushButton *pushButton_clearGraph;
    QWidget *tab_4;
    QGroupBox *groupBox_8;
    QCustomPlot *customPlot2;
    QPushButton *pushButton_plot_2;
    QPushButton *pushButton_clearGraph_2;
    QMenuBar *menubar;
    QMenu *menuPID;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1592, 759);
        actionSave_txt = new QAction(MainWindow);
        actionSave_txt->setObjectName(QString::fromUtf8("actionSave_txt"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/save_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_txt->setIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 160, 341, 321));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 250, 255);"));
        groupBox->setFlat(false);
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 30, 311, 241));
        textBrowser->setFrameShape(QFrame::Panel);
        textBrowser->setFrameShadow(QFrame::Plain);
        pushButton_readData = new QPushButton(groupBox);
        pushButton_readData->setObjectName(QString::fromUtf8("pushButton_readData"));
        pushButton_readData->setGeometry(QRect(20, 280, 111, 31));
        pushButton_readData->setFont(font);
        pushButton_clear = new QPushButton(groupBox);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(230, 280, 91, 31));
        pushButton_clear->setFont(font);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(350, 480, 331, 181));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(242, 245, 255);"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 30, 81, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Comic Sans MS"));
        font1.setPointSize(9);
        label_7->setFont(font1);
        pushButton_velocity = new QPushButton(groupBox_2);
        pushButton_velocity->setObjectName(QString::fromUtf8("pushButton_velocity"));
        pushButton_velocity->setGeometry(QRect(100, 120, 181, 41));
        pushButton_velocity->setFont(font1);
        pushButton_velocity->setStyleSheet(QString::fromUtf8("color: rgb(0, 150, 0);"));
        lineEdit_setpoint = new QLineEdit(groupBox_2);
        lineEdit_setpoint->setObjectName(QString::fromUtf8("lineEdit_setpoint"));
        lineEdit_setpoint->setGeometry(QRect(98, 30, 181, 31));
        pushButton_position = new QPushButton(groupBox_2);
        pushButton_position->setObjectName(QString::fromUtf8("pushButton_position"));
        pushButton_position->setGeometry(QRect(100, 70, 181, 41));
        pushButton_position->setFont(font1);
        pushButton_position->setStyleSheet(QString::fromUtf8("color: rgb(0, 150, 0);"));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 10, 351, 151));
        groupBox_4->setFont(font);
        groupBox_4->setAutoFillBackground(false);
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(229, 235, 255);"));
        groupBox_4->setFlat(false);
        groupBox_4->setCheckable(false);
        pushButton_disconnect = new QPushButton(groupBox_4);
        pushButton_disconnect->setObjectName(QString::fromUtf8("pushButton_disconnect"));
        pushButton_disconnect->setGeometry(QRect(230, 70, 111, 31));
        pushButton_disconnect->setFont(font);
        pushButton_disconnect->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 30, 51, 21));
        label_2->setFont(font1);
        comboBox_COM = new QComboBox(groupBox_4);
        comboBox_COM->setObjectName(QString::fromUtf8("comboBox_COM"));
        comboBox_COM->setGeometry(QRect(90, 30, 111, 31));
        comboBox_Baud = new QComboBox(groupBox_4);
        comboBox_Baud->setObjectName(QString::fromUtf8("comboBox_Baud"));
        comboBox_Baud->setGeometry(QRect(90, 70, 111, 31));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 70, 81, 21));
        label_6->setFont(font1);
        Select_COM = new QPushButton(groupBox_4);
        Select_COM->setObjectName(QString::fromUtf8("Select_COM"));
        Select_COM->setGeometry(QRect(230, 30, 111, 31));
        Select_COM->setFont(font);
        Select_COM->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        pushButton_reload = new QPushButton(groupBox_4);
        pushButton_reload->setObjectName(QString::fromUtf8("pushButton_reload"));
        pushButton_reload->setGeometry(QRect(230, 110, 111, 31));
        pushButton_reload->setFont(font);
        pushButton_reload->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 127);"));
        label_status_com = new QLabel(groupBox_4);
        label_status_com->setObjectName(QString::fromUtf8("label_status_com"));
        label_status_com->setGeometry(QRect(90, 110, 121, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Comic Sans MS"));
        font2.setPointSize(10);
        label_status_com->setFont(font2);
        label_status_com->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 480, 341, 181));
        groupBox_5->setFont(font);
        groupBox_5->setStyleSheet(QString::fromUtf8("background-color: rgb(244, 244, 255);"));
        pushButton_reset = new QPushButton(groupBox_5);
        pushButton_reset->setObjectName(QString::fromUtf8("pushButton_reset"));
        pushButton_reset->setGeometry(QRect(170, 50, 161, 81));
        QFont font3;
        font3.setFamily(QString::fromUtf8("VNI-Korin"));
        font3.setPointSize(14);
        font3.setBold(true);
        pushButton_reset->setFont(font3);
        pushButton_reset->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #9999aa;\n"
"	border-radius: 10px;\n"
"	color: white;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 0, 55, 55), stop:1 rgba(155, 155, 155,155));\n"
"}\n"
"\n"
"QPushButton:enabled {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #fffffe;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(255, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}\n"
""));
        QIcon icon1;
        QString iconThemeName = QString::fromUtf8("applications-games");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        pushButton_reset->setIcon(icon1);
        pushButton_run = new QPushButton(groupBox_5);
        pushButton_run->setObjectName(QString::fromUtf8("pushButton_run"));
        pushButton_run->setGeometry(QRect(10, 50, 151, 81));
        pushButton_run->setFont(font3);
        pushButton_run->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-style: solid;\n"
"	border-width: 2px;\n"
"	border-color: #9999aa;\n"
"	border-radius: 10px;\n"
"	color: white;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 0, 55, 55), stop:1 rgba(155, 155, 155,155));\n"
"}\n"
"\n"
"QPushButton:enabled {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: white;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(0, 255, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #fffffe;\n"
"}\n"
"\n"
"\n"
"QPushButton:hover:!pressed {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, stop:0 rgba(255, 0, 255, 255), stop:1 rgba(255, 255, 255, 255));\n"
"		color: #0c2f70;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"		background-color: #aaaaaa;\n"
"		color: #ffffff;\n"
"}\n"
""));
        pushButton_run->setIcon(icon1);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(360, 10, 321, 151));
        groupBox_3->setFont(font);
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(229, 235, 255);\n"
""));
        groupBox_3->setFlat(false);
        label_Kd = new QLabel(groupBox_3);
        label_Kd->setObjectName(QString::fromUtf8("label_Kd"));
        label_Kd->setGeometry(QRect(30, 110, 31, 21));
        label_Kd->setFont(font1);
        lineEdit_Kp = new QLineEdit(groupBox_3);
        lineEdit_Kp->setObjectName(QString::fromUtf8("lineEdit_Kp"));
        lineEdit_Kp->setGeometry(QRect(70, 30, 111, 31));
        lineEdit_Kp->setStyleSheet(QString::fromUtf8(""));
        lineEdit_Ki = new QLineEdit(groupBox_3);
        lineEdit_Ki->setObjectName(QString::fromUtf8("lineEdit_Ki"));
        lineEdit_Ki->setGeometry(QRect(70, 70, 111, 31));
        lineEdit_Ki->setMaxLength(32767);
        lineEdit_Ki->setDragEnabled(false);
        label_Kp = new QLabel(groupBox_3);
        label_Kp->setObjectName(QString::fromUtf8("label_Kp"));
        label_Kp->setGeometry(QRect(30, 30, 31, 21));
        label_Kp->setFont(font1);
        label_Kp->setMouseTracking(false);
        label_Kp->setTabletTracking(false);
        label_Kp->setContextMenuPolicy(Qt::DefaultContextMenu);
        label_Kp->setAutoFillBackground(false);
        label_Kp->setFrameShape(QFrame::NoFrame);
        label_Kp->setFrameShadow(QFrame::Plain);
        label_Kp->setLineWidth(1);
        lineEdit_Kd = new QLineEdit(groupBox_3);
        lineEdit_Kd->setObjectName(QString::fromUtf8("lineEdit_Kd"));
        lineEdit_Kd->setGeometry(QRect(70, 110, 111, 31));
        label_Ki = new QLabel(groupBox_3);
        label_Ki->setObjectName(QString::fromUtf8("label_Ki"));
        label_Ki->setGeometry(QRect(30, 70, 31, 21));
        label_Ki->setFont(font1);
        sendPID = new QPushButton(groupBox_3);
        sendPID->setObjectName(QString::fromUtf8("sendPID"));
        sendPID->setGeometry(QRect(190, 90, 121, 51));
        sendPID->setFont(font);
        sendPID->setStyleSheet(QString::fromUtf8("color: rgb(140, 0, 255);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("C:/Users/Admin/Downloads/in-komi-we-trust.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        sendPID->setIcon(icon2);
        PID2 = new QPushButton(groupBox_3);
        PID2->setObjectName(QString::fromUtf8("PID2"));
        PID2->setGeometry(QRect(250, 30, 61, 51));
        PID2->setFont(font);
        PID2->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 167);"));
        PID1 = new QPushButton(groupBox_3);
        PID1->setObjectName(QString::fromUtf8("PID1"));
        PID1->setGeometry(QRect(190, 30, 61, 51));
        PID1->setFont(font);
        PID1->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 167);"));
        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(350, 160, 341, 321));
        groupBox_7->setFont(font);
        groupBox_7->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 250, 255);"));
        groupBox_7->setFlat(false);
        groupBox_7->setCheckable(false);
        textBrowser_command = new QTextBrowser(groupBox_7);
        textBrowser_command->setObjectName(QString::fromUtf8("textBrowser_command"));
        textBrowser_command->setGeometry(QRect(10, 30, 311, 241));
        textBrowser_command->setFrameShape(QFrame::Panel);
        textBrowser_command->setFrameShadow(QFrame::Plain);
        pushButton_clear_2 = new QPushButton(groupBox_7);
        pushButton_clear_2->setObjectName(QString::fromUtf8("pushButton_clear_2"));
        pushButton_clear_2->setGeometry(QRect(230, 280, 91, 31));
        pushButton_clear_2->setFont(font);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(680, 10, 911, 651));
        tabWidget->setFont(font);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        groupBox_6 = new QGroupBox(tab_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 0, 891, 611));
        groupBox_6->setFont(font);
        customPlot1 = new QCustomPlot(groupBox_6);
        customPlot1->setObjectName(QString::fromUtf8("customPlot1"));
        customPlot1->setGeometry(QRect(10, 20, 871, 551));
        pushButton_plot = new QPushButton(groupBox_6);
        pushButton_plot->setObjectName(QString::fromUtf8("pushButton_plot"));
        pushButton_plot->setGeometry(QRect(10, 580, 93, 29));
        pushButton_plot->setFont(font2);
        pushButton_plot->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(0, 170, 0);\n"
""));
        pushButton_clearGraph = new QPushButton(groupBox_6);
        pushButton_clearGraph->setObjectName(QString::fromUtf8("pushButton_clearGraph"));
        pushButton_clearGraph->setGeometry(QRect(780, 580, 93, 29));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        groupBox_8 = new QGroupBox(tab_4);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 0, 891, 611));
        customPlot2 = new QCustomPlot(groupBox_8);
        customPlot2->setObjectName(QString::fromUtf8("customPlot2"));
        customPlot2->setGeometry(QRect(10, 20, 871, 551));
        customPlot2->setStyleSheet(QString::fromUtf8(""));
        pushButton_plot_2 = new QPushButton(groupBox_8);
        pushButton_plot_2->setObjectName(QString::fromUtf8("pushButton_plot_2"));
        pushButton_plot_2->setGeometry(QRect(10, 580, 93, 29));
        pushButton_plot_2->setFont(font2);
        pushButton_plot_2->setStyleSheet(QString::fromUtf8("color: rgb(170, 0, 255);"));
        pushButton_clearGraph_2 = new QPushButton(groupBox_8);
        pushButton_clearGraph_2->setObjectName(QString::fromUtf8("pushButton_clearGraph_2"));
        pushButton_clearGraph_2->setGeometry(QRect(780, 580, 93, 29));
        tabWidget->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1592, 26));
        menuPID = new QMenu(menubar);
        menuPID->setObjectName(QString::fromUtf8("menuPID"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuPID->menuAction());
        toolBar->addAction(actionSave_txt);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSave_txt->setText(QCoreApplication::translate("MainWindow", "SAVE TXT - GRAPH", nullptr));
#if QT_CONFIG(tooltip)
        actionSave_txt->setToolTip(QCoreApplication::translate("MainWindow", "SAVE TXT - GRAPH", nullptr));
#endif // QT_CONFIG(tooltip)
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "DATA READ FROM STM32", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton_readData->setText(QCoreApplication::translate("MainWindow", "Read Data", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "MODE", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "SETPOINT:", nullptr));
        pushButton_velocity->setText(QCoreApplication::translate("MainWindow", "VELOCITY (rpm)", nullptr));
        pushButton_position->setText(QCoreApplication::translate("MainWindow", "POSITION (degrees)", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "SET COM", nullptr));
        pushButton_disconnect->setText(QCoreApplication::translate("MainWindow", "DISCONNECT", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "PORT:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Baudrate:", nullptr));
        Select_COM->setText(QCoreApplication::translate("MainWindow", "CONNECT", nullptr));
        pushButton_reload->setText(QCoreApplication::translate("MainWindow", "RELOAD", nullptr));
        label_status_com->setText(QCoreApplication::translate("MainWindow", "DISCONNECT", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "RUN AND RESET", nullptr));
        pushButton_reset->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
        pushButton_run->setText(QCoreApplication::translate("MainWindow", "RUN", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "PID PARAMETERS", nullptr));
        label_Kd->setText(QCoreApplication::translate("MainWindow", "Kd:", nullptr));
        label_Kp->setText(QCoreApplication::translate("MainWindow", "Kp:", nullptr));
        label_Ki->setText(QCoreApplication::translate("MainWindow", "Ki:", nullptr));
        sendPID->setText(QCoreApplication::translate("MainWindow", "SEND PID", nullptr));
        PID2->setText(QCoreApplication::translate("MainWindow", "PID2", nullptr));
        PID1->setText(QCoreApplication::translate("MainWindow", "PID1", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "COMMAND", nullptr));
        textBrowser_command->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton_clear_2->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Graph 1", nullptr));
        pushButton_plot->setText(QCoreApplication::translate("MainWindow", "PLOT", nullptr));
        pushButton_clearGraph->setText(QCoreApplication::translate("MainWindow", "Clear Graph", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Limit_Time", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("MainWindow", "Graph 2", nullptr));
        pushButton_plot_2->setText(QCoreApplication::translate("MainWindow", "PLOT", nullptr));
        pushButton_clearGraph_2->setText(QCoreApplication::translate("MainWindow", "Clear Graph", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Real_Time", nullptr));
        menuPID->setTitle(QCoreApplication::translate("MainWindow", "PID", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
