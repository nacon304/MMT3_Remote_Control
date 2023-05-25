#include "remote_control.h"
#include "ui_remote_control.h"
#include "FolderTask.h"
#include "Globals.h"
#include "ListApp.h"
#include <QMessageBox>
#include <QFileDialog>
#include <WinSock2.h>
#include <fstream>
#include <QDesktopServices>
#include <QUrl>
#include <QTreeView>
#include <QVBoxLayout>
#include <QMenu>
#include <QFileSystemModel>
#include <QThread>
#include <QStandardItemModel>
#include <QQueue>
#include <QRegularExpression>
#include <QInputDialog>
#include <QListView>
#include <QStringListModel>

using namespace std;

const int BUFFER_SIZE = 1024;
#define MAX_LEN 5350000

QModelIndex previousDoubleClickedIndex;
QModelIndex previousCopiedIndex;
SOCKET m_socket;

bool isValidFileName(const QString& fileName)
{
    // Tạo biểu thức chính quy để kiểm tra
    QRegularExpression regex("[a-zA-Z0-9_.-]+");

    // Kiểm tra định dạng của tên tập tin
    QRegularExpressionMatch match = regex.match(fileName);
    return match.hasMatch() && match.capturedLength() == fileName.length();
}
bool isValidFolderName(const QString& fileName)
{
    for (QChar character : fileName) {
        if (character == '.') {
            return false;
        }
    }
    return true;
}

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
//    service.sin_addr.s_addr = inet_addr(IP.toUtf8().constData()); // "127.0.1.1"
//    service.sin_port = htons(Port); // [1024;49151]
    service.sin_addr.s_addr = inet_addr("127.0.1.1"); // "127.0.1.1"
    service.sin_port = htons(12345); // [1024;49151]

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
    ui->btn_home_app->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->btn_home_folder->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->btn_home_key->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->btn_home_process->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->btn_home_screen->setStyleSheet("background-color: rgb(194, 255, 176);");

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
    ui->btn_home_app->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->btn_home_folder->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->btn_home_key->setStyleSheet("background-color: rgb(194, 255, 176);");
    ui->btn_home_process->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->btn_home_screen->setStyleSheet("background-color: rgb(255, 255, 255);");

    ui->wd_home_work->setCurrentWidget(ui->wd_home_key);

    QString text = "";

    while (true)
    {
        // Duyệt qua tất cả các mã phím ảo từ 0x01 đến 0xFE
        // for (int vk = 0x01; vk <= 0xFE; vk++)
        for (int vk = 0x08; vk <= 0xFE; vk++) // bỏ qua click chuột
        {
            // Kiểm tra xem phím có được nhấn hay không
            if (GetAsyncKeyState(vk) & 0x8000)
            {
                QString keyPress = QString::fromStdString(VirtualKeyCodeToString(vk));
                ui->lb_home_key_press->setText(keyPress);
                text += keyPress + ", ";
                ui->plt_home_key->setPlainText(text);
            }
        }

        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
        {
            QMessageBox::information(this, "Thông báo", "[ESC] Bạn đã kết thúc việc bắt phím nhấn!!!");
            break; // Thoát khỏi vòng lặp khi nhấn phím ESC
        }

        // Đợi 100 ms trước khi kiểm tra lại
        QCoreApplication::processEvents();
        QThread::msleep(100);
    }
}


void Remote_Control::on_btn_home_folder_clicked()
{
    ui->btn_home_app->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->btn_home_folder->setStyleSheet("background-color: rgb(194, 255, 176);");
    ui->btn_home_key->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->btn_home_process->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->btn_home_screen->setStyleSheet("background-color: rgb(255, 255, 255);");

    ui->wd_home_work->setCurrentWidget(ui->wd_home_folder);

    ui->fr_home_folder_search->show();
    ui->btn_home_folder_submit->show();
    ui->lin_home_folder_path->show();
}


void Remote_Control::on_btn_home_app_clicked()
{
    ui->btn_home_app->setStyleSheet("background-color: rgb(194, 255, 176);");
    ui->btn_home_folder->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->btn_home_key->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->btn_home_process->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->btn_home_screen->setStyleSheet("background-color: rgb(255, 255, 255);");

    ui->wd_home_work->setCurrentWidget(ui->wd_home_app);
}


