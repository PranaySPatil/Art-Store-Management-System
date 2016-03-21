#ifndef PROFILEFORM_H
#define PROFILEFORM_H

#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrlQuery>

namespace Ui {
class ProfileForm;
}

class ProfileForm : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileForm(QWidget *parent = 0);
    ~ProfileForm();
    void setData(QString name, QString owner, QString address, int balance, int no_of_emp);


    void setBalance(int value);

    int getBalance() const;
    void refresh();

    QString getUserName() const;
    void setUserName(const QString &value);

private slots:
    void on_pushButtonEdit_clicked();

    void on_pushButtonSave_clicked();

private:
    Ui::ProfileForm *ui;
    QString name, owner, address;
    int balance, no_of_emp;
    QNetworkAccessManager *manager;
    QString userName;
    QUrlQuery postData;

public slots:
    void serviceRequestFinished(QNetworkReply*);
};

#endif // PROFILEFORM_H
