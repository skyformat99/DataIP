#include "LineEdit.h"

#include <QDebug>

#define Left 32
#define Right 16

#define SAFE_DEL(p) if(p){delete p; p = NULL;}

LineEdit::LineEdit(QWidget *parent) : QLineEdit(parent)
{
    initlize();
}

LineEdit::~LineEdit()
{
    SAFE_DEL(m_label);
    SAFE_DEL(m_btn);
}

void LineEdit::setImage(const QString &image)
{
    m_label->setPixmap(QPixmap(image));
}

void LineEdit::resizeEvent(QResizeEvent *)
{
    int w = width();
    int h = height();
    if(m_label)
    {
        m_label->setGeometry(0, (h - Left)/2, Left, Left);
    }

    if(m_btn)
    {
        m_btn->setGeometry(w - Right - 5, (h - Right)/2, Right, Right);
    }
}

void LineEdit::enterEvent(QEvent *)
{
    m_btn->show();
}

void LineEdit::leaveEvent(QEvent *)
{
    m_btn->hide();
}

void LineEdit::onClicked(bool)
{
    if(!text().isEmpty())
    {
        clear();
    }
}

void LineEdit::initlize()
{
    m_label = new QLabel(this);
    m_label->setFixedSize(Left, Left);
    m_label->setFocusPolicy(Qt::NoFocus);
    setImage(":/image/user.png");

    m_btn = new QPushButton(this);
    m_btn->setFixedSize(Right, Right);
    m_btn->hide();
    connect(m_btn, SIGNAL(clicked(bool)), this, SLOT(onClicked(bool)));
    m_btn->setObjectName("edit");

    setFixedHeight(46);
    setMinimumWidth(300);
}
