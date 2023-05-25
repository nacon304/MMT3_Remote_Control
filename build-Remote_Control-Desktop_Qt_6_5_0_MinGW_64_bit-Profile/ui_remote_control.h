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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Remote_Control
{
public:
    QAction *actionAdd_File;
    QAction *actionDelete_File;
    QAction *actionRename;
    QAction *actionCopy_File;
    QAction *actionPaste_File;
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
    QPushButton *btn_login_change_color;
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
    QLabel *img_home_menu_logo;
    QLabel *lb_home_menu_hi;
    QWidget *wd_home_folder;
    QTreeView *tv_home_folder;
    QFrame *fr_home_folder_search;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *hor_home_folder_search;
    QLineEdit *lin_home_folder_path;
    QPushButton *btn_home_folder_submit;
    QWidget *wd_home_app;
    QTabWidget *twd_home_app;
    QWidget *tab_home_app_all;
    QListView *lv_home_app_all;
    QWidget *tab_home_app_run;
    QListView *lv_home_app_run;
    QWidget *tab_home_app_close;
    QListView *lv_home_app_close;
    QWidget *wd_home_process;
    QTabWidget *twd_home_process;
    QWidget *tab_home_process_all;
    QListView *lv_home_process_all;
    QWidget *tab_home_process_run;
    QListView *lv_home_process_run;
    QWidget *tab_home_process_close;
    QListView *lv_home_process_close;
    QWidget *wd_home_screen;
    QPushButton *btn_home_screen_link;
    QLabel *img_home_screen;
    QWidget *wd_home_key;
    QPlainTextEdit *plt_home_key;
    QLabel *lb_home_key_press;
    QLabel *lb_home_head;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Remote_Control)
    {
        if (Remote_Control->objectName().isEmpty())
            Remote_Control->setObjectName("Remote_Control");
        Remote_Control->resize(800, 600);
        actionAdd_File = new QAction(Remote_Control);
        actionAdd_File->setObjectName("actionAdd_File");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Icon/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_File->setIcon(icon);
        actionDelete_File = new QAction(Remote_Control);
        actionDelete_File->setObjectName("actionDelete_File");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icon/Icon/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete_File->setIcon(icon1);
        actionRename = new QAction(Remote_Control);
        actionRename->setObjectName("actionRename");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icon/Icon/rename.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRename->setIcon(icon2);
        actionCopy_File = new QAction(Remote_Control);
        actionCopy_File->setObjectName("actionCopy_File");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icon/Icon/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy_File->setIcon(icon3);
        actionPaste_File = new QAction(Remote_Control);
        actionPaste_File->setObjectName("actionPaste_File");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icon/Icon/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste_File->setIcon(icon4);
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
        btn_login_change_color = new QPushButton(wd_login);
        btn_login_change_color->setObjectName("btn_login_change_color");
        btn_login_change_color->setGeometry(QRect(0, 20, 31, 24));
        wd_app->addWidget(wd_login);
        wd_home = new QWidget();
        wd_home->setObjectName("wd_home");
        verticalLayoutWidget = new QWidget(wd_home);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(400, 90, 91, 411));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        verticalLayoutWidget->setFont(font4);
        ver_home_menu = new QVBoxLayout(verticalLayoutWidget);
        ver_home_menu->setObjectName("ver_home_menu");
        ver_home_menu->setContentsMargins(0, 0, 0, 0);
        btn_home_screen = new QPushButton(verticalLayoutWidget);
        btn_home_screen->setObjectName("btn_home_screen");
        btn_home_screen->setFont(font2);
        btn_home_screen->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

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
        wd_home_work->setGeometry(QRect(20, 90, 361, 411));
        wd_home_work->setStyleSheet(QString::fromUtf8("background-color: rgb(203, 226, 255);"));
        wd_home_menu = new QWidget();
        wd_home_menu->setObjectName("wd_home_menu");
        img_home_menu_logo = new QLabel(wd_home_menu);
        img_home_menu_logo->setObjectName("img_home_menu_logo");
        img_home_menu_logo->setGeometry(QRect(-2, 25, 361, 211));
        img_home_menu_logo->setPixmap(QPixmap(QString::fromUtf8(":/Img/Img/cmsnBac.jpg")));
        img_home_menu_logo->setScaledContents(true);
        lb_home_menu_hi = new QLabel(wd_home_menu);
        lb_home_menu_hi->setObjectName("lb_home_menu_hi");
        lb_home_menu_hi->setGeometry(QRect(10, 250, 341, 91));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(18);
        lb_home_menu_hi->setFont(font5);
        lb_home_menu_hi->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lb_home_menu_hi->setAlignment(Qt::AlignCenter);
        wd_home_work->addWidget(wd_home_menu);
        wd_home_folder = new QWidget();
        wd_home_folder->setObjectName("wd_home_folder");
        tv_home_folder = new QTreeView(wd_home_folder);
        tv_home_folder->setObjectName("tv_home_folder");
        tv_home_folder->setGeometry(QRect(0, 0, 361, 411));
        tv_home_folder->setStyleSheet(QString::fromUtf8("background-color: rgb(203, 226, 255);"));
        tv_home_folder->setFrameShape(QFrame::NoFrame);
        fr_home_folder_search = new QFrame(wd_home_folder);
        fr_home_folder_search->setObjectName("fr_home_folder_search");
        fr_home_folder_search->setGeometry(QRect(10, 350, 341, 51));
        fr_home_folder_search->setStyleSheet(QString::fromUtf8("background-color: rgb(203, 226, 255);"));
        fr_home_folder_search->setFrameShape(QFrame::StyledPanel);
        fr_home_folder_search->setFrameShadow(QFrame::Raised);
        fr_home_folder_search->setLineWidth(0);
        horizontalLayoutWidget = new QWidget(fr_home_folder_search);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 341, 51));
        hor_home_folder_search = new QHBoxLayout(horizontalLayoutWidget);
        hor_home_folder_search->setObjectName("hor_home_folder_search");
        hor_home_folder_search->setSizeConstraint(QLayout::SetNoConstraint);
        hor_home_folder_search->setContentsMargins(0, 0, 0, 0);
        lin_home_folder_path = new QLineEdit(horizontalLayoutWidget);
        lin_home_folder_path->setObjectName("lin_home_folder_path");
        lin_home_folder_path->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        hor_home_folder_search->addWidget(lin_home_folder_path);

        btn_home_folder_submit = new QPushButton(horizontalLayoutWidget);
        btn_home_folder_submit->setObjectName("btn_home_folder_submit");
        QFont font6;
        font6.setBold(true);
        btn_home_folder_submit->setFont(font6);
        btn_home_folder_submit->setStyleSheet(QString::fromUtf8("background-color: rgb(203, 255, 169);\n"
"color: rgb(0, 0, 0);"));

        hor_home_folder_search->addWidget(btn_home_folder_submit);

        wd_home_work->addWidget(wd_home_folder);
        wd_home_app = new QWidget();
        wd_home_app->setObjectName("wd_home_app");
        wd_home_app->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));
        twd_home_app = new QTabWidget(wd_home_app);
        twd_home_app->setObjectName("twd_home_app");
        twd_home_app->setGeometry(QRect(0, 0, 361, 411));
        twd_home_app->setStyleSheet(QString::fromUtf8("background-color: rgb(203, 226, 255);"));
        tab_home_app_all = new QWidget();
        tab_home_app_all->setObjectName("tab_home_app_all");
        lv_home_app_all = new QListView(tab_home_app_all);
        lv_home_app_all->setObjectName("lv_home_app_all");
        lv_home_app_all->setGeometry(QRect(0, 0, 361, 381));
        twd_home_app->addTab(tab_home_app_all, QString());
        tab_home_app_run = new QWidget();
        tab_home_app_run->setObjectName("tab_home_app_run");
        lv_home_app_run = new QListView(tab_home_app_run);
        lv_home_app_run->setObjectName("lv_home_app_run");
        lv_home_app_run->setGeometry(QRect(0, 0, 361, 381));
        twd_home_app->addTab(tab_home_app_run, QString());
        tab_home_app_close = new QWidget();
        tab_home_app_close->setObjectName("tab_home_app_close");
        lv_home_app_close = new QListView(tab_home_app_close);
        lv_home_app_close->setObjectName("lv_home_app_close");
        lv_home_app_close->setGeometry(QRect(0, 0, 361, 381));
        twd_home_app->addTab(tab_home_app_close, QString());
        wd_home_work->addWidget(wd_home_app);
        wd_home_process = new QWidget();
        wd_home_process->setObjectName("wd_home_process");
        wd_home_process->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        twd_home_process = new QTabWidget(wd_home_process);
        twd_home_process->setObjectName("twd_home_process");
        twd_home_process->setGeometry(QRect(0, 0, 361, 411));
        twd_home_process->setStyleSheet(QString::fromUtf8("background-color: rgb(203, 226, 255);"));
        tab_home_process_all = new QWidget();
        tab_home_process_all->setObjectName("tab_home_process_all");
        lv_home_process_all = new QListView(tab_home_process_all);
        lv_home_process_all->setObjectName("lv_home_process_all");
        lv_home_process_all->setGeometry(QRect(0, 0, 361, 381));
        twd_home_process->addTab(tab_home_process_all, QString());
        tab_home_process_run = new QWidget();
        tab_home_process_run->setObjectName("tab_home_process_run");
        lv_home_process_run = new QListView(tab_home_process_run);
        lv_home_process_run->setObjectName("lv_home_process_run");
        lv_home_process_run->setGeometry(QRect(0, 0, 361, 381));
        twd_home_process->addTab(tab_home_process_run, QString());
        tab_home_process_close = new QWidget();
        tab_home_process_close->setObjectName("tab_home_process_close");
        lv_home_process_close = new QListView(tab_home_process_close);
        lv_home_process_close->setObjectName("lv_home_process_close");
        lv_home_process_close->setGeometry(QRect(0, 0, 361, 381));
        twd_home_process->addTab(tab_home_process_close, QString());
        wd_home_work->addWidget(wd_home_process);
        wd_home_screen = new QWidget();
        wd_home_screen->setObjectName("wd_home_screen");
        btn_home_screen_link = new QPushButton(wd_home_screen);
        btn_home_screen_link->setObjectName("btn_home_screen_link");
        btn_home_screen_link->setGeometry(QRect(100, 350, 131, 31));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Arial")});
        font7.setPointSize(13);
        font7.setBold(false);
        btn_home_screen_link->setFont(font7);
        btn_home_screen_link->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 127);\n"
