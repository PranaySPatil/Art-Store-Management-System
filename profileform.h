#ifndef PROFILEFORM_H
#define PROFILEFORM_H

#include <QWidget>

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


private slots:
    void on_pushButtonEdit_clicked();

    void on_pushButtonSave_clicked();

private:
    Ui::ProfileForm *ui;
    QString name, owner, address;
    int balance, no_of_emp;
};

#endif // PROFILEFORM_H
