/********************************************************************************
** Form generated from reading UI file 'DataPosition.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAPOSITION_H
#define UI_DATAPOSITION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataPosition
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_left;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_pos;
    QLabel *label_begin;
    QLabel *label_between;
    QLabel *label_end;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_search;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *DataPosition)
    {
        if (DataPosition->objectName().isEmpty())
            DataPosition->setObjectName(QStringLiteral("DataPosition"));
        DataPosition->resize(744, 50);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DataPosition->sizePolicy().hasHeightForWidth());
        DataPosition->setSizePolicy(sizePolicy);
        DataPosition->setMinimumSize(QSize(0, 50));
        DataPosition->setMaximumSize(QSize(16777215, 50));
        DataPosition->setStyleSheet(QStringLiteral(""));
        gridLayout_3 = new QGridLayout(DataPosition);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widget_left = new QWidget(DataPosition);
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

        label_pos = new QLabel(widget_left);
        label_pos->setObjectName(QStringLiteral("label_pos"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_pos->sizePolicy().hasHeightForWidth());
        label_pos->setSizePolicy(sizePolicy1);
        label_pos->setMinimumSize(QSize(70, 30));
        label_pos->setMaximumSize(QSize(70, 30));

        horizontalLayout->addWidget(label_pos);

        label_begin = new QLabel(widget_left);
        label_begin->setObjectName(QStringLiteral("label_begin"));
        sizePolicy1.setHeightForWidth(label_begin->sizePolicy().hasHeightForWidth());
        label_begin->setSizePolicy(sizePolicy1);
        label_begin->setMinimumSize(QSize(80, 30));
        label_begin->setMaximumSize(QSize(80, 30));

        horizontalLayout->addWidget(label_begin);

        label_between = new QLabel(widget_left);
        label_between->setObjectName(QStringLiteral("label_between"));
        sizePolicy1.setHeightForWidth(label_between->sizePolicy().hasHeightForWidth());
        label_between->setSizePolicy(sizePolicy1);
        label_between->setMinimumSize(QSize(20, 30));
        label_between->setMaximumSize(QSize(20, 30));
        label_between->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_between);

        label_end = new QLabel(widget_left);
        label_end->setObjectName(QStringLiteral("label_end"));
        sizePolicy1.setHeightForWidth(label_end->sizePolicy().hasHeightForWidth());
        label_end->setSizePolicy(sizePolicy1);
        label_end->setMinimumSize(QSize(80, 30));
        label_end->setMaximumSize(QSize(80, 30));

        horizontalLayout->addWidget(label_end);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(widget_left);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        widget_search = new QWidget(DataPosition);
        widget_search->setObjectName(QStringLiteral("widget_search"));
        gridLayout_2 = new QGridLayout(widget_search);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(widget_search);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(50, 30));
        label->setMaximumSize(QSize(50, 30));

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(widget_search);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMinimumSize(QSize(150, 40));
        comboBox->setMaximumSize(QSize(150, 40));

        horizontalLayout_2->addWidget(comboBox);

        lineEdit = new QLineEdit(widget_search);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(200, 40));
        lineEdit->setMaximumSize(QSize(200, 40));

        horizontalLayout_2->addWidget(lineEdit);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        horizontalLayout_3->addWidget(widget_search);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        retranslateUi(DataPosition);

        QMetaObject::connectSlotsByName(DataPosition);
    } // setupUi

    void retranslateUi(QWidget *DataPosition)
    {
        DataPosition->setWindowTitle(QApplication::translate("DataPosition", "Form", Q_NULLPTR));
        label_pos->setText(QApplication::translate("DataPosition", "\344\275\240\347\232\204\344\275\215\347\275\256\357\274\232", Q_NULLPTR));
        label_begin->setText(QString());
        label_between->setText(QApplication::translate("DataPosition", ">", Q_NULLPTR));
        label_end->setText(QString());
        label->setText(QApplication::translate("DataPosition", "\350\277\207\346\273\244\351\241\271\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DataPosition: public Ui_DataPosition {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAPOSITION_H
