#ifndef SELLFORM_H
#define SELLFORM_H

#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrlQuery>

namespace Ui {
class SellForm;
}

class SellForm : public QWidget
{
    Q_OBJECT

public:
    explicit SellForm(QWidget *parent = 0);
    ~SellForm();
    void loadPaintings();
    QString getUserName() const;
    void setUserName(const QString &value);
    void refresh();

private:
    Ui::SellForm *ui;
    QNetworkAccessManager *manager;
    QString userName;
    QUrlQuery postData;

public slots:
    void serviceRequestFinished(QNetworkReply*);
};

#endif // SELLFORM_H
