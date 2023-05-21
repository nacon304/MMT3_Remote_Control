#ifndef REMOTE_CONTROL_H
#define REMOTE_CONTROL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Remote_Control; }
QT_END_NAMESPACE

class Remote_Control : public QMainWindow
{
    Q_OBJECT

public:
    Remote_Control(QWidget *parent = nullptr);
    ~Remote_Control();

private slots:
    void on_btn_login_connect_clicked();

    void on_btn_home_screen_clicked();

    void on_btn_home_key_clicked();

    void on_btn_home_folder_clicked();

    void on_btn_home_app_clicked();

    void on_btn_home_process_clicked();


    void on_btn_home_screen_link_clicked();

private:
    Ui::Remote_Control *ui;
};
#endif // REMOTE_CONTROL_H
