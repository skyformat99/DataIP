/********************************************************************************
** Form generated from reading UI file 'DataIP.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAIP_H
#define UI_DATAIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataIP
{
public:
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget_left;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *icon_label;
    QSpacerItem *horizontalSpacer_7;
    QLabel *title_label;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_center;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QLabel *staus_label_up;
    QLabel *staus_label_down;
    QLabel *time_label;
    QWidget *widget_right;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *info_btn;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *exit_btn;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *DataIP)
    {
        if (DataIP->objectName().isEmpty())
            DataIP->setObjectName(QStringLiteral("DataIP"));
        DataIP->resize(869, 60);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DataIP->sizePolicy().hasHeightForWidth());
        DataIP->setSizePolicy(sizePolicy);
        DataIP->setMinimumSize(QSize(0, 60));
        DataIP->setMaximumSize(QSize(16777215, 60));
        DataIP->setStyleSheet(QStringLiteral(""));
        gridLayout_4 = new QGridLayout(DataIP);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        widget_left = new QWidget(DataIP);
        widget_left->setObjectName(QStringLiteral("widget_left"));
        gridLayout = new QGridLayout(widget_left);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        icon_label = new QLabel(widget_left);
        icon_label->setObjectName(QStringLiteral("icon_label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(icon_label->sizePolicy().hasHeightForWidth());
        icon_label->setSizePolicy(sizePolicy1);
        icon_label->setMinimumSize(QSize(32, 32));
        icon_label->setMaximumSize(QSize(32, 32));

        horizontalLayout->addWidget(icon_label);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        title_label = new QLabel(widget_left);
        title_label->setObjectName(QStringLiteral("title_label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(title_label->sizePolicy().hasHeightForWidth());
        title_label->setSizePolicy(sizePolicy2);
        title_label->setMinimumSize(QSize(200, 0));
        title_label->setMaximumSize(QSize(200, 16777215));

        horizontalLayout->addWidget(title_label);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        horizontalLayout_4->addWidget(widget_left);

        widget_center = new QWidget(DataIP);
        widget_center->setObjectName(QStringLiteral("widget_center"));
        gridLayout_3 = new QGridLayout(widget_center);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        staus_label_up = new QLabel(widget_center);
        staus_label_up->setObjectName(QStringLiteral("staus_label_up"));
        sizePolicy2.setHeightForWidth(staus_label_up->sizePolicy().hasHeightForWidth());
        staus_label_up->setSizePolicy(sizePolicy2);
        staus_label_up->setMinimumSize(QSize(160, 0));
        staus_label_up->setMaximumSize(QSize(160, 16777215));
        staus_label_up->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(staus_label_up);

        staus_label_down = new QLabel(widget_center);
        staus_label_down->setObjectName(QStringLiteral("staus_label_down"));
        sizePolicy2.setHeightForWidth(staus_label_down->sizePolicy().hasHeightForWidth());
        staus_label_down->setSizePolicy(sizePolicy2);
        staus_label_down->setMinimumSize(QSize(160, 0));
        staus_label_down->setMaximumSize(QSize(160, 16777215));
        staus_label_down->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(staus_label_down);


        horizontalLayout_3->addLayout(verticalLayout);

        time_label = new QLabel(widget_center);
        time_label->setObjectName(QStringLiteral("time_label"));
        sizePolicy2.setHeightForWidth(time_label->sizePolicy().hasHeightForWidth());
        time_label->setSizePolicy(sizePolicy2);
        time_label->setMinimumSize(QSize(180, 0));
        time_label->setMaximumSize(QSize(180, 16777215));
        time_label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(time_label);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        horizontalLayout_4->addWidget(widget_center);

        widget_right = new QWidget(DataIP);
        widget_right->setObjectName(QStringLiteral("widget_right"));
        sizePolicy2.setHeightForWidth(widget_right->sizePolicy().hasHeightForWidth());
        widget_right->setSizePolicy(sizePolicy2);
        widget_right->setMinimumSize(QSize(200, 0));
        widget_right->setMaximumSize(QSize(200, 16777215));
        gridLayout_2 = new QGridLayout(widget_right);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        info_btn = new QPushButton(widget_right);
        info_btn->setObjectName(QStringLiteral("info_btn"));
        sizePolicy1.setHeightForWidth(info_btn->sizePolicy().hasHeightForWidth());
        info_btn->setSizePolicy(sizePolicy1);
        info_btn->setMinimumSize(QSize(48, 48));
        info_btn->setMaximumSize(QSize(48, 48));

        horizontalLayout_2->addWidget(info_btn);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        exit_btn = new QPushButton(widget_right);
        exit_btn->setObjectName(QStringLiteral("exit_btn"));
        sizePolicy1.setHeightForWidth(exit_btn->sizePolicy().hasHeightForWidth());
        exit_btn->setSizePolicy(sizePolicy1);
        exit_btn->setMinimumSize(QSize(48, 48));
        exit_btn->setMaximumSize(QSize(48, 48));

        horizontalLayout_2->addWidget(exit_btn);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        horizontalLayout_4->addWidget(widget_right);


        gridLayout_4->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        retranslateUi(DataIP);

        QMetaObject::connectSlotsByName(DataIP);
    } // setupUi

    void retranslateUi(QWidget *DataIP)
    {
        DataIP->setWindowTitle(QApplication::translate("DataIP", "DataIP", Q_NULLPTR));
        icon_label->setText(QString());
        title_label->setText(QString());
        staus_label_up->setText(QString());
        staus_label_down->setText(QString());
        time_label->setText(QString());
        info_btn->setText(QString());
        exit_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DataIP: public Ui_DataIP {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAIP_H
