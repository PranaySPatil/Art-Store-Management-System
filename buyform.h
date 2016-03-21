#ifndef BUYFORM_H
#define BUYFORM_H

#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrlQuery>

namespace Ui {
class BuyForm;
}

class BuyForm : public QWidget
{
    Q_OBJECT

public:
    explicit BuyForm(QWidget *parent = 0);
    ~BuyForm();
    void loadPaintings();
    QString getUserName() const;
    void setUserName(const QString &value);
    void refresh();

private:
    Ui::BuyForm *ui;
    QNetworkAccessManager *manager;
    QString userName;
    QUrlQuery postData;

public slots:
    void serviceRequestFinished(QNetworkReply*);
};

#endif // BUYFORM_H
