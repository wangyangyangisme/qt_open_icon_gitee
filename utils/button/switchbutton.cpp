#include "switchbutton.h"
#include "fontawesomewebfont.h"

SwitchButton::SwitchButton(QWidget *parent):BaseButton(parent)
{
    this->setNewFont(FontawesomeWebfont());
    index1 = FontawesomeWebfont::ICON_UNLOCK;
    index2 = FontawesomeWebfont::ICON_LOCK;
    this->setIcon(index1);
    flag = true;
}

void SwitchButton::setIndex(int index1, int index2)
{
    this->index1 = index1;
    this->index2 = index2;
    this->setIcon(index1);
}

void SwitchButton::releaseSlot()
{
    restoreFont();
    if(flag){
        iconhelp::setIcon(this,index2);
        flag = false;
    }else{
        iconhelp::setIcon(this,index1);
        flag = true;
    }
}
