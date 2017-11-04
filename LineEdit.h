#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class LineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit LineEdit(QWidget *parent = Q_NULLPTR);
    ~LineEdit();
    void setImage(const QString &image);

protected:
    void resizeEvent(QResizeEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

private slots:
    void onClicked(bool);

private:
    void initlize();

    QLabel *m_label;
    QPushButton *m_btn;
};

#endif // LINEEDIT_H
