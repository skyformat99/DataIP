#include "FileRW.h"
#include <QDebug>

FileRW::FileRW()
{

}

void FileRW::reader(const QString &filename, vector<QString> &hHeader, vector<QString> &vHeader,
                    vector<vector<QString> > &data)
{
    QFile file(filename);
    bool flg = file.open(QIODevice::ReadOnly | QIODevice::Text);
    if(!flg)
        return ;

    QTextStream ts(&file);
    int n = 0;
    while(!ts.atEnd())
    {
        ++n;
        QString line = ts.readLine().trimmed();
        if(line.isEmpty())
            continue;

        if(n == 1)
            hHeader = line.split(',').toVector().toStdVector();
        else if(n == 2)
            vHeader = line.split(',').toVector().toStdVector();
        else
            data.push_back(line.split(',').toVector().toStdVector());
    }
}

void FileRW::writer(const QString &filename, const vector<QString> &hHeader,
                    const vector<QString> &vHeader, const vector<vector<QString> > &data)
{
    QFile file(filename);
    bool flg = file.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!flg)
        return ;

    QTextStream ts(&file);
    ts << join(hHeader) << "\r\n";
    ts << join(vHeader) << "\r\n";
    for(auto it = data.begin(); it != data.end(); ++it)
    {
        ts << join(*it) << "\r\n";
    }
    file.close();
}

QString FileRW::join(const vector<QString> &vec)
{
    QString line;
    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        line.append(*it + ",");
    }
    line = line.remove(line.size() - 1, 1);

    return line;
}

