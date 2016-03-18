#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    buyForm = new BuyForm;
    sellForm = new SellForm;
    reportForm = new ReportForm;
    loginForm = new LogInForm;
    aboutForm = new AboutForm;
    profileForm = new ProfileForm;
    stack = ui->stackedWidget;
    stack->addWidget(loginForm);
    stack->addWidget(buyForm);
    stack->addWidget(sellForm);
    stack->addWidget(reportForm);
    stack->addWidget(aboutForm);
    stack->addWidget(profileForm);
    stack->setCurrentWidget(loginForm);
    QObject::connect(loginForm, SIGNAL(loggedIn()), this, SLOT(load_paintings()));
}

bool MainWindow::isLogged = false;
QString MainWindow::userName;


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionBuy_triggered()
{
    if(loginForm->getIsLogged()){
        stack->setCurrentWidget(buyForm);
        qDebug() << "Buy for";
        qDebug() << loginForm->getUserName();
    }
    else{
        QMessageBox::warning(
                this,
                tr("ASMS"),
                tr("You must login first") );
    }
}

void MainWindow::on_actionLog_Out_triggered()
{
    if(loginForm->getIsLogged()){
        loginForm->logOut();
        stack->setCurrentWidget(loginForm);
        loginForm->setUserName("");
        loginForm->setIsLogged(false);
        ui->actionLog_Out->setText("Log In");
        delete(buyForm);
        delete(sellForm);
        delete(reportForm);
        buyForm = new BuyForm;
        sellForm = new SellForm;
        reportForm = new ReportForm;
        stack->addWidget(buyForm);
        stack->addWidget(sellForm);
        stack->addWidget(reportForm);
    }
    else{
        stack->setCurrentWidget(loginForm);
    }

}

void MainWindow::on_actionSell_triggered()
{
    if(loginForm->getIsLogged()){
        stack->setCurrentWidget(sellForm);
        qDebug() << "Sell for";
        qDebug() << loginForm->getUserName();
    }
    else{
        QMessageBox::warning(
                this,
                tr("ASMS"),
                tr("You must login first") );
    }
}

void MainWindow::on_actionReport_triggered()
{
    stack->setCurrentWidget(reportForm);
//    if(loginForm->getIsLogged()){
//        stack->setCurrentWidget(reportForm);
//        ui->actionLog_Out->setText("LogOut");
//    }
//    else{
//        QMessageBox::warning(
//                this,
//                tr("ASMS"),
//                tr("You must login first") );
//    }
}

void MainWindow::on_actionRefresh_triggered()
{
    if(loginForm->getIsLogged()){
        buyForm->setUserName(loginForm->getUserName());
        buyForm->refresh();
        sellForm->setUserName(loginForm->getUserName());
        sellForm->refresh();
    }
    else{
        QMessageBox::warning(
                this,
                tr("ASMS"),
                tr("You must login first") );
    }
}

void MainWindow::load_paintings()
{
    qDebug()<<"Inside Slot loadPaintings";
    ui->actionLog_Out->setText("Log Out");
    buyForm->setUserName(loginForm->getUserName());
    buyForm->loadPaintings();
    buyForm->setUserName(loginForm->getUserName());
    sellForm->loadPaintings();
    profileForm->setData(loginForm->getUserName(), "Owner1", "Address1", 50434240, 34);
}

void MainWindow::on_actionAbout_triggered()
{
    stack->setCurrentWidget(aboutForm);
}

void MainWindow::on_actionProfile_triggered()
{
    if(loginForm->getIsLogged()){
        stack->setCurrentWidget(profileForm);
    }
    else{
        QMessageBox::warning(
                this,
                tr("ASMS"),
                tr("You must login first") );
    }
}
