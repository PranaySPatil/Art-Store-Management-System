#ifndef BUYFORM_H
#define BUYFORM_H

#include <QWidget>

namespace Ui {
class BuyForm;
}

class BuyForm : public QWidget
{
    Q_OBJECT

public:
    explicit BuyForm(QWidget *parent = 0);
    ~BuyForm();

private:
    Ui::BuyForm *ui;
};

#endif // BUYFORM_H
