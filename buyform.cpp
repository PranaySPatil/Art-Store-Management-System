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
    QUrl url("http://localhost:8088/artstore/get_paintings.php");
    QNetworkReply* reply = manager->get(QNetworkRequest(url));
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
    //strReply.replace(tr("\""), tr(""));
    //strReply.append(".");
    qDebug() << strReply;
    QJsonParseError *error{nullptr};
    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8(), error);
    if(error)
        qDebug()<< error->errorString();
    QJsonObject jsonObject = jsonResponse.object();
    qDebug() << jsonObject.keys();

    QJsonArray jsonArray = jsonObject["testData"].toArray();

    qDebug() << jsonObject["testData"].toArray();
    foreach (const QJsonValue & v, jsonArray){
        QJsonObject obj = v.toObject();
        qDebug() << obj;
        int type, id = v.toObject().value("id").toString().toInt();
        QString title = v.toObject().value("title").toString();
        QString artist = v.toObject().value("artist").toString();
        QString owner = v.toObject().value("artstore").toString();
        int price = v.toObject().value("price").toString().toInt();
        QListWidgetItem* item;
        QString url = "http://localhost:8088/artstore/paintings/painting1.jpeg", medium = "WaterColor";
        CustomListItemForm *widget = new CustomListItemForm(title, artist, medium, price, 1, url, owner);
        item = new QListWidgetItem(ui->listWidgetBuy);
        item->setSizeHint(*(new QSize(120, 150)));
        ui->listWidgetBuy->addItem(item);
        ui->listWidgetBuy->setItemWidget(item, widget);
    }
}

