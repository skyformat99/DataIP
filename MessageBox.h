#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

enum MsgIcon
{
    NoIcon = 0,
    Info,
    Warn,
    System
};

class MessageBox : public QDialog
{
    friend class CustomMsgBox;
private:
    MessageBox(MsgIcon icon, QWidget *parent = nullptr);

    void initlize();
    void setTitle(const QString &);
    void setText(const QString &);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QLabel *m_titleLabel;
    QPushButton *m_closeBtn;
    QWidget *m_topWidget;

    QLabel *m_iconLabel;
    QLabel *m_textLabel;
    QWidget *m_midWidget;

    QPushButton *m_okBtn;
    QPushButton *m_cancleBtn;
    QWidget *m_bottomWidget;

    bool m_pressed;
    QPoint m_prePos;

    MsgIcon m_icon;
};

class CustomMsgBox
{
public:
    static int about(MsgIcon icon, const QString &title, const QString &text);
};

#endif // MESSAGEBOX_H
