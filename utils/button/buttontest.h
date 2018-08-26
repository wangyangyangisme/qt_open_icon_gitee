#ifndef BUTTONTEST_H
#define BUTTONTEST_H

#include <QWidget>

namespace Ui {
class ButtonTest;
}

class ButtonTest : public QWidget
{
    Q_OBJECT

public:
    explicit ButtonTest(QWidget *parent = 0);
    ~ButtonTest();

private:
    Ui::ButtonTest *ui;
};

#endif // BUTTONTEST_H
