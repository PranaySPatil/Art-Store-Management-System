#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "buyform.h"
#include "sellform.h"
#include "reportform.h"
#include "loginform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    static bool isLogged;
    static QString userName;
    ~MainWindow();

    static bool getIsLogged();
    static void setIsLogged(bool value);

private slots:
    void on_actionBuy_triggered();

    void on_actionLog_Out_triggered();

    void on_actionSell_triggered();

    void on_actionReport_triggered();

private:
    QStackedWidget *stack;
    Ui::MainWindow *ui;
    LogInForm *loginForm;
    BuyForm *buyForm;
    SellForm *sellForm;
    ReportForm *reportForm;
};

#endif // MAINWINDOW_H
