/**
 ** @author:	    浓咖啡
 ** @date:            2016.10.21
 ** @brief:          dao层抽象接口
 */

#ifndef ABSTRACTDAO_H
#define ABSTRACTDAO_H

#include "connectionpool.h"

class AbstractDao : public QObject
{
    Q_OBJECT
public:
    explicit AbstractDao();
    bool initTable();
    void viewTable(const QString &);


protected:
    bool executeSql(const QString &sql, const QList<QVariant> &list = QList<QVariant>());
    bool getConn(QSqlDatabase &db);
    void putConn(const QSqlDatabase &db);

    virtual bool createTable() = 0;  //产生表的接口
    virtual void __viewTable() = 0;  //select * from table封装

    QSqlDatabase db;
    QTextStream out;
};

#endif // ABSTRACTDAO_H
