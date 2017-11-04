#include "DataTitle.h"
#include <QPainter>

DataTitle::DataTitle(QWidget *parent) : QWidget(parent)
{
    ui.setupUi(this);
    initlize();
}

DataTitle::~DataTitle()
{

}

void DataTitle::setUserName(const QString &user)
{
    ui.staus_label_up->setText(tr("欢迎") + user);
    ui.staus_label_down->setText(tr("登陆成功"));
}

void DataTitle::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}

void DataTitle::onTimeOut()
{
    QString curDataTime = QDateTime::currentDateTime().toString(tr("yyyy年MM月dd日\n hh时mm分ss秒"));
    ui.time_label->setText(curDataTime);
}

void DataTitle::initlize()
{
    m_timer = new QTimer(this);
    m_timer->start(1000);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));

    connect(ui.info_btn, SIGNAL(clicked(bool)), this, SIGNAL(help()));
    connect(ui.exit_btn, SIGNAL(clicked(bool)), this, SIGNAL(quit()));

    ui.title_label->setText(tr("自动判读软件"));

    onTimeOut();

    ui.icon_label->setObjectName("icon");
    ui.info_btn->setObjectName("info");
    ui.exit_btn->setObjectName("exit");

    ui.title_label->setObjectName("title");
    ui.time_label->setObjectName("time");
    ui.staus_label_up->setObjectName("status_up");
    ui.staus_label_down->setObjectName("status_down");
}
