#include "customlistitemform.h"
#include "ui_customlistitemform.h"

CustomListItemForm::CustomListItemForm(QString title, QString artist, QString medium, int price, int type, QString url, QString owner, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomListItemForm)
{
    ui->setupUi(this);
    this->title = title;
    this->artist = artist;
    this->medium = medium;
    this->price = price;
    this->type = type;
    this->owner = owner;
    this->url = QUrl(url);
    if(type==1)
        ui->pushButtonBuyOrSell->setText("Buy");
    else
        ui->pushButtonBuyOrSell->setText("Sell");
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(url));
}


CustomListItemForm::~CustomListItemForm()
{
    delete ui;
}

void CustomListItemForm::replyFinished(QNetworkReply *reply)
{
    QImage* img2 = new QImage();
    img2->loadFromData(reply->readAll());

    if(img2->isNull())
        qDebug() << "oops";

//    ui->label->setFixedWidth(400);
//    ui->label->setFixedHeight(400);
      ui->labelImage->setPixmap(QPixmap::fromImage(*img2));
}
