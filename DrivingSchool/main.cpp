#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/new/image/img/logo.png"));
    MainWindow w;
    // background
    //w.setStyleSheet("background-color:#EEEEEE;");

    w.setWindowTitle("简易驾校数据查询系统");
    w. setFixedSize(1200,900);
    w.show();
    return a.exec();
}
