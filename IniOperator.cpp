#include "IniOperator.h"
#include <QTextCodec>

IniOperator::IniOperator()
{

}

void IniOperator::write(const QString &filename, const QString &key, const QString &val)
{
    QSettings setting(filename, QSettings::IniFormat);
    setting.beginGroup("config");
    setting.setValue(key, val);
    setting.endGroup();
}

QString IniOperator::read(const QString &filename, const QString &key)
{
    QSettings setting(filename, QSettings::IniFormat);
    setting.setIniCodec("system");
    return setting.value("config/" + key).toString();
}
