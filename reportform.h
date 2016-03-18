#ifndef REPORTFORM_H
#define REPORTFORM_H

#include <QWidget>
#include <QDebug>
#include <reportitem.h>

namespace Ui {
class ReportForm;
}

class ReportForm : public QWidget
{
    Q_OBJECT

public:
    explicit ReportForm(QWidget *parent = 0);
    ~ReportForm();

    void setUserName(const QString &value);
    void loadReport();
    void refresh();

private:
    Ui::ReportForm *ui;
    QString userName;
};

#endif // REPORTFORM_H
