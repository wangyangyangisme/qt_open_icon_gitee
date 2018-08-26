#include "digitalinputtest.h"

DigitalInputTest::DigitalInputTest(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle(QString("数字输入框"));
    digWig  = new DigitalInput(50, 50);
    QHBoxLayout *lay = new QHBoxLayout(this);

    lay->addWidget(digWig);
}
