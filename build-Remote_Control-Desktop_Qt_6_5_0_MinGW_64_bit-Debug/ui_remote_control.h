/********************************************************************************
** Form generated from reading UI file 'remote_control.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOTE_CONTROL_H
#define UI_REMOTE_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Remote_Control
{
public:
    QWidget *centralwidget;
    QStackedWidget *wd_app;
    QWidget *wd_login;
    QFrame *fr_login_head;
    QLabel *lb_login_header;
    QLabel *img_login_logo;
    QFrame *fr_login_info;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *lb_login_port;
    QLineEdit *lin_login_client;
    QLabel *lb_login_ip;
    QLineEdit *lin_login_ip;
    QLabel *lb_login_client;
    QLineEdit *lin_login_port;
    QPushButton *btn_login_connect;
    QWidget *wd_home;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *ver_home_menu;
    QPushButton *btn_home_screen;
    QPushButton *btn_home_key;
    QPushButton *btn_home_folder;
    QPushButton *btn_home_app;
    QPushButton *btn_home_process;
    QStackedWidget *wd_home_work;
    QWidget *wd_home_menu;
    QSpinBox *spinBox;
    QWidget *wd_home_folder;
    QDateEdit *dateEdit;
    QWidget *wd_home_app;
    QLabel *label;
    QWidget *wd_home_process;
    QSlider *horizontalSlider;
    QWidget *wd_home_screen;
    QPushButton *btn_home_screen_link;
    QLabel *img_home_screen;
    QWidget *wd_home_key;
    QTextEdit *textEdit;
    QLabel *lb_home_head;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Remote_Control)
    {
        if (Remote_Control->objectName().isEmpty())
            Remote_Control->setObjectName("Remote_Control");
        Remote_Control->resize(800, 600);
        centralwidget = new QWidget(Remote_Control);
        centralwidget->setObjectName("centralwidget");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(10);
        centralwidget->setFont(font);
        wd_app = new QStackedWidget(centralwidget);
        wd_app->setObjectName("wd_app");
        wd_app->setGeometry(QRect(190, -20, 511, 531));
        wd_app->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));
        wd_login = new QWidget();
        wd_login->setObjectName("wd_login");
        fr_login_head = new QFrame(wd_login);
        fr_login_head->setObjectName("fr_login_head");
        fr_login_head->setGeometry(QRect(30, 50, 451, 211));
        fr_login_head->setFrameShape(QFrame::StyledPanel);
        fr_login_head->setFrameShadow(QFrame::Raised);
        lb_login_header = new QLabel(fr_login_head);
        lb_login_header->setObjectName("lb_login_header");
        lb_login_header->setGeometry(QRect(110, 0, 231, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(22);
        font1.setStyleStrategy(QFont::PreferDefault);
        lb_login_header->setFont(font1);
        lb_login_header->setAlignment(Qt::AlignCenter);
        img_login_logo = new QLabel(fr_login_head);
        img_login_logo->setObjectName("img_login_logo");
        img_login_logo->setGeometry(QRect(90, 40, 271, 171));
        img_login_logo->setAutoFillBackground(false);
        img_login_logo->setPixmap(QPixmap(QString::fromUtf8(":/Img/Img/M10.jpg")));
        img_login_logo->setScaledContents(true);
        fr_login_info = new QFrame(wd_login);
        fr_login_info->setObjectName("fr_login_info");
        fr_login_info->setGeometry(QRect(60, 270, 421, 161));
        fr_login_info->setFrameShape(QFrame::StyledPanel);
        fr_login_info->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(fr_login_info);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        lb_login_port = new QLabel(fr_login_info);
        lb_login_port->setObjectName("lb_login_port");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(13);
        lb_login_port->setFont(font2);
        lb_login_port->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lb_login_port, 2, 0, 1, 1);

        lin_login_client = new QLineEdit(fr_login_info);
        lin_login_client->setObjectName("lin_login_client");
        lin_login_client->setFont(font2);
        lin_login_client->setFrame(false);

        gridLayout->addWidget(lin_login_client, 0, 1, 1, 1);

        lb_login_ip = new QLabel(fr_login_info);
        lb_login_ip->setObjectName("lb_login_ip");
        lb_login_ip->setFont(font2);
        lb_login_ip->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lb_login_ip, 1, 0, 1, 1);

        lin_login_ip = new QLineEdit(fr_login_info);
        lin_login_ip->setObjectName("lin_login_ip");
        lin_login_ip->setFont(font2);
        lin_login_ip->setFrame(false);

        gridLayout->addWidget(lin_login_ip, 1, 1, 1, 1);

        lb_login_client = new QLabel(fr_login_info);
        lb_login_client->setObjectName("lb_login_client");
        lb_login_client->setFont(font2);
        lb_login_client->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lb_login_client, 0, 0, 1, 1);

        lin_login_port = new QLineEdit(fr_login_info);
        lin_login_port->setObjectName("lin_login_port");
        lin_login_port->setFont(font2);
        lin_login_port->setFrame(false);

        gridLayout->addWidget(lin_login_port, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        btn_login_connect = new QPushButton(wd_login);
        btn_login_connect->setObjectName("btn_login_connect");
        btn_login_connect->setGeometry(QRect(170, 460, 171, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(12);
        font3.setBold(true);
        btn_login_connect->setFont(font3);
        btn_login_connect->setStyleSheet(QString::fromUtf8("background-color: rgb(36, 255, 97);\n"
"color: rgb(0, 0, 0);"));
        wd_app->addWidget(wd_login);
        wd_home = new QWidget();
        wd_home->setObjectName("wd_home");
        verticalLayoutWidget = new QWidget(wd_home);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(390, 90, 91, 411));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        verticalLayoutWidget->setFont(font4);
        ver_home_menu = new QVBoxLayout(verticalLayoutWidget);
        ver_home_menu->setObjectName("ver_home_menu");
        ver_home_menu->setContentsMargins(0, 0, 0, 0);
        btn_home_screen = new QPushButton(verticalLayoutWidget);
        btn_home_screen->setObjectName("btn_home_screen");
        btn_home_screen->setFont(font2);

        ver_home_menu->addWidget(btn_home_screen);

        btn_home_key = new QPushButton(verticalLayoutWidget);
        btn_home_key->setObjectName("btn_home_key");
        btn_home_key->setFont(font2);

        ver_home_menu->addWidget(btn_home_key);

        btn_home_folder = new QPushButton(verticalLayoutWidget);
        btn_home_folder->setObjectName("btn_home_folder");
        btn_home_folder->setFont(font2);

        ver_home_menu->addWidget(btn_home_folder);

        btn_home_app = new QPushButton(verticalLayoutWidget);
        btn_home_app->setObjectName("btn_home_app");
        btn_home_app->setFont(font2);

        ver_home_menu->addWidget(btn_home_app);

        btn_home_process = new QPushButton(verticalLayoutWidget);
        btn_home_process->setObjectName("btn_home_process");
        btn_home_process->setFont(font2);

        ver_home_menu->addWidget(btn_home_process);

        wd_home_work = new QStackedWidget(wd_home);
        wd_home_work->setObjectName("wd_home_work");
        wd_home_work->setGeometry(QRect(30, 90, 331, 411));
        wd_home_work->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(100, 100, 100);"));
        wd_home_menu = new QWidget();
        wd_home_menu->setObjectName("wd_home_menu");
        spinBox = new QSpinBox(wd_home_menu);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(130, 100, 42, 25));
        wd_home_work->addWidget(wd_home_menu);
        wd_home_folder = new QWidget();
        wd_home_folder->setObjectName("wd_home_folder");
        dateEdit = new QDateEdit(wd_home_folder);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(30, 180, 110, 25));
        wd_home_work->addWidget(wd_home_folder);
        wd_home_app = new QWidget();
        wd_home_app->setObjectName("wd_home_app");
        label = new QLabel(wd_home_app);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 180, 49, 16));
        wd_home_work->addWidget(wd_home_app);
        wd_home_process = new QWidget();
        wd_home_process->setObjectName("wd_home_process");
        horizontalSlider = new QSlider(wd_home_process);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(80, 150, 160, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        wd_home_work->addWidget(wd_home_process);
        wd_home_screen = new QWidget();
        wd_home_screen->setObjectName("wd_home_screen");
        btn_home_screen_link = new QPushButton(wd_home_screen);
        btn_home_screen_link->setObjectName("btn_home_screen_link");
        btn_home_screen_link->setGeometry(QRect(100, 350, 131, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(13);
        font5.setBold(false);
        btn_home_screen_link->setFont(font5);
        btn_home_screen_link->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);\n"
"color: rgb(0, 0, 0);"));
        img_home_screen = new QLabel(wd_home_screen);
        img_home_screen->setObjectName("img_home_screen");
        img_home_screen->setGeometry(QRect(0, 30, 331, 201));
        img_home_screen->setPixmap(QPixmap(QString::fromUtf8(":/Img/Img/M10.jpg")));
        img_home_screen->setScaledContents(true);
        wd_home_work->addWidget(wd_home_screen);
        wd_home_key = new QWidget();
        wd_home_key->setObjectName("wd_home_key");
        textEdit = new QTextEdit(wd_home_key);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(110, 90, 104, 70));
        wd_home_work->addWidget(wd_home_key);
        lb_home_head = new QLabel(wd_home);
        lb_home_head->setObjectName("lb_home_head");
        lb_home_head->setGeometry(QRect(140, 40, 231, 31));
        lb_home_head->setFont(font1);
        lb_home_head->setAlignment(Qt::AlignCenter);
        wd_app->addWidget(wd_home);
        Remote_Control->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Remote_Control);
        statusbar->setObjectName("statusbar");
        Remote_Control->setStatusBar(statusbar);
        QWidget::setTabOrder(lin_login_client, lin_login_ip);
        QWidget::setTabOrder(lin_login_ip, lin_login_port);
        QWidget::setTabOrder(lin_login_port, btn_login_connect);
        QWidget::setTabOrder(btn_login_connect, btn_home_screen);
        QWidget::setTabOrder(btn_home_screen, btn_home_key);
        QWidget::setTabOrder(btn_home_key, btn_home_folder);
        QWidget::setTabOrder(btn_home_folder, btn_home_app);
        QWidget::setTabOrder(btn_home_app, btn_home_process);

        retranslateUi(Remote_Control);

        wd_app->setCurrentIndex(0);
        wd_home_work->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Remote_Control);
    } // setupUi

    void retranslateUi(QMainWindow *Remote_Control)
    {
        Remote_Control->setWindowTitle(QCoreApplication::translate("Remote_Control", "Remote_Control", nullptr));
        lb_login_header->setText(QCoreApplication::translate("Remote_Control", "\304\220\304\203ng nh\341\272\255p Client", nullptr));
        img_login_logo->setText(QString());
        lb_login_port->setText(QCoreApplication::translate("Remote_Control", "Port:", nullptr));
        lb_login_ip->setText(QCoreApplication::translate("Remote_Control", "IP:", nullptr));
        lb_login_client->setText(QCoreApplication::translate("Remote_Control", "T\303\252n Client:", nullptr));
        btn_login_connect->setText(QCoreApplication::translate("Remote_Control", "CONNECT", nullptr));
        btn_home_screen->setText(QCoreApplication::translate("Remote_Control", "Ch\341\273\245p m\303\240n\n"
"h\303\254nh", nullptr));
        btn_home_key->setText(QCoreApplication::translate("Remote_Control", "B\341\272\257t ph\303\255m\n"
"nh\341\272\245n", nullptr));
        btn_home_folder->setText(QCoreApplication::translate("Remote_Control", "Qu\341\272\243n l\303\275\n"
"th\306\260 m\341\273\245c", nullptr));
        btn_home_app->setText(QCoreApplication::translate("Remote_Control", "Qu\341\272\243n l\303\275\n"
"App", nullptr));
        btn_home_process->setText(QCoreApplication::translate("Remote_Control", "Qu\341\272\243n l\303\275\n"
"ti\341\272\277n tr\303\254nh", nullptr));
        label->setText(QCoreApplication::translate("Remote_Control", "Appppppppppppppppp", nullptr));
        btn_home_screen_link->setText(QCoreApplication::translate("Remote_Control", "T\341\273\233i \304\220\306\260\341\273\235ng D\341\272\253n", nullptr));
        img_home_screen->setText(QString());
        textEdit->setHtml(QCoreApplication::translate("Remote_Control", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">fuccccc</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        lb_home_head->setText(QCoreApplication::translate("Remote_Control", "MENU", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Remote_Control: public Ui_Remote_Control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTE_CONTROL_H
