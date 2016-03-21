#include "mainwindow.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setStyleSheet("background-image:url(\"back.jpg\"); background-position: center;");
//    w.setStyleSheet("background-color:red");
    w.show();
    w.setWindowTitle("Art Store Management System");
    return a.exec();
}
