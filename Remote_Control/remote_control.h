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

    void on_tv_home_folder_clicked(const QModelIndex &index);

    void on_tv_home_folder_customContextMenuRequested(const QPoint &pos);

    void on_wd_home_folder_customContextMenuRequested(const QPoint &pos);

    void on_tv_home_folder_doubleClicked(const QModelIndex &index);

    void on_actionAdd_File_triggered();

    void on_actionDelete_File_triggered();

    void on_actionRename_triggered();

    void on_btn_home_folder_submit_clicked();

    void on_pushButton_clicked();

    void on_btn_login_change_color_clicked();

    void on_actionCopy_File_triggered();

    void on_actionPaste_File_triggered();

    void on_twd_home_app_tabBarClicked(int index);

    void on_twd_home_process_tabBarClicked(int index);

    void on_lv_home_app_run_doubleClicked(const QModelIndex &index);

    void on_btn_home_back_clicked();

private:
    Ui::Remote_Control *ui;
};
#endif // REMOTE_CONTROL_H
