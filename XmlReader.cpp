#include "XmlReader.h"

QXmlStreamReader XmlReader::m_reader;

void XmlReader::readXml(const QString &filename, MenuData &data)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
        return ;

    m_reader.setDevice(&file);

    int id = 0;
    while(!m_reader.atEnd())
    {
        m_reader.readNext();
        if(m_reader.isStartElement())
        {
            if(m_reader.name() == "menu")
            {
                string name = m_reader.attributes().value("name").toString().toStdString();
                bool flg = m_reader.attributes().value("search").toInt() == 1;
                readAction(data[Data(name, flg, ++id)]);
            }
        }
        //m_reader.readNext();
    }
}

void XmlReader::readAction(vector<Data> &data)
{
    while(!m_reader.atEnd())
    {
        m_reader.readNext();
        if(m_reader.isStartElement())
        {
            if(m_reader.name() == "action")
            {
                bool flg = m_reader.attributes().value("checked").toString() != "0";
                string name = m_reader.readElementText().toStdString();
                data.push_back(Data(name, flg));
            }
        }
        else
        {
            if(m_reader.name() == "menu")
                return ;
        }
        //m_reader.readNext();
    }
}
