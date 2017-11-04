#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "ui_Login.h"
#include "IniOperator.h"

class Login : public QDialog
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);
    virtual ~Login();

    QString getUserName()
    {
        return ui.userEdit->text();
    }
    QString getPassWord()
    {
        return ui.pwdEdit->text();
    }
    bool savePwd()
    {
        return ui.save_pwd->isChecked();
    }

signals:
    void login();
    void quit();
    void setup();

private:
    void initlize();

private:
    Ui::Login ui;
};

#endif // LOGIN_H