void Remote_Control::on_btn_home_process_clicked()
{
    ui->btn_home_app->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->btn_home_folder->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->btn_home_key->setStyleSheet("background-color: rgb(255, 255, 255);");
    ui->btn_home_process->setStyleSheet("background-color: rgb(194, 255, 176);");
    ui->btn_home_screen->setStyleSheet("background-color: rgb(255, 255, 255);");

    ui->wd_home_work->setCurrentWidget(ui->wd_home_process);
}

void Remote_Control::on_btn_home_screen_link_clicked()
{
    QString imgPath = "ScreenShot.bmp";
    QString folderPath = QFileInfo(imgPath).absolutePath();

    QDesktopServices::openUrl(QUrl::fromLocalFile(folderPath));
}


void Remote_Control::on_tv_home_folder_clicked(const QModelIndex &index)
{
    if (index.isValid()) {
        QString filePath = ui->tv_home_folder->model()->data(index.sibling(index.row(), index.column() + 1)).toString();
        // Tiếp tục xử lý đường dẫn của file ở đây
        qDebug() << "Đường dẫn của file: " << filePath;
    }
}


void Remote_Control::on_tv_home_folder_customContextMenuRequested(const QPoint &pos)
{
    QModelIndex index = ui->tv_home_folder->indexAt(pos);
    qDebug() << "Fuckkkkkk";
//    if (index.isValid()) {
//        QMenu contextMenu(this);
//        contextMenu.addAction(ui->actionAdd_File);
//        contextMenu.addAction(ui->actionDelete_File);
//        contextMenu.addAction(ui->actionRename);

////        connect(renameAction, &QAction::triggered, this, &Remote_Control::renameFile);
////        connect(deleteAction, &QAction::triggered, this, &Remote_Control::deleteFile);
////        connect(addAction, &QAction::triggered, this, &Remote_Control::addFile);
//        contextMenu.exec(QCursor::pos());
////        contextMenu.exec(ui->tv_home_folder->viewport()->mapToGlobal(pos));
//    }
}

void Remote_Control::on_wd_home_folder_customContextMenuRequested(const QPoint &pos)
{

}


void Remote_Control::on_tv_home_folder_doubleClicked(const QModelIndex &index)
{
    if (index.isValid()) {
        previousDoubleClickedIndex = index;

        QMenu contextMenu(this);
        contextMenu.addAction(ui->actionAdd_File);
        contextMenu.addAction(ui->actionDelete_File);
        contextMenu.addAction(ui->actionRename);
        contextMenu.addAction(ui->actionCopy_File);
        contextMenu.addAction(ui->actionPaste_File);

        contextMenu.exec(QCursor::pos());
        if(ui->tv_home_folder->isExpanded(index))
            ui->tv_home_folder->collapse(index);
        else
            ui->tv_home_folder->expand(index);
    }
}


void Remote_Control::on_actionAdd_File_triggered()
{
    QString path = ui->tv_home_folder->model()->data(previousDoubleClickedIndex.sibling(previousDoubleClickedIndex.row(), previousDoubleClickedIndex.column() + 1)).toString();

    bool ok;
    QString fileName = QInputDialog::getText(this, "Thêm file", "Nhập tên file:", QLineEdit::Normal, "", &ok);

    if (ok && !fileName.isEmpty()) {
        // Xử lý tên file ở đây (ví dụ: tạo file với tên đã nhập)
        QString newFile = path + fileName;

        if(!isValidFileName(fileName))
        {
            QMessageBox::information(this, "Thông báo", "Nhập file lỗi!!!");
            return;
        }

        QString type = "File";
        FolderTask * fl;
        if(isValidFolderName(fileName))
        {
            fl->createFolder(newFile.toLatin1().constData());
            type = "Folder";
        }
        else
            fl->createFile(newFile.toLatin1().constData());

        QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tv_home_folder->model());

        if(model) {
            QStandardItem* itemName = new QStandardItem(fileName);
            QStandardItem* itemPath = new QStandardItem(newFile + '/');
            QStandardItem* itemType = new QStandardItem(type);

            // Lấy QStandardItem cha tại previousDoubleClickedIndex
            QStandardItem* parentItem = model->itemFromIndex(previousDoubleClickedIndex);

            // Đặt các giá trị vào các cột
            parentItem->setChild(parentItem->rowCount(), 0, itemName);
            parentItem->setChild(parentItem->rowCount() - 1, 1, itemPath);
            parentItem->setChild(parentItem->rowCount() - 1, 2, itemType);
        }

        QMessageBox::information(this, "Thông báo", "Thêm file thành công!!!");
    }
    else
        QMessageBox::information(this, "Thông báo", "Nhập file lỗi!!!");
}


