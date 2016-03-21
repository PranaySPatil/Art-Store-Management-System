#include "loginform.h"
#include "ui_loginform.h"
#include <QMessageBox>
#include <QtCore>

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
        postData.addQueryItem("username", user);
        postData.addQueryItem("password", pass);
        QNetworkRequest request(QUrl("http://localhost:8088/artstoremgmtsys/login.php"));
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
    QString strReply = QObject::tr(re->readAll());
//    qDebug() << strReply;
    if(strReply.length()>1){
        QString name, owner, address;
        int balance, no_of_emp;
        QJsonParseError *error{nullptr};
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8(), error);
        if(error)
            qDebug()<< error->errorString();
        QJsonObject jsonObject = jsonResponse.object();
        //qDebug() << jsonObject.keys();

        QJsonArray jsonArray = jsonObject["login"].toArray();

        //qDebug() << jsonObject["login"].toArray();
        QJsonObject obj = jsonArray[0].toObject();
//        qDebug()<<obj.value("status").toString();
        if(obj.value("status").toString().compare("Success")==0){
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
            name = obj.value("name").toString();
            owner = obj.value("owner").toString();
            address = obj.value("address").toString();
            balance = obj.value("balance").toString().toInt();
            no_of_emp = obj.value("no_of_emp").toString().toInt();
//            qDebug() << tr("balance: ")+obj.value("balance").toString();
//            qDebug() << tr("no_of_emp: ")+ obj.value("no_of_emp").toString();
            emit loggedIn(name, owner, address, balance, no_of_emp);
            //qDebug() << (MainWindow.userName);
        }
        else if(obj.value("status").toString().compare("Incorrect Password") == 0){
            ui->lineEditPassword->setText("");
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Wrong username or password");
            messageBox.setFixedSize(500,200);
        }
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
