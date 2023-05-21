#include "remote_control.h"
#include "ui_remote_control.h"
#include <QMessageBox>
#include <QFileDialog>
#include <WinSock2.h>
#include <fstream>
#include <QDesktopServices>
#include <QUrl>

using namespace std;

const int BUFFER_SIZE = 1024;
#define MAX_LEN 5350000

SOCKET m_socket;

Remote_Control::Remote_Control(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Remote_Control)
{
    ui->setupUi(this);
}

Remote_Control::~Remote_Control()
{
    delete ui;
}

void SaveScreenShotToFile(char* filename) {
    // Nhan kich thuoc file
    streampos file_size;
    int bytes_received;
    do {
        bytes_received = recv(m_socket, reinterpret_cast<char*>(&file_size), sizeof(streampos), 0);
    } while (bytes_received == -1);

    // Tao file anh
    ofstream out(filename, ios::binary);
    char* buffer = new char[BUFFER_SIZE];
    int bytes_read = 0;

    // Nhan file anh
    while (bytes_read < file_size) {
        do {
            bytes_received = recv(m_socket, buffer, BUFFER_SIZE, 0);
        } while(bytes_received == -1);

        out.write(buffer, bytes_received);
        bytes_read += bytes_received;
        if (bytes_read == file_size) {
            break;
        }
    }

    out.close();
    delete[] buffer;
}

QString openSocketClient(QString name, QString IP, int Port, bool & checkStatus)
{
    WORD verRequested = MAKEWORD(2, 2);
    WSADATA wsaData;

    QString notice = QString("Hello %1!\n").arg(name);

    int wsaErr = WSAStartup(verRequested, &wsaData);
    if (wsaErr != 0) {
        notice += QString("WSAStartup fail - error: %1").arg(QString::number(wsaErr));
        return 0;
    }
    else
        notice += QString("WSAStartup success - status: %1\n").arg(wsaData.szSystemStatus);

//    SOCKET m_socket;
    m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_socket == INVALID_SOCKET) {
        notice += QString("socket fail - error: %1").arg(QString::number(WSAGetLastError()));
        WSACleanup();
        return 0;
    }
    else
        notice += QString("socket success\n");

    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr(IP.toUtf8().constData()); // "127.0.1.1"
    service.sin_port = htons(Port); // [1024;49151]
//    service.sin_addr.s_addr = inet_addr("127.0.1.1"); // "127.0.1.1"
//    service.sin_port = htons(12345); // [1024;49151]

    int connectErr = connect(m_socket, (SOCKADDR *)&service, sizeof(service));
    if (connectErr != 0) {
        notice += QString("connect fail - error: %1").arg(QString::number(WSAGetLastError()));
        WSACleanup();
        return 0;
    }
    else
        notice += QString("connect success\n");

    checkStatus = 1;

    return notice;
}

void Remote_Control::on_btn_login_connect_clicked()
{
    ui->btn_login_connect->setStyleSheet("background-color: rgb(218, 44, 0);");

    QString name = ui->lin_login_client->text();
    QString IP = ui->lin_login_ip->text();
    int Port = ui->lin_login_port->text().toInt();

    bool checkStatus = 0;
    QMessageBox::information(this, "Thông báo", openSocketClient(name, IP, Port, checkStatus));

    ui->btn_login_connect->setStyleSheet("background-color: rgb(36, 255, 97);");

    if(checkStatus) ui->wd_app->setCurrentWidget(ui->wd_home);

//    closesocket(m_socket);
//    printf("Close m_socket\n");
//    WSACleanup();
}


void Remote_Control::on_btn_home_screen_clicked()
{
    ui->wd_home_work->setCurrentWidget(ui->wd_home_screen);
    char filename[] = "ScreenShot.bmp";
    SaveScreenShotToFile(filename);

     // Đường dẫn tới tệp ảnh
    QString imagePath = "ScreenShot.bmp";
    QPixmap image(imagePath);
    ui->img_home_screen->setPixmap(image);

//    connect(button, &QPushButton::clicked, [this, imagePath]() {
//        QString folderPath = QFileInfo(imagePath).absolutePath();
//        // Xử lý thư mục được chọn (ví dụ: hiển thị đường dẫn trên một QLabel)
//        QLabel *label = new QLabel(ui->wd_home_screen);
//        label->setText("Image folder: " + folderPath);
//        label->move(10, 50);
//        label->show();
//    });

//    button->show();
}


void Remote_Control::on_btn_home_key_clicked()
{
    ui->wd_home_work->setCurrentWidget(ui->wd_home_key);
}


void Remote_Control::on_btn_home_folder_clicked()
{
    ui->wd_home_work->setCurrentWidget(ui->wd_home_folder);
}


void Remote_Control::on_btn_home_app_clicked()
{
    ui->wd_home_work->setCurrentWidget(ui->wd_home_app);
}


void Remote_Control::on_btn_home_process_clicked()
{
    ui->wd_home_work->setCurrentWidget(ui->wd_home_process);
}

void Remote_Control::on_btn_home_screen_link_clicked()
{
    QString imgPath = "ScreenShot.bmp";
    QString folderPath = QFileInfo(imgPath).absolutePath();

    QDesktopServices::openUrl(QUrl::fromLocalFile(folderPath));
}