void Remote_Control::on_actionDelete_File_triggered()
{
    QString path = ui->tv_home_folder->model()->data(previousDoubleClickedIndex.sibling(previousDoubleClickedIndex.row(), previousDoubleClickedIndex.column() + 1)).toString();
    path.removeLast();

    FolderTask * fl;
    if(fl->isFolder(path.toStdString()))
        fl->deleteFolder(path.toLatin1().constData());
    else
        fl->deleteFile(path.toLatin1().constData());

    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tv_home_folder->model());

    if(model) {
        // Lấy QStandardItem tương ứng với QModelIndex
        QStandardItem* itemToRemove = model->itemFromIndex(previousDoubleClickedIndex);

        // Lấy QStandardItem cha của hàng muốn xóa
        QStandardItem* parentItem = itemToRemove->parent();

        // Xóa hàng từ QStandardItemModel
        parentItem->removeRow(itemToRemove->row());
        QMessageBox::information(this, "Thông báo", "Xóa file thành công!!!");
    }
    else
        QMessageBox::information(this, "Thông báo", "Xóa file không thành công!!!");
}


void Remote_Control::on_actionRename_triggered()
{
    QString path = ui->tv_home_folder->model()->data(previousDoubleClickedIndex.sibling(previousDoubleClickedIndex.row(), previousDoubleClickedIndex.column() + 1)).toString();
    QString oldName = ui->tv_home_folder->model()->data(previousDoubleClickedIndex).toString() + "/";

    bool ok;
    QString newName = QInputDialog::getText(this, "Đổi tên file", "Nhập tên file mới:", QLineEdit::Normal, "", &ok);

    if (ok && !newName.isEmpty()) {
        QString newFile = path.left(path.length() - oldName.length()) + newName + "/";

        if(!isValidFileName(newName))
        {
            QMessageBox::information(this, "Thông báo", "Nhập file lỗi!!!");
            return;
        }

        qDebug() << "Dia chi cu: " << path.removeLast();
        qDebug() << "Dia chi moi: " << newFile.removeLast();
        FolderTask * fl;
        if(!fl->renameFileFolder(path.toLatin1().constData(), newFile.toLatin1().constData()))
        {
            QMessageBox::information(this, "Thông báo", "Đổi tên file không thành công!!!");
            return;
        }

        QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tv_home_folder->model());

        if(model) {
            // Lấy QStandardItem tương ứng với QModelIndex
            QStandardItem* item = model->itemFromIndex(previousDoubleClickedIndex);

            // Thay đổi giá trị của cột 0
            item->setText(newName); // Thay đổi giá trị của cột 0

            // Lấy QModelIndex của cột 1 kế tiếp
            QModelIndex siblingIndex = previousDoubleClickedIndex.sibling(previousDoubleClickedIndex.row(), previousDoubleClickedIndex.column() + 1);

            // Kiểm tra xem siblingIndex hợp lệ và thay đổi giá trị của cột 1
            if (siblingIndex.isValid()) {
                model->setData(siblingIndex, newFile + '/', Qt::DisplayRole);
            }
        }

        QMessageBox::information(this, "Thông báo", "Đổi tên file thành công!!!");
    }
    else
        QMessageBox::information(this, "Thông báo", "Nhập file lỗi!!!");

}


void Remote_Control::on_actionCopy_File_triggered()
{
    previousCopiedIndex = previousDoubleClickedIndex;
    QMessageBox::information(this, "Thông báo", "Đã sao chép file vào ổ nhớ tạm thành công!!!");
}


