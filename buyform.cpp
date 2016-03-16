#include "buyform.h"
#include "ui_buyform.h"

BuyForm::BuyForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuyForm)
{
    ui->setupUi(this);
}

BuyForm::~BuyForm()
{
    delete ui;
}
