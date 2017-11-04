#include "ChangePassword.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

#define SAFE_DEL(p) if(p) { delete p; p = nullptr; }
#define LabelWidth 80

ChangePassword::ChangePassword(QWidget *parent) : QWidget(parent)
{
    setFixedSize(320, 200);
    m_oldLabel = new QLabel(tr("旧密码："), this);
    m_newLabel = new QLabel(tr("新密码："), this);
    m_newReLabel = new QLabel(tr("确  认："), this);

    m_oldEdit = new QLineEdit(this);
    m_newEdit = new QLineEdit(this);
    m_newReEdit = new QLineEdit(this);

    m_okBtn = new QPushButton(tr("确定"), this);
    m_cancleBtn = new QPushButton(tr("取消"), this);
    m_okBtn->setObjectName("btn");
    m_cancleBtn->setObjectName("btn");
    m_okBtn->setDisabled(true);
    m_cancleBtn->setDisabled(true);

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(m_oldLabel, 0, 0);
    gridLayout->addWidget(m_oldEdit, 0, 1);
    gridLayout->addWidget(m_newLabel, 1, 0);
    gridLayout->addWidget(m_newEdit, 1, 1);
    gridLayout->addWidget(m_newReLabel, 2, 0);
    gridLayout->addWidget(m_newReEdit, 2, 1);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addStretch();
    hLayout->addWidget(m_okBtn);
    hLayout->addWidget(m_cancleBtn);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(gridLayout);
    mainLayout->addLayout(hLayout);

    connect(m_oldEdit, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged()));
    connect(m_newEdit, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged()));
    connect(m_newReEdit, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged()));
    connect(m_okBtn, SIGNAL(clicked(bool)), this, SLOT(onOkBtnClicked()));
    connect(m_cancleBtn, SIGNAL(clicked(bool)), this, SLOT(onCancleBtnClicked()));
}

ChangePassword::~ChangePassword()
{

}

void ChangePassword::onTextChanged()
{
    bool flg = false;
    if(m_oldEdit->text().isEmpty() || m_newEdit->text().isEmpty() || m_newReEdit->text().isEmpty())
    {
        flg = true;
    }
    m_okBtn->setDisabled(flg);
    m_cancleBtn->setDisabled(flg);
}

void ChangePassword::onOkBtnClicked()
{

}

void ChangePassword::onCancleBtnClicked()
{

}
