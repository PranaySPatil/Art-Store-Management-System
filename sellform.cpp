#include "sellform.h"
#include "ui_sellform.h"

SellForm::SellForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SellForm)
{
    ui->setupUi(this);
}

SellForm::~SellForm()
{
    delete ui;
}
