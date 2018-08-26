/**
 ** @author:	浓咖啡
 ** @date:      2018.3.1
 ** @brief:     演示ui编辑器中图标库使用
 */
#ifndef LABELTEST_H
#define LABELTEST_H

#include <QWidget>

namespace Ui {
class LabelTest;
}

class LabelTest : public QWidget
{
    Q_OBJECT

public:
    explicit LabelTest(QWidget *parent = 0);
    ~LabelTest();

private:
    Ui::LabelTest *ui;
};

#endif // LABELTEST_H
