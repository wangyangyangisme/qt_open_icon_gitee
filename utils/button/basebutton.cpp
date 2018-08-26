#include "basebutton.h"
#include "muifont.h"

#define DEFULT_BUTTON_STYLE "\
QPushButton{\
    color:#000000;\
    border:1px solid #AAAAAA;\
    border-radius:5;\
    background-color:#FFFFFF;\
}\
QPushButton:pressed{\
    color:#FFFFFF;\
    background-color:#AAAAAA;\
}\
"

//background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9, stop:0.494318 rgba(214, 214, 214, 255), stop:0.5 rgba(236, 236, 236, 255));

/**
 * @brief 会产生示例按钮，默认使用mui字体显示微信图标
 */
BaseButton::BaseButton(QWidget *parent):QPushButton(parent)
{
    //默认是mui字体
    fontName = MuiFont().getIconName();
    iconhelp::setIcon(this, MuiFont::ICON_WEINXIN);

    //字体大小需要单独设置
    QString finalStyle = DEFULT_BUTTON_STYLE + \
            QString("QPushButton{font:%1pt;}").arg(this->font().pointSize());

    setStyleSheet(finalStyle);

    connect(this, SIGNAL(btnReleased()), this, SLOT(releaseSlot()));
}

/**
 * @brief 按钮基类
 * @param fontLib 选择字体库
 * @param iconIndex 选择字体库图标索引
 * @param style 样式
 * @param parent
 */
BaseButton::BaseButton(const AbstractFont &fontLib, int iconIndex, \
                       const QString &style, QWidget *parent):QPushButton(parent)
{
    fontName = fontLib.getIconName();
    IconHelper::Instance()->setNewIcon(fontLib);
    iconhelp::setIcon(this,iconIndex);

    if(style != QString()){
        setStyleSheet(style);
    }else{
        QString finalStyle = DEFULT_BUTTON_STYLE + \
                QString("QPushButton{font:%1pt;}").arg(this->font().pointSize());
        setStyleSheet(finalStyle);
    }

    connect(this,SIGNAL(btnReleased()),this,SLOT(releaseSlot()));
}

/**
 * @brief 重设图标，等价重调用setText方法
 * @param index 图标在字体库中索引号
 */
void BaseButton::setIcon(int index)
{
    iconhelp::setIcon(this, index);
}

/**
 * @brief 重设图标大小
 * @param ptSize
 */
void BaseButton::setIconSize(int ptSize)
{
    QString finalStyle = this->styleSheet() + \
            QString("QPushButton{font:%1pt;}").arg(ptSize);

    setStyleSheet(finalStyle);
}

/**
 * @brief 重设字体库
 * @param fontLib 新字库
 */
void BaseButton::setNewFont(const AbstractFont &fontLib)
{
    fontName = fontLib.getIconName();
    IconHelper::Instance()->setNewIcon(fontLib);
}

/**
 * @brief 恢复字体库，因为按钮有状态变化，故可能字库被改变，
 * 调用此方法可还原字体库
 */
void BaseButton::restoreFont()
{
    IconHelper::Instance()->setNewIcon(AbstractFont(fontName));
}

/**
 * @brief 重新定义松开事件，实现误按后滑出按钮不会触发事件效果
 * @param e
 */
void BaseButton::mouseReleaseEvent(QMouseEvent *e)
{
    if (hitButton(e->pos())){  //松开时候光标仍在按钮区域
        emit btnReleased();
        QPushButton::mouseReleaseEvent(e); //继续默认处理
    }
}
