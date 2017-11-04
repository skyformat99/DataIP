#include "Login.h"
#include <QDebug>

Login::Login(QWidget *parent) : QDialog(parent)
{
    ui.setupUi(this);
    initlize();
}

Login::~Login()
{

}

void Login::initlize()
{
    ui.userEdit->setPlaceholderText(tr("用户名"));
    ui.pwdEdit->setPlaceholderText(tr("密码"));
    ui.pwdEdit->setImage(":/image/password.png");
    ui.pwdEdit->setEchoMode(QLineEdit::Password);

    ui.userEdit->setText(IniOperator::read("config.ini", "user"));
    ui.pwdEdit->setText(IniOperator::read("config.ini", "pwd"));

    ui.save_pwd->setChecked(true);

    ui.login_btn->setShortcut(QKeySequence::InsertParagraphSeparator);
    ui.login_btn->setShortcut(Qt::Key_Enter);
    ui.login_btn->setShortcut(Qt::Key_Return);
    connect(ui.login_btn, SIGNAL(clicked(bool)), this, SIGNAL(login()));
    connect(ui.exit_btn, SIGNAL(clicked(bool)), this, SIGNAL(quit()));
    connect(ui.config_btn, SIGNAL(clicked(bool)), this, SIGNAL(setup()));
    connect(ui.pwdEdit, SIGNAL(returnPressed()), ui.login_btn, SLOT(click()));

    ui.login_btn->setObjectName("login");
    ui.exit_btn->setObjectName("login");
    ui.config_btn->setObjectName("login");
    ui.pwdEdit->setObjectName("login");
    ui.userEdit->setObjectName("login");
}