void Remote_Control::on_actionPaste_File_triggered()
{
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tv_home_folder->model());

    QStandardItem* itemCopy = model->itemFromIndex(previousCopiedIndex);
    QStandardItem* itemPaste = model->itemFromIndex(previousDoubleClickedIndex);

    if(itemCopy == itemPaste)
    {
        QMessageBox::information(this, "Thông báo", "File đã tồn tại!!!");
        return;
    }

    QString pathSrc = model->data(previousCopiedIndex.sibling(previousCopiedIndex.row(), previousCopiedIndex.column() + 1)).toString();
    QString pathDes = model->data(previousDoubleClickedIndex.sibling(previousDoubleClickedIndex.row(), previousDoubleClickedIndex.column() + 1)).toString();
    QString nameSrc = ui->tv_home_folder->model()->data(previousCopiedIndex).toString();
    QString oldPath = pathSrc.removeLast();
    QString newPath = pathDes + nameSrc;

    QString type = "File";
    FolderTask * fl;
    if(fl->isFolder(oldPath.toStdString()))
    {
        fl->createFolder(newPath.toLatin1().constData());
        type = "Folder";
    }
    else
        fl->createFile(newPath.toLatin1().constData());

    if(model) {
        QStandardItem* itemName = new QStandardItem(nameSrc);
        QStandardItem* itemPath = new QStandardItem(newPath + '/');
        QStandardItem* itemType = new QStandardItem(type);

        // Lấy QStandardItem cha tại previousDoubleClickedIndex
        QStandardItem* parentItem = model->itemFromIndex(previousDoubleClickedIndex);

        // Đặt các giá trị vào các cột
        parentItem->setChild(parentItem->rowCount(), 0, itemName);
        parentItem->setChild(parentItem->rowCount() - 1, 1, itemPath);
        parentItem->setChild(parentItem->rowCount() - 1, 1, itemType);
    }

    QMessageBox::information(this, "Thông báo", "Đã dán file thành công!!!");
}

void Remote_Control::on_btn_home_folder_submit_clicked()
{
//    QString path = ui->lin_home_folder_path->text();

//    // Khởi tạo QFileSystemModel
//    QFileSystemModel *model = new QFileSystemModel();
//    model->setRootPath(path); // Đặt đường dẫn gốc là ổ đĩa C

//    // Khởi tạo QTreeView và đặt model
//    ui->tv_home_folder->setModel(model);
//    ui->tv_home_folder->setRootIndex(model->index(path));
//    ui->tv_home_folder->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

//    ui->fr_home_folder_search->hide();
//    ui->btn_home_folder_submit->hide();
//    ui->lin_home_folder_path->hide();

 // Tạo mô hình dữ liệu
    QString path = ui->lin_home_folder_path->text();

    QStandardItemModel* model = new QStandardItemModel(this);

    // Thiết lập mô hình cho QTreeView
    ui->tv_home_folder->setModel(model);
    ui->tv_home_folder->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

    // Thiết lập tiêu đề cột
    model->setHorizontalHeaderLabels(QStringList() << "Tên" << "Đường dẫn" << "Loại");

    // Thêm dữ liệu ví dụ
    QStandardItem* rootItem = model->invisibleRootItem();

    FolderTask * fl;
    QQueue<QStandardItem*> stItem;
    vector<string> files = fl->list_files(path.toUtf8().constData());
    for(int i = 0; i < files.size(); i++)
    {
        QString file = QString::fromStdString(files[i]);
        QStandardItem* itemName = new QStandardItem(file);
        QStandardItem* itemPath = new QStandardItem(path + file + '/');
        rootItem->appendRow(itemName);
        rootItem->setChild(i, 1, itemPath);

        QString type = "File";
        if(fl->isFolder((path + file).toStdString()))
            type = "Folder";
        rootItem->setChild(i, 2, new QStandardItem(type));

        stItem.enqueue(rootItem->child(i));
//        QModelIndex childIndex = rootItem->child(i)->index(); // Get the index of the current child item
//        QModelIndex nextSiblingIndex = childIndex.sibling(childIndex.row(), childIndex.column() + 1);
//        QStandardItem * childItem = model->itemFromIndex(nextSiblingIndex);
//        qDebug() << childItem->data(0).toString() <<"\n";
    }
    while(stItem.size())
    {
        QStandardItem* rItem = stItem.front();
        QModelIndex childIndex = rItem->index();
        QModelIndex nextSiblingIndex = childIndex.sibling(childIndex.row(), childIndex.column() + 1);
        QStandardItem * childItem = model->itemFromIndex(nextSiblingIndex);
        QString pth = childItem->data(0).toString();
        qDebug() << pth;
        stItem.dequeue();

        files.clear();
        files = fl->list_files(pth.toUtf8().constData());

        for(int i = 0; i < files.size(); i++)
        {
            QString file = QString::fromStdString(files[i]);
            qDebug() << file;
            QStandardItem* item = new QStandardItem(file);
            rItem->appendRow(item);
            rItem->setChild(i, 1, new QStandardItem(pth + file + '/'));

            QString type = "File";
            if(fl->isFolder((pth + file).toStdString()))
                type = "Folder";
            rItem->setChild(i, 2, new QStandardItem(type));
//            rootItem->appendColumn(new QStandardItem(pth + '\\' + QString::fromStdString(file)));
            stItem.enqueue(rItem->child(i));
        }

    }
//    ui->tv_home_folder->setStyleSheet("QTreeView::item { border-color: red; }");
//    ui->tv_home_folder->setColumnHidden(1, true);
    ui->fr_home_folder_search->hide();
    ui->btn_home_folder_submit->hide();
    ui->lin_home_folder_path->hide();
}


