#ifndef NAVBARTEST_H
#define NAVBARTEST_H

#include <QWidget>

namespace Ui {
class NavbarTest;
}

class NavbarTest : public QWidget
{
    Q_OBJECT

public:
    explicit NavbarTest(QWidget *parent = 0);
    ~NavbarTest();

public slots:
    void lBtnSlot();
    void rBtnSlot();

private:
    Ui::NavbarTest *ui;
};

#endif // NAVBARTEST_H
