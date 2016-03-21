#ifndef CUSTOMLISTITEMFORM_H
#define CUSTOMLISTITEMFORM_H

#include <QWidget>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QMessageBox>

namespace Ui {
class CustomListItemForm;
}

class CustomListItemForm : public QWidget
{
    Q_OBJECT

public:
    explicit CustomListItemForm(int pid, QString username, QString title, QString artist, QString medium, int price, int type, QString url, QString sold_to="", QString owner = "", QWidget *parent = 0);
    ~CustomListItemForm();

    int getSell() const;
    void setSell(int value);
signals:
    void painting_bought(int price);

private:
    Ui::CustomListItemForm *ui;
    QString title;
    QString artist;
    QString medium;
    QString username, sold_to;
    int price;
    int type;
    QString owner = "";
    QUrl url;
    int sell, pid;
    QUrlQuery postData;

private slots:
    void replyFinished(QNetworkReply* reply);

    void on_labelImage_linkActivated(const QString &link);
    void on_pushButtonBuyOrSell_clicked();
    void on_pushButtonOptimalPrice_clicked();
};

#endif // CUSTOMLISTITEMFORM_H
