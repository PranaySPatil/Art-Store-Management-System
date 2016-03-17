#include "loginform.h"
#include "ui_loginform.h"
#include <QMessageBox>

LogInForm::LogInForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogInForm)
{
    ui->setupUi(this);
    nam = new QNetworkAccessManager(this);
}

LogInForm::~LogInForm()
{
    delete ui;
}

void LogInForm::on_pushButtonLogin_clicked()
{
    if(!isLogged){
        user = ui->lineEditUserName->text();
        pass = ui->lineEditPassword->text();
        postData.addQueryItem("uname", user);
        postData.addQueryItem("pass", pass);
        QNetworkRequest request(QUrl("http://localhost:8088/artstore/login.php"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(onNetworkResponse(QNetworkReply*)));
        reply = nam->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
    }
    else{
        isLogged = false;
        userName = "";
        ui->labelWelcome->setText("Log In ");
        ui->lineEditPassword->setReadOnly(isLogged);
        ui->lineEditUserName->setReadOnly(isLogged);
        ui->pushButtonLogin->setText("LogIn");
    }

}

void LogInForm::onNetworkResponse(QNetworkReply *re)
{
    QString response = QObject::tr(re->readAll());
    qDebug() << response;
    if(response == "  <strong>You're Successfully Logged In.</strong>"){
        qDebug() << "in If";
        isLogged = true;
        userName = user;
        ui->labelWelcome->setText("Welcome "+userName);
        ui->lineEditPassword->setReadOnly(isLogged);
        ui->lineEditUserName->setReadOnly(isLogged);
        ui->lineEditPassword->setReadOnly(isLogged);
        ui->lineEditPassword->setText("");
        ui->lineEditUserName->setText("");
        ui->pushButtonLogin->setText("LogOut");
        //qDebug() << (MainWindow.userName);
    }
    else if(response == "  <strong color='red'>Invalid username or password.</strong>"){
        ui->lineEditPassword->setText("");
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Wrong username or password");
        messageBox.setFixedSize(500,200);
    }
}

void LogInForm::setUserName(const QString &value)
{
    userName = value;
}

void LogInForm::logOut()
{
    isLogged = false;
    userName = "";
    ui->labelWelcome->setText("Log In ");
    ui->lineEditPassword->setReadOnly(isLogged);
    ui->lineEditUserName->setReadOnly(isLogged);
    ui->pushButtonLogin->setText("LogIn");
}

void LogInForm::setIsLogged(bool value)
{
    isLogged = value;
}

QString LogInForm::getUserName() const
{
    return userName;
}

bool LogInForm::getIsLogged() const
{
    return isLogged;
}
