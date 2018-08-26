/**
 ** @author:    浓咖啡
 ** @date:      2017.6.4
 ** @brief:     上下结构的组合按钮，上面是图标，下面是文字
 */

#include "groupbutton.h"
#include "muifont.h"

#define ICON_STYLE "\
QLabel{\
    font:50px;\
    color:rgb(44, 134, 0);\
}\
"

#define TEXT_STYLE "\
QLabel{\
    font:20px;\
    color:rgb(44, 134, 0);\
}\
"
#define ALL_STYLE "\
QPushButton{\
    border:1px solid rgb(44, 134, 0);\
    border-radius:5;\
    background: QLinearGradient(x1:0, y1:0, x2:0, y2:1,stop:0 rgb(255, 255, 255), stop:1 rgb(199, 255, 235));\
}\
QPushButton:pressed{\
    background-color:#AAAAAA;\
}\
"

GroupButton::GroupButton(QWidget *parent) : QPushButton(parent)
{
    int w = 200;
    int h = 100;

    labIcon = new BaseLabel(MuiFont(), MuiFont::ICON_WEINXIN, ICON_STYLE);
    labIcon->setFixedSize(w, h*2/3);
    labIcon->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    labIcon->setStyleSheet(ICON_STYLE);

    labText = new QLabel("微信");
    labText->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    labText->setFixedSize(w, h*1/3);
    labText->setStyleSheet(TEXT_STYLE);

    QVBoxLayout *vlay = new QVBoxLayout(this);
    vlay->setMargin(0);
    vlay->setSpacing(0);

    vlay->addWidget(labIcon);
    vlay->addWidget(labText);

    this->setFocusPolicy(Qt::NoFocus);
    this->setStyleSheet(ALL_STYLE);
}

/**
 * @brief GroupButton::GroupButton
 * @param fontLib 使用的图标库
 * @param iconIndex 上方图标索引
 * @param w 总宽度
 * @param h 总高度，图标占2/3,文字占1/3
 * @param text 文字内容
 * @param style1 图标样式
 * @param style2 文字样式
 */
GroupButton::GroupButton(const AbstractFont &fontLib, int iconIndex, \
                         int w, int h, const QString &text, const QString &style1, const QString &style2)
{
    //初始化第一个label
    if(!style1.isEmpty()){
        labIcon = new BaseLabel(fontLib, iconIndex, style1);
        labIcon->setFixedSize(w, h*2/3);
    }else{
        labIcon = new BaseLabel(fontLib, iconIndex, ICON_STYLE);
        labIcon->setFixedSize(w, h*2/3);
    }
    labIcon->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);

    //初始化第二个label
    labText = new QLabel(text);
    labText->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    labText->setFixedSize(w, h*1/3);
    if(!style2.isEmpty()){
        labText->setStyleSheet(style2);
    }else{
        labText->setStyleSheet(TEXT_STYLE);
    }

    QVBoxLayout *vlay = new QVBoxLayout(this);
    vlay->setMargin(0);
    vlay->setSpacing(0);

    vlay->addWidget(labIcon);
    vlay->addWidget(labText);

    this->setFocusPolicy(Qt::NoFocus);
    this->setFixedSize(w, h);
    this->setStyleSheet(ALL_STYLE);
}
