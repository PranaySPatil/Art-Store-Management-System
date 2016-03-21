#include "sellform.h"
#include "ui_sellform.h"
#include <QLabel>
#include <QPushButton>
#include <iostream>
#include <QtCore>
#include "customlistitemform.h"
using namespace std;

SellForm::SellForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SellForm)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager;
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(serviceRequestFinished(QNetworkReply*)));
}

SellForm::~SellForm()
{
    delete ui;
}

void SellForm::loadPaintings()
{
    postData.addQueryItem("username", userName);
    QUrl url("http://localhost:8088/artstoremgmtsys/owned_paintings.php");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QNetworkReply* reply = manager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
}

QString SellForm::getUserName() const
{
    return userName;
}

void SellForm::setUserName(const QString &value)
{
    userName = value;
}

void SellForm::refresh()
{
    ui->listWidgetSell->clear();
    loadPaintings();
}

void SellForm::serviceRequestFinished(QNetworkReply *re)
{
    QString strReply = tr(re->readAll());
//    qDebug() << strReply;
    QJsonParseError *error{nullptr};
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8(), error);
    if(error)
        qDebug()<< error->errorString();
    QJsonObject jsonObject = jsonResponse.object();
//    qDebug() << jsonObject.keys();

    QJsonArray jsonArray = jsonObject["owned"].toArray();

//    qDebug() << jsonObject["available"].toArray();
    foreach (const QJsonValue & v, jsonArray){
        QJsonObject obj = v.toObject();
//        qDebug() << obj;
        int type = 2;
        QString title = v.toObject().value("painting_name").toString();
        QString artist = v.toObject().value("artist_name").toString();
        int pid = v.toObject().value("pid").toString().toInt();
        QString medium = v.toObject().value("medium").toString();
        int sell = v.toObject().value("sell").toString().toInt();
        QListWidgetItem* item;
        QString url = "http://localhost:8088/artstoremgmtsys/paintings/";
        url = url + v.toObject().value("url").toString();
        qDebug()<<url;
        CustomListItemForm *widget = new CustomListItemForm(pid, userName, title, artist, medium, 0, type, url);
        widget->setSell(sell);
        item = new QListWidgetItem(ui->listWidgetSell);
        item->setSizeHint(*(new QSize(120, 150)));
        ui->listWidgetSell->addItem(item);
        ui->listWidgetSell->setItemWidget(item, widget);
    }
}
