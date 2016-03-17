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
    QUrl url("http://localhost:8088/artstore/get_paintings.php");
    QNetworkReply* reply = manager->get(QNetworkRequest(url));
}

QString SellForm::getUserName() const
{
    return userName;
}

void SellForm::setUserName(const QString &value)
{
    userName = value;
}

void SellForm::serviceRequestFinished(QNetworkReply *re)
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
        QString url, medium;
        CustomListItemForm *widget = new CustomListItemForm(title, artist, medium, price, 2, url);
        item = new QListWidgetItem(ui->listWidgetSell);
        item->setSizeHint(*(new QSize(120, 80)));
        ui->listWidgetSell->addItem(item);
        ui->listWidgetSell->setItemWidget(item, widget);
    }
}
