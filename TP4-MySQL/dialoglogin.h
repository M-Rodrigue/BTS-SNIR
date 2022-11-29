#ifndef DIALOGLOGIN_H
#define DIALOGLOGIN_H

#include <QDialog>

namespace Ui {
class DialogLogin;
}

class DialogLogin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLogin(QWidget *parent = 0);
    ~DialogLogin();

private:
    Ui::DialogLogin *ui;

private slots:
    void on_buttonBox_accepted();
};

#endif // DIALOGLOGIN_H