void Remote_Control::on_pushButton_clicked()
{
    return;
}


void Remote_Control::on_btn_login_change_color_clicked()
{
    ui->wd_login->setStyleSheet("background-color: rgb(240, 205, 255);");
}



void Remote_Control::on_twd_home_app_tabBarClicked(int index)
{
    qDebug() << "Tab Bar clicked. Index: " << index;

    if(index == 0)
    {
        vector<string> allApps = listAllApp();

        QStandardItemModel *model;
        model = new QStandardItemModel(this);

        for(int i = 1; i <= allApps.size();i++)
        {
            QString data = QString::number(i) + ". " + QString::fromStdString(allApps[i - 1]);
            QStandardItem *item = new QStandardItem(data);

            model->appendRow(item);
        }

        ui->lv_home_app_all->setModel(model);
    }
    else if(index == 1)
    {
        vector<string> runApps = listAllAppRun();

        QStandardItemModel *model;
        model = new QStandardItemModel(this);

        for(int i = 1; i <= runApps.size();i++)
        {
            QString data = QString::number(i) + ". " + QString::fromStdString(runApps[i - 1]);
//            qDebug() << data;
            QStandardItem *item = new QStandardItem(data);

            model->appendRow(item);
        }

        ui->lv_home_app_run->setModel(model);
    }
    else
    {
        return;
    }
}


void Remote_Control::on_twd_home_process_tabBarClicked(int index)
{
    qDebug() << "Tab Bar clicked. Index: " << index;

    if(index == 0)
    {
        return;
    }
    else if(index == 1)
    {
        return;
    }
    else
    {
        return;
    }
}


void Remote_Control::on_lv_home_app_run_doubleClicked(const QModelIndex &index)
{
    QAbstractItemModel* model = ui->lv_home_app_run->model();
    QString item = model->data(index).toString();
    QString path = item.split(". ")[1];
    qDebug()<<path;

    // Display a message box with options "Run" and "Do Not Run"
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Chạy App", "Bạn có muốn chạy App này?\n" + path,
                                                              QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // User chose to run the item
        qDebug() << "Running item:" << path;
        runApp(path.toStdString());
    } else {
        // User chose not to run the item
        qDebug() << "Not running item:" << path;
    }
}


void Remote_Control::on_btn_home_back_clicked()
{
//    closesocket(m_socket);
//    printf("Close m_socket\n");
//    WSACleanup();
    ui->wd_app->setCurrentWidget(ui->wd_login);
}

