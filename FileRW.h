#ifndef FILERW_H
#define FILERW_H

#include "common.h"

class FileRW
{
public:
    FileRW();

    static void reader(const QString &filename, vector<QString> &hHeader, vector<QString> &vHeader,
                       vector<vector<QString> > &data);
    static void writer(const QString &filename, const vector<QString> &hHeader, const vector<QString> &vHeader,
                       const vector<vector<QString> > &data);

private:
    static QString join(const vector<QString> &vec);
};

#endif // FILERW_H
