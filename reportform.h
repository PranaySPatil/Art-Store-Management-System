#ifndef REPORTFORM_H
#define REPORTFORM_H

#include <QWidget>
#include <QDebug>
#include <reportitem.h>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QUrlQuery>

namespace Ui {
class ReportForm;
}

class ReportForm : public QWidget
{
    Q_OBJECT

public:
    explicit ReportForm(int type, QWidget *parent = 0);
    ~ReportForm();

    void setUserName(const QString &value);
    void loadReport();
    void refresh();

private slots:
    void on_pushButtonAverage_clicked();

public slots:
    void serviceRequestFinished(QNetworkReply*);

private:
    Ui::ReportForm *ui;
    QNetworkAccessManager *manager;
    QString userName;
    // type1 - purchase; type2 - sale;
    int row, column, type;
    QUrlQuery postData;
};

#endif // REPORTFORM_H
