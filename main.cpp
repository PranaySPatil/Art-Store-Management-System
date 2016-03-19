#include "mainwindow.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    QIcon icon("icon.ico");
//    w.setWindowIcon(icon);
    w.show();
    w.setWindowTitle("Art Store Management System");
    return a.exec();
}
