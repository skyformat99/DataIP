#include "MessageBox.h"
#include <QMouseEvent>

#define WIDTH 300
#define TOP_HEIGHT 44
#define BTN_WIDTH 80
#define BTN_HEIGHT 30

MessageBox::MessageBox(MsgIcon icon, QWidget *parent) : QDialog(parent), m_icon(icon)
{
    initlize();
}

void MessageBox::initlize()
{
    setWindowFlag(Qt::FramelessWindowHint);
    m_titleLabel = new QLabel(this);
    m_closeBtn = new QPushButton(this);
    m_closeBtn->setFixedSize(40, 40);
    m_topWidget = new QWidget(this);
    m_topWidget->setFixedSize(WIDTH, TOP_HEIGHT);
    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(m_titleLabel);
    topLayout->addStretch();
    topLayout->addWidget(m_closeBtn, 0, Qt::AlignCenter);
    topLayout->setSpacing(0);
    topLayout->setMargin(0);
    m_topWidget->setLayout(topLayout);

    m_titleLabel->setObjectName("msgTitle");
    m_closeBtn->setObjectName("exit");
    m_topWidget->setObjectName("msgTopWidget");

    m_iconLabel = new QLabel(this);
    m_iconLabel->setFixedSize(52,32);
    m_textLabel = new QLabel(this);
    m_textLabel->setWordWrap(true);
    m_midWidget = new QWidget(this);
    m_midWidget->setFixedWidth(WIDTH);
    QHBoxLayout *midLayout = new QHBoxLayout;
    midLayout->addWidget(m_iconLabel, 0, Qt::AlignTop);
    midLayout->addWidget(m_textLabel);
    m_midWidget->setLayout(midLayout);

    if(m_icon == NoIcon)
        m_iconLabel->hide();
    else if(m_icon == Warn)
        m_iconLabel->setPixmap(QPixmap(":/image/warn.png"));
    else if(m_icon == Info)
        m_iconLabel->setPixmap(QPixmap(":/image/info.png"));
    else if(m_icon == System)
        m_iconLabel->setPixmap(QPixmap(":/image/Data_Meter.ico"));

    m_okBtn = new QPushButton(tr("确定"), this);
    m_okBtn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    m_cancleBtn = new QPushButton(tr("取消"), this);
    m_cancleBtn->setFixedSize(BTN_WIDTH, BTN_HEIGHT);
    m_bottomWidget = new QWidget(this);
    m_bottomWidget->setFixedSize(WIDTH, TOP_HEIGHT);
    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch();
    bottomLayout->addWidget(m_okBtn);
    bottomLayout->addWidget(m_cancleBtn);
    m_bottomWidget->setLayout(bottomLayout);

    m_okBtn->setObjectName("login");
    m_cancleBtn->setObjectName("login");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);
    mainLayout->addWidget(m_topWidget);
    mainLayout->addWidget(m_midWidget);
    mainLayout->addWidget(m_bottomWidget);
    setLayout(mainLayout);

    connect(m_closeBtn, SIGNAL(clicked(bool)), this, SLOT(reject()));
    connect(m_cancleBtn, SIGNAL(clicked(bool)), this, SLOT(reject()));
    connect(m_okBtn, SIGNAL(clicked(bool)), this, SLOT(accept()));
}

void MessageBox::setTitle(const QString &title)
{
    m_titleLabel->setText(title);
}

void MessageBox::setText(const QString &text)
{
    m_textLabel->setText(text);
}

void MessageBox::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_prePos = event->globalPos() - pos();
        m_pressed = true;
        event->accept();
    }
}

void MessageBox::mouseReleaseEvent(QMouseEvent *)
{
    m_pressed = false;
}

void MessageBox::mouseMoveEvent(QMouseEvent *event)
{
    if(m_pressed && (event->buttons() && Qt::LeftButton))
    {
        move(event->globalPos() - m_prePos);
        event->accept();
    }
}


int CustomMsgBox::about(MsgIcon icon, const QString &title, const QString &text)
{
    MessageBox box(icon);
    box.setTitle(title);
    box.setText(text);

    return box.exec();
}
