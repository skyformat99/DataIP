#ifndef INIOPERATOR_H
#define INIOPERATOR_H

#include <QSettings>
#include <QVariant>
#include <QString>

class IniOperator
{
public:
    IniOperator();

    static void write(const QString &filename, const QString &key, const QString &val);
    static QString read(const QString &filename, const QString &key);
};

#endif // INIOPERATOR_H
