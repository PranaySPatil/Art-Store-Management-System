#include "buyform.h"
#include "ui_buyform.h"
#include <QLabel>
#include <QPushButton>
#include <iostream>
#include <QtCore>
#include "customlistitemform.h"
using namespace std;

BuyForm::BuyForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuyForm)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager;
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(serviceRequestFinished(QNetworkReply*)));
}

BuyForm::~BuyForm()
{
    delete ui;
}

void BuyForm::loadPaintings()
{
    postData.addQueryItem("username", userName);
    QUrl url("http://localhost:8088/artstoremgmtsys/available_paintings.php");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QNetworkReply* reply = manager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
}

QString BuyForm::getUserName() const
{
    return userName;
}

void BuyForm::setUserName(const QString &value)
{
    userName = value;
}

void BuyForm::refresh()
{
    ui->listWidgetBuy->clear();
    loadPaintings();
}

void BuyForm::serviceRequestFinished(QNetworkReply *re)
{
    QString strReply = tr(re->readAll());
//    qDebug() << strReply;
    QJsonParseError *error{nullptr};
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8(), error);
    if(error)
        qDebug()<< error->errorString();
    QJsonObject jsonObject = jsonResponse.object();
//    qDebug() << jsonObject.keys();

    QJsonArray jsonArray = jsonObject["available"].toArray();

//    qDebug() << jsonObject["available"].toArray();
    foreach (const QJsonValue & v, jsonArray){
        QJsonObject obj = v.toObject();
//        qDebug() << obj;
        int type = 1;
        QString title = v.toObject().value("painting_name").toString();
        QString artist = v.toObject().value("artist_name").toString();
        QString owner = v.toObject().value("current_artstore").toString();
        QString sold_to = v.toObject().value("sold_to").toString();
        int price = v.toObject().value("price").toString().toInt();
        QString medium = v.toObject().value("medium").toString();
        int pid = v.toObject().value("pid").toString().toInt();
        QListWidgetItem* item;
        QString url = "http://localhost:8088/artstoremgmtsys/paintings/";
        url = url + v.toObject().value("url").toString();
//        qDebug()<<url;
        //url = "http://localhost:8088/artstoremgmtsys/paintings/empty_room.jpeg";
        CustomListItemForm *widget = new CustomListItemForm(pid, userName, title, artist, medium, price, type, url, sold_to, owner);
        item = new QListWidgetItem(ui->listWidgetBuy);
        item->setSizeHint(*(new QSize(120, 150)));
        ui->listWidgetBuy->addItem(item);
        ui->listWidgetBuy->setItemWidget(item, widget);
    }
}

