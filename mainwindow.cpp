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
    buyReportForm = new ReportForm(1);
    sellReportForm = new ReportForm(2);
    loginForm = new LogInForm;
    aboutForm = new AboutForm;
    profileForm = new ProfileForm;
    stack = ui->stackedWidget;
    stack->addWidget(loginForm);
    stack->addWidget(buyForm);
    stack->addWidget(sellForm);
    stack->addWidget(buyReportForm);
    stack->addWidget(sellReportForm);
    stack->addWidget(aboutForm);
    stack->addWidget(profileForm);
    stack->setCurrentWidget(loginForm);
    QObject::connect(loginForm, SIGNAL(loggedIn(QString , QString, QString, int, int)), this, SLOT(load_paintings(QString , QString, QString, int, int)));
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
//        qDebug() << "Buy for";
//        qDebug() << loginForm->getUserName();
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
        delete(sellReportForm);
        delete(buyReportForm);
        buyForm = new BuyForm;
        sellForm = new SellForm;
        buyReportForm = new ReportForm(1);
        sellReportForm = new ReportForm(2);
        QObject::connect(buyForm, SIGNAL(refresh_balance(int)), this, SLOT(refresh_balance(int)));
        stack->addWidget(buyForm);
        stack->addWidget(sellForm);
        stack->addWidget(buyReportForm);
        stack->addWidget(sellReportForm);
    }
    else{
        stack->setCurrentWidget(loginForm);
    }

}

void MainWindow::on_actionSell_triggered()
{
    if(loginForm->getIsLogged()){
        stack->setCurrentWidget(sellForm);
//        qDebug() << "Sell for";
//        qDebug() << loginForm->getUserName();
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
    if(loginForm->getIsLogged()){
        QMessageBox msgBox(
                    QMessageBox::Question,
                    trUtf8("Which Report?"),
                    "Buy/Sell",
                    QMessageBox::Yes | QMessageBox::No);

        msgBox.setButtonText(QMessageBox::Yes, trUtf8("Purchase"));
        msgBox.setButtonText(QMessageBox::No, trUtf8("Sale"));

        if (msgBox.exec() == QMessageBox::No) {
//            qDebug()<<"Sale Report";
            stack->setCurrentWidget(sellReportForm);
        }
        else{
//            qDebug()<<"Purchase Report";
            stack->setCurrentWidget(buyReportForm);
        }

    }
    else{
        QMessageBox::warning(
                this,
                tr("ASMS"),
                tr("You must login first") );
    }
}

void MainWindow::on_actionRefresh_triggered()
{
    if(loginForm->getIsLogged()){
        buyForm->setUserName(loginForm->getUserName());
        buyForm->refresh();
        sellForm->setUserName(loginForm->getUserName());
        sellForm->refresh();
        buyReportForm->setUserName(loginForm->getUserName());
        buyReportForm->refresh();
        sellReportForm->setUserName(loginForm->getUserName());
        sellReportForm->refresh();
        profileForm->setUserName(loginForm->getUserName());
        profileForm->refresh();
    }
    else{
        QMessageBox::warning(
                this,
                tr("ASMS"),
                tr("You must login first") );
    }
}

void MainWindow::load_paintings(QString name, QString owner, QString address, int balance, int no_of_emp)
{
//    qDebug()<<"Inside Slot loadPaintings";
    ui->actionLog_Out->setText("Log Out");
    buyForm->setUserName(loginForm->getUserName());
    buyForm->loadPaintings();
    sellForm->setUserName(loginForm->getUserName());
    sellForm->loadPaintings();
    buyReportForm->setUserName(loginForm->getUserName());
    buyReportForm->loadReport();
    sellReportForm->setUserName(loginForm->getUserName());
    sellReportForm->loadReport();
    this->balance = balance;
    profileForm->setUserName(loginForm->getUserName());
    profileForm->setData(name, owner, address, balance, no_of_emp);
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
