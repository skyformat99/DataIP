#ifndef DATAIP_H
#define DATAIP_H

#include "DataTitle.h"
#include "Login.h"
#include "MainContent.h"
#include "MessageBox.h"
#include "FileRW.h"
#include "ChangePassword.h"
#include "Curve.h"

#include <QTableView>
#include <QStandardItemModel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void onHelp();
    void onLogin();
    void onSetup();
    void onDataType(DataType, bool);

private:
    void setTableData(const QString &filename);
    void saveTableData();
    void importTableData();
    void changedPwd();

    void setBar();
    void setLine();

private:
    DataTitle *m_title;
    MainContent *m_content;
    QStackedWidget *m_stackedWidget;
    ChangePassword *m_changePwd;

    Login *m_login;

    QTableView *m_tableView;
    QStandardItemModel *m_tableModel;

    Curve *m_bar;
    Curve *m_line;
};

#endif // DATAIP_H
