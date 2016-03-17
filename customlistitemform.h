#ifndef CUSTOMLISTITEMFORM_H
#define CUSTOMLISTITEMFORM_H

#include <QWidget>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

namespace Ui {
class CustomListItemForm;
}

class CustomListItemForm : public QWidget
{
    Q_OBJECT

public:
    explicit CustomListItemForm(QString title, QString artist, QString medium, int price, int type, QString url, QString owner = "", QWidget *parent = 0);
    ~CustomListItemForm();

private:
    Ui::CustomListItemForm *ui;
    QString title;
    QString artist;
    QString medium;
    int price;
    int type;
    QString owner = "";
    QUrl url;

private slots:
    void replyFinished(QNetworkReply* reply);

};

#endif // CUSTOMLISTITEMFORM_H
