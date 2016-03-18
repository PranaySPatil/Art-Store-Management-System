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
