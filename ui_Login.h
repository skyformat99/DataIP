/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "LineEdit.h"

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    LineEdit *userEdit;
    LineEdit *pwdEdit;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *save_pwd;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *login_btn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *exit_btn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *config_btn;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
        Login->setSizePolicy(sizePolicy);
        Login->setMinimumSize(QSize(400, 300));
        Login->setMaximumSize(QSize(400, 300));
        gridLayout = new QGridLayout(Login);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        userEdit = new LineEdit(Login);
        userEdit->setObjectName(QStringLiteral("userEdit"));
        userEdit->setMinimumSize(QSize(300, 46));
        userEdit->setMaximumSize(QSize(16777215, 46));

        verticalLayout->addWidget(userEdit);

        pwdEdit = new LineEdit(Login);
        pwdEdit->setObjectName(QStringLiteral("pwdEdit"));
        pwdEdit->setMinimumSize(QSize(300, 46));
        pwdEdit->setMaximumSize(QSize(16777215, 46));

        verticalLayout->addWidget(pwdEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        save_pwd = new QCheckBox(Login);
        save_pwd->setObjectName(QStringLiteral("save_pwd"));
        save_pwd->setMinimumSize(QSize(0, 25));
        save_pwd->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(save_pwd);

        horizontalSpacer = new QSpacerItem(208, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        login_btn = new QPushButton(Login);
        login_btn->setObjectName(QStringLiteral("login_btn"));
        sizePolicy.setHeightForWidth(login_btn->sizePolicy().hasHeightForWidth());
        login_btn->setSizePolicy(sizePolicy);
        login_btn->setMinimumSize(QSize(100, 30));
        login_btn->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(login_btn);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        exit_btn = new QPushButton(Login);
        exit_btn->setObjectName(QStringLiteral("exit_btn"));
        sizePolicy.setHeightForWidth(exit_btn->sizePolicy().hasHeightForWidth());
        exit_btn->setSizePolicy(sizePolicy);
        exit_btn->setMinimumSize(QSize(100, 30));
        exit_btn->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(exit_btn);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        config_btn = new QPushButton(Login);
        config_btn->setObjectName(QStringLiteral("config_btn"));
        sizePolicy.setHeightForWidth(config_btn->sizePolicy().hasHeightForWidth());
        config_btn->setSizePolicy(sizePolicy);
        config_btn->setMinimumSize(QSize(100, 30));
        config_btn->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(config_btn);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", Q_NULLPTR));
        save_pwd->setText(QApplication::translate("Login", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
        login_btn->setText(QApplication::translate("Login", "\347\231\273\351\231\206", Q_NULLPTR));
        exit_btn->setText(QApplication::translate("Login", "\351\200\200\345\207\272", Q_NULLPTR));
        config_btn->setText(QApplication::translate("Login", "\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
