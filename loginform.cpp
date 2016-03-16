#include "loginform.h"
#include "ui_loginform.h"

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
    user = ui->lineEditUserName->text();
    pass = ui->lineEditPassword->text();
    postData.addQueryItem("uname", user);
    postData.addQueryItem("pass", pass);
    QNetworkRequest request(QUrl("http://localhost:8088/artstore/login.php"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(onNetworkResponse(QNetworkReply*)));
    reply = nam->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
}

void LogInForm::onNetworkResponse(QNetworkReply *re)
{
    QString response = QObject::tr(re->readAll());
    qDebug() << response;
    if(response == "  <strong>You're Successfully Logged In.</strong>"){
        qDebug() << "in If";
        isLogged = true;
        userName = user;
        //qDebug() << (MainWindow.userName);
    }
    else{
        ui->lineEditPassword->setText("");
    }
}

void LogInForm::setUserName(const QString &value)
{
    userName = value;
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
