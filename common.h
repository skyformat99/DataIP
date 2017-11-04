#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <fstream>

#include <QFile>
#include <QTextStream>
#include <QString>

using namespace std;

struct Data
{
    Data(string name="", bool flg = true, int id = 1)
        :m_name(name), m_flg(flg), m_id(id)
    {}

    friend bool operator ==(const Data &lhs, const Data &rhs)
    {
        return lhs.m_name == rhs.m_name;
    }
    friend bool operator <(const Data &lhs, const Data &rhs)
    {
        return lhs.m_id < rhs.m_id;
    }

    string m_name;
    bool m_flg;
    int m_id;
};

typedef map<Data, vector<Data> >  MenuData;


enum DataType
{
    KSPD = 0,  //开始判读
    DRBDZY,    //导入本地资源
    BCWJ,      //保存文件
    ZZT,       //柱状图
    ZXT,       //折线图
    LDT,       //雷达图
    XGMM       //修改密码
};

#endif // COMMON_H
