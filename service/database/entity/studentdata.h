/**
 ** @author:	     浓咖啡
 ** @date:           2016.10.21
 ** @brief:          实体层:只负责数据定义
 */

#ifndef STUDENTDATA_H
#define STUDENTDATA_H

#include <QString>

class StudentData
{
public:
    StudentData();

public:
    int num;  //学号
    QString name;  //姓名
    bool sex;
    int age;
};

#endif // STUDENTDATA_H
