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

void ReportForm::setUserName(const QString &value)
{
    userName = value;
}

void ReportForm::loadReport()
{
    QTableWidgetItem *item;
    ReportItem *rItem;
    QStringList headers;
    ui->tableWidgetReport->setColumnCount(6);
    ui->tableWidgetReport->setRowCount(5);
    ui->tableWidgetReport->setEditTriggers(QAbstractItemView::NoEditTriggers);
    headers<<"Painting"<<"Artist"<<"Subject"<<"Date"<<"Purchased Price"<<"Optimal Price";
    ui->tableWidgetReport->setHorizontalHeaderLabels(headers);
    for(int i=0;i<10;i++){
        for(int j=0;j<6;j++){
            item = new QTableWidgetItem();
            item->setText(QString::number(i+j));
            ui->tableWidgetReport->setItem(i, j, item);
        }
    }
}

void ReportForm::refresh()
{
    ui->tableWidgetReport->clear();
    loadReport();
}
