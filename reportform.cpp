#include "reportform.h"
#include "ui_reportform.h"
#include <QtCore>

ReportForm::ReportForm(int type, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReportForm)
{
    this->type = type;
    ui->setupUi(this);
    manager = new QNetworkAccessManager;
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(serviceRequestFinished(QNetworkReply*)));
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
    postData.addQueryItem("username", userName);
    if(type == 1){
        QUrl url("http://localhost:8088/artstoremgmtsys/purchase_report.php");
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        QNetworkReply* reply = manager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
    }
    else{
        QUrl url("http://localhost:8088/artstoremgmtsys/sale_report.php");
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        QNetworkReply* reply = manager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
    }
}

void ReportForm::refresh()
{
    ui->tableWidgetReport->clear();
    loadReport();
}

void ReportForm::on_pushButtonAverage_clicked()
{
    float total_opt = 0, tol_spent = 0;
    for(int i=0;i<ui->tableWidgetReport->rowCount();i++){
        total_opt += ui->tableWidgetReport->item(i, 5)->text().toFloat();
        tol_spent += ui->tableWidgetReport->item(i, 4)->text().toFloat();
//        qDebug()<<QString::number(i)+tr(". tol spent ")+QString::number(tol_spent)+tr(", total_opt ")+QString::number(total_opt);
    }
//    qDebug()<<QString::number(tol_spent/total_opt);
    if(total_opt != 0)
        ui->labelAverage->setText(QString::number(tol_spent/total_opt));
}

void ReportForm::serviceRequestFinished(QNetworkReply *re)
{
    QTableWidgetItem *item;
    QStringList headers;
    ui->tableWidgetReport->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QString strReply = tr(re->readAll());
//    qDebug()<<strReply;
    QJsonParseError *error{nullptr};
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8(), error);
    if(error)
        qDebug()<< error->errorString();
    QJsonObject jsonObject = jsonResponse.object();
//    qDebug() << jsonObject.keys();

    QJsonArray jsonArray;
    if(type == 1)
         jsonArray = jsonObject["purchase_report"].toArray();
    else
        jsonArray = jsonObject["sale_report"].toArray();
    if(type == 1)
        headers<<"Painting"<<"Artist"<<"Subject"<<"Date"<<"Purchase Price"<<"Optimal Price";
    else
        headers<<"Painting"<<"Artist"<<"Subject"<<"Date"<<"Selling Price"<<"Optimal Price";
    int i = 0;
    foreach (const QJsonValue & v, jsonArray){
        i++;
    }
    column = 6;
    row = i;
    ui->tableWidgetReport->setColumnCount(column);
    ui->tableWidgetReport->setRowCount(row);
    ui->tableWidgetReport->setHorizontalHeaderLabels(headers);
    i = 0;
    foreach (const QJsonValue & v, jsonArray){
//        qDebug()<<v.toObject();
        QString title = v.toObject().value("painting_name").toString();
        QString artist = v.toObject().value("artist_name").toString();
        QString subject = v.toObject().value("subject").toString(), price;
        if(type == 1)
            price = v.toObject().value("purchase_price").toString();
        else
            price = v.toObject().value("selling_price").toString();
        QString opt_price = v.toObject().value("optimal_price").toString();
        QString date = v.toObject().value("date").toString();
        item = new QTableWidgetItem();
        item->setText(title);
        ui->tableWidgetReport->setItem(i, 0, item);
        item = new QTableWidgetItem();
        item->setText(artist);
        ui->tableWidgetReport->setItem(i, 1, item);
        item = new QTableWidgetItem();
        item->setText(subject);
        ui->tableWidgetReport->setItem(i, 2, item);
        item = new QTableWidgetItem();
        item->setText(date);
        ui->tableWidgetReport->setItem(i, 3, item);
        item = new QTableWidgetItem();
        item->setText(price);
        ui->tableWidgetReport->setItem(i, 4, item);
        item = new QTableWidgetItem();
        item->setText(opt_price);
        ui->tableWidgetReport->setItem(i, 5, item);
        i++;
    }
}
