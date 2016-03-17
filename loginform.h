#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrlQuery>

namespace Ui {
class LogInForm;
}

class LogInForm : public QWidget
{
    Q_OBJECT

public:
    explicit LogInForm(QWidget *parent = 0);
    ~LogInForm();
    bool getIsLogged() const;
    QString getUserName() const;
    void setIsLogged(bool value);
    void setUserName(const QString &value);
    void logOut();

private slots:
    void on_pushButtonLogin_clicked();
    void onNetworkResponse(QNetworkReply*);

private:
    QNetworkAccessManager *nam;
    QNetworkReply *reply;
    QUrlQuery postData;
    Ui::LogInForm *ui;
    QString user, pass;
    bool isLogged = false;
    QString userName;
};

#endif // LOGINFORM_H
