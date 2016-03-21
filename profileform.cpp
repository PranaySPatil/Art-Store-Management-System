#include "profileform.h"
#include "ui_profileform.h"

ProfileForm::ProfileForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileForm)
{
    ui->setupUi(this);
    ui->lineEditAddress->setReadOnly(true);
    ui->lineEditBalance->setReadOnly(true);
    ui->lineEditEmp->setReadOnly(true);
    ui->lineEditName->setReadOnly(true);
    ui->lineEditOwner->setReadOnly(true);
    ui->pushButtonSave->setEnabled(false);
    manager = new QNetworkAccessManager;
}

ProfileForm::~ProfileForm()
{
    delete ui;
}

void ProfileForm::setData(QString name, QString owner, QString address, int balance, int no_of_emp)
{
    this->name = name;
    this->owner = owner;
    this->address = address;
    this->balance = balance;
    this->no_of_emp = no_of_emp;
    ui->lineEditAddress->setText(address);
    ui->lineEditBalance->setText(QString::number(balance));
    ui->lineEditEmp->setText(QString::number(no_of_emp));
    ui->lineEditName->setText(name);
    ui->lineEditOwner->setText(owner);
}

void ProfileForm::on_pushButtonEdit_clicked()
{
    ui->lineEditAddress->setReadOnly(false);
    ui->lineEditBalance->setReadOnly(false);
    ui->lineEditEmp->setReadOnly(false);
    ui->lineEditName->setReadOnly(false);
    ui->lineEditOwner->setReadOnly(false);
    ui->pushButtonSave->setEnabled(true);
    ui->pushButtonEdit->setEnabled(false);
}

void ProfileForm::on_pushButtonSave_clicked()
{
    // Save to DB
    postData.addQueryItem("username", userName);
    postData.addQueryItem("name", ui->lineEditName->text());
    postData.addQueryItem("owner", ui->lineEditOwner->text());
    postData.addQueryItem("address", ui->lineEditAddress->text());
    postData.addQueryItem("balance", ui->lineEditBalance->text());
    postData.addQueryItem("no_of_emp",ui->lineEditEmp->text());
    QUrl url("http://localhost:8088/artstoremgmtsys/update_details.php");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(serviceRequestFinished(QNetworkReply*)));
    QNetworkReply* reply = manager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
    ui->lineEditAddress->setReadOnly(true);
    ui->lineEditBalance->setReadOnly(true);
    ui->lineEditEmp->setReadOnly(true);
    ui->lineEditName->setReadOnly(true);
    ui->lineEditOwner->setReadOnly(true);
    ui->pushButtonEdit->setEnabled(true);
    ui->pushButtonSave->setEnabled(false);
    name = ui->lineEditName->text();
    address = ui->lineEditAddress->text();
    owner = ui->lineEditOwner->text();
    balance = ui->lineEditBalance->text().toInt();
    no_of_emp = ui->lineEditEmp->text().toInt();
}

void ProfileForm::serviceRequestFinished(QNetworkReply *re)
{
    qDebug()<<tr(re->readAll());
}

QString ProfileForm::getUserName() const
{
    return userName;
}

void ProfileForm::setUserName(const QString &value)
{
    userName = value;
}

int ProfileForm::getBalance() const
{
    return balance;
}

void ProfileForm::refresh()
{
    ui->lineEditBalance->setText(QString::number(balance));
}

void ProfileForm::setBalance(int value)
{
    balance = value;
}
