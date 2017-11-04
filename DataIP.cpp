#include "DataIP.h"
#include <QDebug>
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent), m_changePwd(NULL)
{
    setWindowIcon(QIcon(":/image/Data_Meter.ico"));

    m_title = new DataTitle(this);
    m_stackedWidget = new QStackedWidget(this);

    m_login = new Login(this);

    QWidget *wid = new QWidget(this);
    QHBoxLayout *widLayout = new QHBoxLayout(wid);
    widLayout->addWidget(m_login, 0, Qt::AlignCenter);
    wid->setLayout(widLayout);

    m_content = new MainContent;
    m_stackedWidget->addWidget(m_content);
    m_stackedWidget->addWidget(wid);
    m_stackedWidget->setCurrentWidget(wid);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(m_title);
    mainLayout->addWidget(m_stackedWidget);
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    setLayout(mainLayout);

    m_tableView = new QTableView(this);
    m_tableModel = new QStandardItemModel(m_tableView);
    m_tableView->setModel(m_tableModel);

    connect(m_content, SIGNAL(dataType(DataType,bool)), this, SLOT(onDataType(DataType,bool)));
    connect(m_title, SIGNAL(quit()), this, SLOT(close()));
    connect(m_title, SIGNAL(help()), this, SLOT(onHelp()));
    connect(m_login, SIGNAL(quit()), this, SLOT(close()));
    connect(m_login, SIGNAL(login()), this, SLOT(onLogin()));
    connect(m_login, SIGNAL(setup()), this, SLOT(onSetup()));

    m_content->setFirstClicked();
}

Widget::~Widget()
{

}

void Widget::onHelp()
{
    CustomMsgBox::about(System, tr("帮助"),tr("<h3>自动判读软件</h3><p>版权所有：朱高鹏</p><p>Copyright &copy;2017<br/>"
                                            "E-mail:18811475054@163.com</p>"));
}

void Widget::onLogin()
{
    QString user = m_login->getUserName();
    if(user.isEmpty())
    {
        CustomMsgBox::about(Info, tr("提示"), tr("用户名为空"));
        return ;
    }
    QString pwd = m_login->getPassWord();
    if(pwd.isEmpty())
    {
        CustomMsgBox::about(Info, tr("提示"), tr("密码为空"));
        return ;
    }

    m_stackedWidget->setCurrentWidget(m_content);
    bool savePwd = m_login->savePwd();
    if(user == "admin" && pwd == "123456")
    {
        IniOperator::write("config.ini", "user", user);
        pwd = savePwd ? pwd : "";
        IniOperator::write("config.ini", "pwd", pwd);

        m_title->setUserName(user);
    }
    else
    {
        CustomMsgBox::about(Info, tr("提示"), tr("用户名或密码错误"));
    }
}

void Widget::onSetup()
{
}

void Widget::onDataType(DataType dType, bool flg)
{
    Q_UNUSED(flg);
    switch(dType)
    {
        case KSPD:
            m_content->setWidget(m_tableView);
            setTableData("./data.dat");
            break;
        case DRBDZY:
            importTableData();
            break;
        case BCWJ:
            saveTableData();
            break;
        case ZZT:
            setBar();
            break;
        case ZXT:
            setLine();
            break;
        case LDT:
            break;
        case XGMM:
            changedPwd();
            break;
    }
}

void Widget::setTableData(const QString &filename)
{
    m_tableModel->clear();

    vector<QString> hHeader;
    vector<QString> vHeader;
    vector<vector<QString> > vec;
    FileRW::reader(filename, hHeader, vHeader, vec);

    m_content->setItems(hHeader);

    for(int i = 0, len = hHeader.size(); i != len; ++i)
    {
        m_tableModel->setHorizontalHeaderItem(i, new QStandardItem(hHeader[i]));
    }
    for(int i = 0, len = vHeader.size(); i != len; ++i)
    {
        m_tableModel->setVerticalHeaderItem(i, new QStandardItem(vHeader[i]));
    }
    for(int i = 0, row = vec.size(); i != row; ++i)
    {
        for(int j = 0, col = vec[i].size(); j != col; ++j)
        {
            m_tableModel->setItem(i, j, new QStandardItem(vec[i][j]));
        }
    }
}

void Widget::saveTableData()
{
    QString filename = QFileDialog::getSaveFileName(this, "/", "", "*.txt");
    if(filename.isEmpty())
        return ;

    vector<QString> hHeader, vHeader;
    vector<vector<QString> > data;
    int rowCnt = m_tableModel->rowCount();
    int colCnt = m_tableModel->columnCount();
    for(int i = 0; i != colCnt; ++i)
    {
        hHeader.push_back(m_tableModel->horizontalHeaderItem(i)->text());
    }
    for(int i = 0; i != rowCnt; ++i)
    {
        vHeader.push_back(m_tableModel->verticalHeaderItem(i)->text());
    }
    for(int i = 0; i != rowCnt; ++i)
    {
        vector<QString> tmp;
        for(int j = 0; j != colCnt; ++j)
        {
            tmp.push_back(m_tableModel->item(i,j)->text());
        }
        data.push_back(tmp);
    }

    FileRW::writer(filename, hHeader, vHeader, data);
    CustomMsgBox::about(Info, tr("提示"), tr("保存成功"));
}

void Widget::importTableData()
{
    QString filename = QFileDialog::getOpenFileName(this, "/", "", "*.txt");
    if(filename.isEmpty())
        return ;

    setTableData(filename);
}

void Widget::changedPwd()
{
    if(!m_changePwd)
    {
        m_changePwd = new ChangePassword(this);
    }
    m_content->setWidget(m_changePwd);
}

void Widget::setBar()
{
    QVector<QString> hHeader, vHeader;
    QVector<QVector<double> > data;
    int rowCnt = m_tableModel->rowCount();
    int colCnt = m_tableModel->columnCount();
    for(int i = 0; i != colCnt; ++i)
    {
        hHeader.push_back(m_tableModel->horizontalHeaderItem(i)->text());
    }
    for(int i = 0; i != rowCnt; ++i)
    {
        vHeader.push_back(m_tableModel->verticalHeaderItem(i)->text());
    }
    for(int i = 0; i != colCnt; ++i)
    {
        QVector<double> tmp;
        for(int j = 0; j != rowCnt; ++j)
        {
            tmp.push_back(m_tableModel->item(j,i)->text().toDouble());
        }
        data.push_back(tmp);
    }

    m_bar = new Curve(ChartType::BarChart, this);
    m_bar->setTickerLables(vHeader);
    m_bar->setNames(hHeader);
    m_bar->setData(data);
    m_content->setWidget(m_bar);
}

void Widget::setLine()
{
    QVector<QString> hHeader, vHeader;
    QVector<QVector<double> > data;
    int rowCnt = m_tableModel->rowCount();
    int colCnt = m_tableModel->columnCount();
    for(int i = 0; i != colCnt; ++i)
    {
        hHeader.push_back(m_tableModel->horizontalHeaderItem(i)->text());
    }
    for(int i = 0; i != rowCnt; ++i)
    {
        vHeader.push_back(m_tableModel->verticalHeaderItem(i)->text());
    }
    for(int i = 0; i != colCnt; ++i)
    {
        QVector<double> tmp;
        for(int j = 0; j != rowCnt; ++j)
        {
            tmp.push_back(m_tableModel->item(j,i)->text().toDouble());
        }
        data.push_back(tmp);
    }

    m_line = new Curve(ChartType::LineChart, this);
    m_line->setTickerLables(vHeader);
    m_line->setNames(hHeader);
    m_line->setData(data);
    m_content->setWidget(m_line);
}
