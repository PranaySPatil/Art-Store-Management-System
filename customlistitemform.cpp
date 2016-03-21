#include "customlistitemform.h"
#include "ui_customlistitemform.h"
#include <QInputDialog>


CustomListItemForm::CustomListItemForm(int pid, QString username, QString title, QString artist, QString medium, int price, int type, QString url, QString sold_to, QString owner, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomListItemForm)
{
    ui->setupUi(this);
    this->sold_to = sold_to;
    this->pid = pid;
    this->username = username;
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
    QString reqUrl = reply->url().toString();
    if(reqUrl.compare("http://localhost:8088/artstoremgmtsys/optimal_price.php") == 0){
        QString opt_price = tr(reply->readAll());
        qDebug()<<opt_price;
        if(opt_price.compare("Sorry, no data exists for selected painting") == 0){
            QMessageBox::warning(
                    this,
                    tr("ASMS"),
                    tr("Sorry, no data exists for selected painting") );
        }
        else{
            QMessageBox::information(
                    this,
                    tr("ASMS"),
                    tr("Optimal Price: ")+opt_price );

        }
    }
    else if(reqUrl.compare("http://localhost:8088/artstoremgmtsys/buy.php") == 0){
//        qDebug()<<"Buy Response";
//        qDebug()<<tr(reply->readAll());
    }
    else if(reqUrl.compare("http://localhost:8088/artstoremgmtsys/sell.php") == 0){
//        qDebug()<<"Sell Response";
//        qDebug()<<tr(reply->readAll());
    }
    else{
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
        if(type == 2)
            ui->labelPriceKey->setText("Purchased At");
        if(type == 1)
            ui->labelOwner->setText(owner);
        if(sell == 1){
            ui->pushButtonBuyOrSell->setText("Sold");
            //ui->pushButtonBuyOrSell->setDisabled(true);
        }
    }

}

void CustomListItemForm::on_labelImage_linkActivated(const QString &link)
{

}

void CustomListItemForm::on_pushButtonBuyOrSell_clicked()
{
// Sell : type 2 ; Buy : type 1
    if(type == 1){
        QNetworkAccessManager *manager = new QNetworkAccessManager();
        postData.addQueryItem("username", username);
        postData.addQueryItem("seller", sold_to);
        postData.addQueryItem("price", QString::number(price));
        postData.addQueryItem("pid", QString::number(pid));
        QUrl url("http://localhost:8088/artstoremgmtsys/buy.php");
        QNetworkRequest request(url);
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
        connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
        QNetworkReply* reply = manager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
        ui->pushButtonBuyOrSell->setText("Bought");
        ui->pushButtonBuyOrSell->setDisabled(true);
    }
    else if(type == 2){
        bool ok;
        QString text = QInputDialog::getText(this, "Value",
                           "Please Enter the selling price", QLineEdit::Normal, 0, &ok);
        if(ok){
            //qDebug() << text;
            QNetworkAccessManager *manager = new QNetworkAccessManager();
            postData.addQueryItem("username", username);
            postData.addQueryItem("price", text);
            postData.addQueryItem("pid", QString::number(pid));
            QUrl url("http://localhost:8088/artstoremgmtsys/sell.php");
            QNetworkRequest request(url);
            request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
            connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
            QNetworkReply* reply = manager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
            ui->pushButtonBuyOrSell->setText("Sold");
//            ui->pushButtonBuyOrSell->setDisabled(true);
        }

    }
}

void CustomListItemForm::on_pushButtonOptimalPrice_clicked()
{
    //qDebug()<<"Opt Price";
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    postData.addQueryItem("pid", QString::number(pid));
    QUrl url("http://localhost:8088/artstoremgmtsys/optimal_price.php");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    QNetworkReply* reply = manager->post(request, postData.toString(QUrl::FullyEncoded).toUtf8());
}
