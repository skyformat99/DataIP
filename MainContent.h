#ifndef MAINCONTENT_H
#define MAINCONTENT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QButtonGroup>
#include "DataPosition.h"
#include "XmlReader.h"

class MainContent : public QWidget
{
    Q_OBJECT
public:
    explicit MainContent(QWidget *parent = nullptr);
    virtual ~MainContent();

    void setItems(const vector<QString> &vec);
    void setWidget(QWidget *wid);
    void setFirstClicked();

signals:
    void textChanged(int, const QString &);
    void dataType(DataType, bool);

public slots:
    void onListViewClicked(const QModelIndex &);
    void onClicked();

protected:
    void paintEvent(QPaintEvent *);

private:
    void setLeftData();
    void setButtonData();
    void clearButtonData();

private:
    DataPosition *m_positon;
    QListWidget *m_leftWidget;
    QStackedWidget *m_stackedWidget;
    QWidget *m_buttonWidget;

    QHBoxLayout *m_buttonLayout;
    vector<QAbstractButton *> m_buttons;

    MenuData m_data;
    QString m_curText;

    vector<QWidget *> m_widgets;
};

#endif // MAINCONTENT_H
