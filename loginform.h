#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>

namespace Ui {
class LogInForm;
}

class LogInForm : public QWidget
{
    Q_OBJECT

public:
    explicit LogInForm(QWidget *parent = 0);
    ~LogInForm();

private:
    Ui::LogInForm *ui;
};

#endif // LOGINFORM_H
