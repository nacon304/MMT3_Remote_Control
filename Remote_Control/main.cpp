#include "remote_control.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Remote_Control w;
    w.show();
    return a.exec();
}
