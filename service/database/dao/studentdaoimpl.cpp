/**
 ** @author:	    浓咖啡
 ** @date:          2018.7.19
 ** @brief:         具体表的dao层
 */

#include "studentdaoimpl.h"

#define STUDENT_TABLE QString("STUDENT_TABLE")

#define CREATE_STUDENT_TABLE_CMD "CREATE TABLE IF NOT EXISTS "+STUDENT_TABLE+"(\
NUM INT PRIMARY KEY,   \
NAME TEXT NOT NULL,\
SEX BOOLEAN NOT NULL,\
AGE INT NOT NULL\
)"

#define INSERT_STUDENT_CMD "INSERT INTO "+STUDENT_TABLE+\
    " VALUES(?, ?, ?, ?)"

//https://blog.csdn.net/y_dzaichirou/article/details/53673528

/**
 * @brief 构造函数
 * @param db 数据库连接
 */
StudentDaoImpl::StudentDaoImpl() : AbstractDao()
{
}

/**
 * @brief 产生所需的表
 * @return
 */
bool StudentDaoImpl::createTable()
{
    return executeSql(CREATE_STUDENT_TABLE_CMD);
}

/**
 * @brief 插入数据
 * @param obj 学生实体信息
 * @return
 */
bool StudentDaoImpl::insert(const StudentData &obj)
{
    QList<QVariant> list;
    list.append(obj.num);
    list.append(obj.name);
    list.append(obj.sex);
    list.append(obj.age);

    return executeSql(INSERT_STUDENT_CMD, list);
}

/**
 * @brief 查询通用方法
 * @param objs 查询到的所有结果实体项
 * @param condition 查询条件，空为查找所有
 * @return -1:查询出错 0：未查到 >0：实际查询到记录条数
 */
int StudentDaoImpl::querryCommon(QList<StudentData> &objs, const QString &condition)
{
    QString sql;

    if(condition.isEmpty()){  //查询所有
        sql = "SELECT * FROM " + STUDENT_TABLE;
    }else{
        sql = "SELECT * FROM " + STUDENT_TABLE + " WHERE " + condition;
    }

    StudentData data;
    QSqlDatabase db;
    if(!getConn(db)){
        return -1;
    }

    QSqlQuery query(db);

    if(!query.exec(sql)){
        qDebug()<<query.lastError();
        return -1;
    }

    while (query.next()) {
        data.num = query.value(0).toInt();
        data.name = query.value(1).toString();
        data.sex = query.value(2).toBool();
        data.age = query.value(3).toInt();

        objs.append(data);
    }
    putConn(db);

    return objs.length();
}

/**
 * @brief 根据主键查询唯一的记录
 * @param obj 返回实体对象
 * @param num 主键值
 * @return -1:查询出错 0：未查到 1：查到记录
 */
int StudentDaoImpl::querryObj(StudentData &obj, int num)
{
    QList<StudentData> objs;
    QString condition = findByNum(num);

    if(!querryCommon(objs, condition)){
        return -1;
    }

    if(objs.isEmpty()){
        return 0;
    }

    obj = objs.at(0);

    return 1;
}

/**
 * @brief 查询所有记录
 * @param objs
 * @return -1:查询出错 0：未查到 >0：查询成功
 */
int StudentDaoImpl::querryAll(QList<StudentData> &objs)
{
    return querryCommon(objs, QString());
}

/**
 * @brief 查看表的内容
 */
void StudentDaoImpl::__viewTable()
{
    QString cmd = "SELECT * FROM " + STUDENT_TABLE;

    QSqlDatabase db;
    if(!getConn(db)){
        return;
    }

    QSqlQuery query(db);
    query.exec(cmd);

    //输出到控制台，这个格式不好控制，如果数据多，可以去文件查看
    qDebug()<<\
               "id"<<\
               "name"<<\
               "score";

    //输出到文件
    out<<\
          "id"<<\
          "name"<<\
          "score"<<qSetFieldWidth(0)<<endl;
    out<<"--------------------------------------------"<<endl;

    //输出数据
    while (query.next()) {
        //输出到控制台
        qDebug()<<\
                   query.value(0).toInt()<<\
                   query.value(1).toString()<<\
                   query.value(2).toBool()<<\
                   query.value(3).toInt();
        //输出到文件
        out<<left<<qSetFieldWidth(20)<<\
             query.value(1).toString()<<\
             query.value(2).toBool()<<\
             query.value(3).toInt()\
          <<qSetFieldWidth(0)<<endl;
    }

    putConn(db);
}

/**
 *---------------------------------------------------
 * 以下为查询子方法语句
 */
QString StudentDaoImpl::findByNum(int num)
{
    return QString("num = %1").arg(QString::number(num));
}
