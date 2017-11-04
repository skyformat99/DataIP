#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class ChangePassword : public QWidget
{
    Q_OBJECT
public:
    explicit ChangePassword(QWidget *parent = nullptr);
    ~ChangePassword();

signals:

public slots:
    void onTextChanged();
    void onOkBtnClicked();
    void onCancleBtnClicked();

private:
    QLabel *m_oldLabel;
    QLabel *m_newLabel;
    QLabel *m_newReLabel;

    QLineEdit *m_oldEdit;
    QLineEdit *m_newEdit;
    QLineEdit *m_newReEdit;

    QPushButton *m_okBtn;
    QPushButton *m_cancleBtn;
};

#endif // CHANGEPASSWORD_H
