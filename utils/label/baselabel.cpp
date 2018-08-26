/**
 ** @author:	   浓咖啡
 ** @date:	   2016.5.23
 ** @brief:      图标基类
 */
#include "baselabel.h"
#include "muifont.h"

#define DEFULT_LABEL_STYLE "\
QLabel{\
    color:#000000;\
    border:1px solid #AAAAAA;\
    background-color:rgb(255,255,255);\
}\
"

/**
 * @brief 字体库方式生成label
 * @param parent
 */
BaseLabel::BaseLabel(QWidget *parent):QLabel(parent)
{
    //默认是mui字体
    fontName = MuiFont().getIconName();
    iconhelp::setIcon(this, MuiFont::ICON_WEINXIN);

    //字体大小需要单独设置
    QString finalStyle = DEFULT_LABEL_STYLE + \
            QString("QLabel{font:%1pt;}").arg(this->font().pointSize());

    setStyleSheet(finalStyle);
    this->setAlignment(Qt::AlignCenter);
}

/**
 * @brief label基类
 * @param fontLib 选择字体库
 * @param iconIndex 选择字体库图标索引
 * @param style 样式
 * @param parent
 */
BaseLabel::BaseLabel(const AbstractFont &fontLib, int iconIndex, \
                     const QString &style, QWidget *parent):QLabel(parent)
{
    fontName = fontLib.getIconName();
    IconHelper::Instance()->setNewIcon(fontLib);
    iconhelp::setIcon(this,iconIndex);
    if(style != QString()){
        setStyleSheet(style);
    }else{
        QString finalStyle = DEFULT_LABEL_STYLE + \
                QString("QLabel{font:%1pt;}").arg(this->font().pointSize());
        setStyleSheet(finalStyle);
    }
    this->setAlignment(Qt::AlignCenter);
}

/**
 * @brief 重设图标，等价重调用setText方法
 * @param index 图标在字体库中索引号
 */
void BaseLabel::setIcon(int index)
{
    iconhelp::setIcon(this, index);
}

/**
 * @brief 重设图标大小
 * @param ptSize
 */
void BaseLabel::setIconSize(int ptSize)
{
    QString finalStyle = this->styleSheet() + \
            QString("QLabel{font:%1pt;}").arg(ptSize);

    setStyleSheet(finalStyle);
}

/**
 * @brief 重设字体库
 * @param fontLib 新字库
 */
void BaseLabel::setNewFont(const AbstractFont &fontLib)
{
    fontName = fontLib.getIconName();
    IconHelper::Instance()->setNewIcon(fontLib);
}
