/**
 ** @author:	    浓咖啡
 ** @date:            2016.10.23
 ** @brief:          学生信息dao层演示示例
 */

#ifndef STUDENTDAOIMPL_H
#define STUDENTDAOIMPL_H

#include "studentdata.h"
#include "abstractdao.h"

class StudentDaoImpl : public AbstractDao
{
public:
    StudentDaoImpl();

    int querryObj(StudentData &obj, int num);
    int querryAll(QList<StudentData> &objs);
    bool insert(const StudentData &obj);
    bool insertObjList(QList<StudentData> &objList);

private:
    int querryCommon(QList<StudentData> &objs, const QString &condition);
    bool createTable();
    void __viewTable();

    QString findByNum(int num);
};

#endif // STUDENTDAOIMPL_H
