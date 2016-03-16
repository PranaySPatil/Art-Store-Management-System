#include "reportform.h"
#include "ui_reportform.h"

ReportForm::ReportForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportForm)
{
    ui->setupUi(this);
}

ReportForm::~ReportForm()
{
    delete ui;
}