"color: rgb(0, 0, 0);"));
        img_home_screen = new QLabel(wd_home_screen);
        img_home_screen->setObjectName("img_home_screen");
        img_home_screen->setGeometry(QRect(0, 30, 361, 221));
        img_home_screen->setPixmap(QPixmap(QString::fromUtf8(":/Img/Img/M10.jpg")));
        img_home_screen->setScaledContents(true);
        wd_home_work->addWidget(wd_home_screen);
        wd_home_key = new QWidget();
        wd_home_key->setObjectName("wd_home_key");
        plt_home_key = new QPlainTextEdit(wd_home_key);
        plt_home_key->setObjectName("plt_home_key");
        plt_home_key->setGeometry(QRect(10, 10, 341, 251));
        plt_home_key->setTextInteractionFlags(Qt::NoTextInteraction);
        lb_home_key_press = new QLabel(wd_home_key);
        lb_home_key_press->setObjectName("lb_home_key_press");
        lb_home_key_press->setGeometry(QRect(130, 290, 101, 51));
        lb_home_key_press->setFont(font2);
        lb_home_key_press->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lb_home_key_press->setFrameShape(QFrame::StyledPanel);
        lb_home_key_press->setFrameShadow(QFrame::Plain);
        lb_home_key_press->setAlignment(Qt::AlignCenter);
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
        QWidget::setTabOrder(btn_home_process, tv_home_folder);
        QWidget::setTabOrder(tv_home_folder, lin_home_folder_path);
        QWidget::setTabOrder(lin_home_folder_path, btn_home_folder_submit);
        QWidget::setTabOrder(btn_home_folder_submit, plt_home_key);
        QWidget::setTabOrder(plt_home_key, btn_home_screen_link);

        retranslateUi(Remote_Control);

        wd_app->setCurrentIndex(0);
        wd_home_work->setCurrentIndex(0);
        twd_home_app->setCurrentIndex(0);
        twd_home_process->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Remote_Control);
    } // setupUi

    void retranslateUi(QMainWindow *Remote_Control)
    {
        Remote_Control->setWindowTitle(QCoreApplication::translate("Remote_Control", "Remote_Control", nullptr));
        actionAdd_File->setText(QCoreApplication::translate("Remote_Control", "Add File", nullptr));
#if QT_CONFIG(shortcut)
        actionAdd_File->setShortcut(QCoreApplication::translate("Remote_Control", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDelete_File->setText(QCoreApplication::translate("Remote_Control", "Delete File", nullptr));
#if QT_CONFIG(shortcut)
        actionDelete_File->setShortcut(QCoreApplication::translate("Remote_Control", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRename->setText(QCoreApplication::translate("Remote_Control", "Rename", nullptr));
#if QT_CONFIG(shortcut)
        actionRename->setShortcut(QCoreApplication::translate("Remote_Control", "F2", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy_File->setText(QCoreApplication::translate("Remote_Control", "Copy File", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy_File->setShortcut(QCoreApplication::translate("Remote_Control", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste_File->setText(QCoreApplication::translate("Remote_Control", "Paste File", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste_File->setShortcut(QCoreApplication::translate("Remote_Control", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        lb_login_header->setText(QCoreApplication::translate("Remote_Control", "\304\220\304\203ng nh\341\272\255p Client", nullptr));
        img_login_logo->setText(QString());
        lb_login_port->setText(QCoreApplication::translate("Remote_Control", "Port:", nullptr));
        lb_login_ip->setText(QCoreApplication::translate("Remote_Control", "IP:", nullptr));
        lb_login_client->setText(QCoreApplication::translate("Remote_Control", "T\303\252n Client:", nullptr));
        btn_login_connect->setText(QCoreApplication::translate("Remote_Control", "CONNECT", nullptr));
        btn_login_change_color->setText(QCoreApplication::translate("Remote_Control", "\342\230\200\357\270\217", nullptr));
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
        img_home_menu_logo->setText(QString());
        lb_home_menu_hi->setText(QCoreApplication::translate("Remote_Control", "App hay qu\303\241 n\303\250!!! \n"
"M\341\273\235i b\341\272\241n th\341\273\255 nha \342\235\244\357\270\217\342\235\244\357\270\217\342\235\244\357\270\217", nullptr));
        btn_home_folder_submit->setText(QCoreApplication::translate("Remote_Control", "SUBMIT", nullptr));
        twd_home_app->setTabText(twd_home_app->indexOf(tab_home_app_all), QCoreApplication::translate("Remote_Control", "T\341\272\245t c\341\272\243 App", nullptr));
        twd_home_app->setTabText(twd_home_app->indexOf(tab_home_app_run), QCoreApplication::translate("Remote_Control", "Ch\341\272\241y App", nullptr));
        twd_home_app->setTabText(twd_home_app->indexOf(tab_home_app_close), QCoreApplication::translate("Remote_Control", "\304\220\303\263ng App", nullptr));
        twd_home_process->setTabText(twd_home_process->indexOf(tab_home_process_all), QCoreApplication::translate("Remote_Control", "T\341\272\245t c\341\272\243 Process", nullptr));
        twd_home_process->setTabText(twd_home_process->indexOf(tab_home_process_run), QCoreApplication::translate("Remote_Control", "Ch\341\272\241y Process", nullptr));
        twd_home_process->setTabText(twd_home_process->indexOf(tab_home_process_close), QCoreApplication::translate("Remote_Control", "\304\220\303\263ng Process", nullptr));
        btn_home_screen_link->setText(QCoreApplication::translate("Remote_Control", "T\341\273\233i \304\220\306\260\341\273\235ng D\341\272\253n", nullptr));
        img_home_screen->setText(QString());
        lb_home_key_press->setText(QCoreApplication::translate("Remote_Control", "Key Press", nullptr));
        lb_home_head->setText(QCoreApplication::translate("Remote_Control", "MENU", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Remote_Control: public Ui_Remote_Control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTE_CONTROL_H
