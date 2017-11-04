#ifndef XMLREADER_H
#define XMLREADER_H

#include <QXmlStreamReader>
#include <QFile>
#include "common.h"

class XmlReader
{
public:
    static void readXml(const QString &filename, MenuData &data);

private:
    static void readAction(vector<Data> &data);

    static QXmlStreamReader m_reader;
};

#endif // XMLREADER_H
