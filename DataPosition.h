#ifndef DATAPOSITION_H
#define DATAPOSITION_H

#include <QWidget>
#include "common.h"

namespace Ui {
class DataPosition;
}

class DataPosition : public QWidget
{
    Q_OBJECT

public:
    explicit DataPosition(QWidget *parent = 0);
    ~DataPosition();

    void setText(const QString &beg, const QString &end);
    void addItems(const vector<QString> &vec);
    void setSearchShow(bool flg);

private slots:
    void onCurrentIndexChanged(int);
    void onTextChanged(const QString &);

signals:
    void textChanged(int, const QString &);

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::DataPosition *ui;
};

#endif // DATAPOSITION_H
