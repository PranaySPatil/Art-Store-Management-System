#ifndef SELLFORM_H
#define SELLFORM_H

#include <QWidget>

namespace Ui {
class SellForm;
}

class SellForm : public QWidget
{
    Q_OBJECT

public:
    explicit SellForm(QWidget *parent = 0);
    ~SellForm();

private:
    Ui::SellForm *ui;
};

#endif // SELLFORM_H
