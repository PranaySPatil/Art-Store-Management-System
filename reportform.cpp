#include "reportform.h"
#include "ui_reportform.h"

ReportForm::ReportForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportForm)
{
    ui->setupUi(this);
    QTableWidgetItem *item;
    QStringList headers;
    headers<<"Painting"<<"Artist"<<"Subject"<<"Purchased Price"<<"Optimal Price"<<"Date";
    ui->tableWidgetReport->setHorizontalHeaderLabels(headers);
    ui->tableWidgetReport->show();
}

ReportForm::~ReportForm()
{
    delete ui;
}
