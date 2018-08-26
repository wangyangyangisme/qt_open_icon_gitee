#ifndef DATABASEWIG_H
#define DATABASEWIG_H

#include <QtWidgets>
#include "studentdaoimpl.h"

namespace Ui {
class DataBaseWig;
}

class DataBaseWig : public QWidget
{
    Q_OBJECT

public:
    explicit DataBaseWig(QWidget *parent = 0);

private slots:

    void on_addStuBtn_clicked();

private:
    void updateStuTable();
    Ui::DataBaseWig *ui;
    StudentDaoImpl stuDao;
};

#endif // DATABASEWIG_H
