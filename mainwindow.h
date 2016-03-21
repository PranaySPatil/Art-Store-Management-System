#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "buyform.h"
#include "sellform.h"
#include "reportform.h"
#include "loginform.h"
#include "aboutform.h"
#include "profileform.h"

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

    void on_actionRefresh_triggered();

    void on_actionAbout_triggered();

    void on_actionProfile_triggered();

private:
    QStackedWidget *stack;
    Ui::MainWindow *ui;
    LogInForm *loginForm;
    BuyForm *buyForm;
    SellForm *sellForm;
    ReportForm *buyReportForm, *sellReportForm;
    AboutForm *aboutForm;
    ProfileForm *profileForm;
    int balance;

 public slots:
    void load_paintings(QString name, QString owner, QString address, int balance, int no_of_emp);
    void refresh_balance(int price);
};

#endif // MAINWINDOW_H
