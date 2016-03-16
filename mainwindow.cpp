#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    buyForm = new BuyForm;
    sellForm = new SellForm;
    reportForm = new ReportForm;
    loginForm = new LogInForm;
    stack = ui->stackedWidget;
    stack->addWidget(loginForm);
    stack->addWidget(buyForm);
    stack->addWidget(sellForm);
    stack->addWidget(reportForm);
    stack->setCurrentWidget(loginForm);
}

bool MainWindow::isLogged = false;
QString MainWindow::userName;

bool MainWindow::getIsLogged()
{
    return isLogged;
}

void MainWindow::setIsLogged(bool value)
{
    isLogged = value;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionBuy_triggered()
{
    stack->setCurrentWidget(buyForm);
    ui->actionLog_Out->setText("LogOut");
    qDebug() << "Buy for";
    qDebug() << loginForm->getUserName();
}

void MainWindow::on_actionLog_Out_triggered()
{
    stack->setCurrentWidget(loginForm);
    loginForm->setUserName("");
    loginForm->setIsLogged(false);
    ui->actionLog_Out->setText("Log In");
}

void MainWindow::on_actionSell_triggered()
{
    stack->setCurrentWidget(sellForm);
    ui->actionLog_Out->setText("LogOut");
    qDebug() << "Sell for";
    qDebug() << loginForm->getUserName();
}

void MainWindow::on_actionReport_triggered()
{
    stack->setCurrentWidget(reportForm);
    ui->actionLog_Out->setText("LogOut");
}
