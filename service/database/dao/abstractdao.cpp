/**
 ** @author:	     浓咖啡
 ** @date:           2016.10.21
 ** @brief:          dao层抽象接口:只负责数据库操作
 ** @update:        重写设计数据库操作框架 2018.7.18 浓咖啡
 */

#include "abstractdao.h"


AbstractDao::AbstractDao()
{
}

/**
 * @brief 从连接池获取连接
 * @param db
 * @return
 */
bool AbstractDao::getConn(QSqlDatabase &db)
{
    db = ConnectionPool::openConnection();
    if(db.isValid()){
        return true;
    }else{
        qDebug()<<"getConn failed";
        return false;  //达到最大连接数
    }
}

void AbstractDao::putConn(const QSqlDatabase &db)
{
    ConnectionPool::closeConnection(db);
}

bool AbstractDao::initTable()
{
    if(createTable()){
        return true;
    }else{
        return false;
    }
}

/**
 * @brief 通用sql语句执行方法
 * @param sql 执行的sql语句
 * @param list 参数列表，没有可以不填
 * @return
 */
bool AbstractDao::executeSql(const QString &sql,const QList<QVariant> &list)
{
    QSqlDatabase db;
    if(!getConn(db)){
        return false;
    }

    QSqlQuery query(db);
    query.prepare(sql);

    if(!list.isEmpty()){
        for(int i=0; i<list.length(); i++){
            query.bindValue(i, list.at(i));
        }
    }

    if(!query.exec()){
        qDebug()<<query.lastError();
        return false;
    }

    putConn(db);

    return true;
}

/**
 * @brief 调试使用，显示表的所有信息:select * from table
 * @param logFile:日志文件名字
 */
void AbstractDao::viewTable(const QString &logFile)
{
    QFile file(logFile + ".log");
    file.open(QIODevice::Text | QIODevice::WriteOnly);
    out.setDevice(&file);
    out<<left<<qSetFieldWidth(20);

    qDebug()<<endl;

    __viewTable();
    qDebug()<<endl;

    file.close();
}

