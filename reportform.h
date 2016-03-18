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

private:
    Ui::ReportForm *ui;
};

#endif // REPORTFORM_H
