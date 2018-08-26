/**
 ** @author:	   浓咖啡
 ** @date:	   2016.6.7
 ** @brief:      适用于点击后两个图标来回切换的按钮
 */

#ifndef SWITCHBUTTON_H
#define SWITCHBUTTON_H

#include "basebutton.h"

class SwitchButton : public BaseButton
{
    Q_OBJECT
public:
    explicit SwitchButton(QWidget *parent = 0);
    void setIndex(int, int);

signals:

protected slots:
    virtual void releaseSlot();  //松开后需要扩展的功能

protected:
    int index1;
    int index2;
    bool flag;
};

#endif // SWITCHBUTTON_H
