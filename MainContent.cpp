#include "MainContent.h"
#include <QPainter>
#include <QStyleOption>
#include <QDebug>

MainContent::MainContent(QWidget *parent) : QWidget(parent)
{
    m_positon = new DataPosition(this);

    m_leftWidget = new QListWidget(this);
    m_leftWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_leftWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_leftWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    m_leftWidget->setFixedWidth(260);

    m_buttonWidget = new QWidget(this);
    m_buttonWidget->setFixedHeight(70);
    m_buttonLayout = new QHBoxLayout;
    m_buttonLayout->setSpacing(0);
    m_buttonLayout->setMargin(0);
    m_buttonWidget->setLayout(m_buttonLayout);

    m_stackedWidget = new QStackedWidget(this);
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->addWidget(m_buttonWidget);
    vLayout->addWidget(m_stackedWidget);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(m_leftWidget);
    hLayout->addLayout(vLayout);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(m_positon, 0, Qt::AlignTop);
    mainLayout->addLayout(hLayout);
    mainLayout->setMargin(0);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);

    setLeftData();

    emit dataType(KSPD, true);

    connect(m_leftWidget, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onListViewClicked(const QModelIndex &)));
    connect(m_positon, SIGNAL(textChanged(int, const QString &)), this, SIGNAL(textChanged(int, const QString &)));
}

MainContent::~MainContent()
{

}

void MainContent::setItems(const vector<QString> &vec)
{
    m_positon->addItems(vec);
}

void MainContent::setWidget(QWidget *wid)
{
    auto it = std::find(m_widgets.begin(), m_widgets.end(), wid);
    if(it == m_widgets.end())
    {
        m_widgets.push_back(wid);
        m_stackedWidget->addWidget(wid);
    }
    m_stackedWidget->setCurrentWidget(wid);
}

void MainContent::setFirstClicked()
{
    if(!m_buttons.empty())
        m_buttons[0]->click();
}

void MainContent::onListViewClicked(const QModelIndex &index)
{
    QString curText = index.data().toString();
    if(curText != m_curText)
    {
        m_curText = curText;
        setButtonData();
    }
}

void MainContent::onClicked()
{
    QAbstractButton * btn = qobject_cast<QAbstractButton *>(sender());
    if(!btn)
        return ;

    QString text = btn->text();
    bool flg = btn->isChecked();
    DataType dType = KSPD;
    if(text == tr("开始判读"))
        dType = KSPD;
    else if(text == tr("导入本地资源"))
        dType = DRBDZY;
    else if(text == tr("保存文件"))
        dType = BCWJ;
    else if(text == tr("柱状图"))
        dType = ZZT;
    else if(text == tr("折线图"))
        dType = ZXT;
    else if(text == tr("雷达图"))
        dType = LDT;
    else if(text == tr("修改密码"))
        dType = XGMM;

    emit dataType(dType, flg);
}

void MainContent::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}

void MainContent::setLeftData()
{
    XmlReader::readXml("./menu.xml", m_data);
    m_leftWidget->clear();
    for(auto it = m_data.cbegin(); it != m_data.cend(); ++it)
    {
        m_leftWidget->addItem(QString::fromStdString(it->first.m_name));
    }

    m_curText = QString::fromStdString(m_data.begin()->first.m_name);
    setButtonData();
    m_leftWidget->setCurrentRow(0);
}

void MainContent::setButtonData()
{
    clearButtonData();

    auto it = m_data.begin();
    while(it != m_data.end())
    {
        if(it->first.m_name == m_curText.toStdString())
        {
            break;
        }
        ++it;
    }

    const vector<Data> &vec = it->second;
    QButtonGroup *group = new QButtonGroup(this);
    for(int i = 0, len = vec.size(); i != len; ++i)
    {
        QPushButton *btn = new QPushButton(QString::fromStdString(vec[i].m_name), this);
        connect(btn, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
        btn->setObjectName("btn");
        m_buttons.push_back(btn);
        m_buttonLayout->addWidget(btn);
        btn->setCheckable(vec[i].m_flg);
        if(vec[i].m_flg)
            group->addButton(btn, i);
    }
    m_buttonLayout->addStretch();
    //group->button(0)->setChecked(true);
    //group->button(0)->click();
    setFirstClicked();

    m_positon->setText(tr("数据判读"), m_curText);
    m_positon->setSearchShow(it->first.m_flg);
}

void MainContent::clearButtonData()
{
    int sz = m_buttons.size();
    if(sz != 0)
    {
        m_buttonLayout->removeItem(m_buttonLayout->itemAt(sz));
    }

    for(int i = 0; i != sz; ++i)
    {
        m_buttonLayout->removeWidget(m_buttons[i]);
        delete m_buttons[i];
    }
    m_buttons.clear();
}
