#ifndef DATATITLE_H
#define DATATITLE_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>

#include "ui_DataIP.h"

class DataTitle : public QWidget
{
    Q_OBJECT
public:
    explicit DataTitle(QWidget *parent = nullptr);
    virtual ~DataTitle();

    void setUserName(const QString &user);

signals:
    void help();
    void quit();

protected:
    void paintEvent(QPaintEvent *);

public slots:
    void onTimeOut();

private:
    void initlize();

private:
    Ui::DataIP ui;
    QTimer *m_timer;
};

#endif // DATATITLE_H
