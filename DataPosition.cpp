#include "DataPosition.h"
#include "ui_DataPosition.h"
#include <QPainter>

DataPosition::DataPosition(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataPosition)
{
    ui->setupUi(this);

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onCurrentIndexChanged(int)));
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(onTextChanged(QString)));

    ui->label_begin->setObjectName("pos");
    ui->label_end->setObjectName("pos");
}

DataPosition::~DataPosition()
{
    delete ui;
}

void DataPosition::setText(const QString &beg, const QString &end)
{
    ui->label_begin->setText(beg);
    ui->label_end->setText(end);
}

void DataPosition::addItems(const vector<QString> &vec)
{
    ui->comboBox->clear();
    for(auto it = vec.begin(); it != vec.end(); ++it)
        ui->comboBox->addItem(*it);
}

void DataPosition::setSearchShow(bool flg)
{
    ui->widget_search->setHidden(!flg);
}

void DataPosition::onCurrentIndexChanged(int index)
{
    QString text = ui->lineEdit->text();
    emit textChanged(index, text);
}

void DataPosition::onTextChanged(const QString &text)
{
    int index = ui->comboBox->currentIndex();
    emit textChanged(index, text);
}

void DataPosition::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}
