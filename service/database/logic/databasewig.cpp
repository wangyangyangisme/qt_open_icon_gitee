#include "databasewig.h"
#include "ui_databasewig.h"

//参考资料：https://blog.csdn.net/linan_pin/article/details/70158259

DataBaseWig::DataBaseWig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataBaseWig)
{
    ui->setupUi(this);
    stuDao.initTable();

    updateStuTable();
}

void DataBaseWig::updateStuTable()
{
    QList<StudentData> list;
    stuDao.querryAll(list);

    ui->stuTable->clear();

    int rowCount = list.length();
    ui->stuTable->setRowCount(rowCount);
    for(int i=0; i<rowCount; i++){
        ui->stuTable->setItem(i, 0, new QTableWidgetItem(QString::number(list.at(i).num)));
        ui->stuTable->setItem(i, 1, new QTableWidgetItem(list.at(i).name));
        ui->stuTable->setItem(i, 2, new QTableWidgetItem(QString::number(list.at(i).sex)));
        ui->stuTable->setItem(i, 3, new QTableWidgetItem(QString::number(list.at(i).age)));
    }
}

void DataBaseWig::on_addStuBtn_clicked()
{
    StudentData stu;
    stu.num = ui->addStuTable->item(0,0)->text().toInt();
    stu.name = ui->addStuTable->item(0,1)->text();
    stu.sex = ui->addStuTable->item(0,2)->text().toInt() ? 1:0;
    stu.age = ui->addStuTable->item(0,3)->text().toInt();

    stuDao.insert(stu);

    updateStuTable();
}
