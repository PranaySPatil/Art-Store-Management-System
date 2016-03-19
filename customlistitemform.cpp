#include "customlistitemform.h"
#include "ui_customlistitemform.h"
#include <QInputDialog>


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
    else{
        ui->pushButtonBuyOrSell->setText("Sell");

    }
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(url));
}


CustomListItemForm::~CustomListItemForm()
{
    delete ui;
}

int CustomListItemForm::getSell() const
{
    return sell;
}

void CustomListItemForm::setSell(int value)
{
    sell = value;
}

void CustomListItemForm::replyFinished(QNetworkReply *reply)
{
    QImage* img2 = new QImage();
    img2->loadFromData(reply->readAll());

    if(img2->isNull())
        qDebug() << "oops";
    QPixmap qPixMap = QPixmap::fromImage(*img2);
    ui->labelImage->setPixmap(qPixMap);
    ui->labelImage->setScaledContents( true );
    ui->labelImage->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    ui->labelMedium->setText(medium);
    ui->labelArtist->setText(artist);
    ui->labelPrice->setText(QString::number(price));
    ui->labelTitle->setText(title);
    ui->labelOwner->setText("You");
    if(type == 1)
        ui->labelOwner->setText(owner);
    if(sell == 1)
        ui->pushButtonBuyOrSell->setText("Sold");
}

void CustomListItemForm::on_labelImage_linkActivated(const QString &link)
{

}

void CustomListItemForm::on_pushButtonBuyOrSell_clicked()
{
// Sell : type 2 ; Buy : type 1
    if(type == 1){

    }
    else if(type == 2){
        bool ok;
        QString text = QInputDialog::getText(this, "Value",
                           "Please Enter the selling price", QLineEdit::Normal, 0, &ok);
        if(ok)
            qDebug() << text;
    }
}
