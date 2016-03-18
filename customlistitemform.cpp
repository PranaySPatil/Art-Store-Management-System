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
    QPixmap qPixMap = QPixmap::fromImage(*img2);
    ui->labelImage->setPixmap(qPixMap);
    ui->labelImage->setScaledContents( true );
    ui->labelImage->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    ui->labelMedium->setText(medium);
}

void CustomListItemForm::on_labelImage_linkActivated(const QString &link)
{

}

void CustomListItemForm::on_pushButtonBuyOrSell_clicked()
{

}
