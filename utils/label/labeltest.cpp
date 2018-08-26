/**
 ** @author:	浓咖啡
 ** @date:      2018.3.1
 ** @brief:     演示ui编辑器中图标库使用
 */

#include "labeltest.h"
#include "ui_labeltest.h"
#include "muifont.h"
#include "fontawesomewebfont.h"

#define LABEL_STYLE "\
QLabel{\
    color:#000000;\
    border:1px solid #AAAAAA;\
    background-color:rgb(255,255,255);\
}\
"

#define LABEL_STYLE2 "\
QLabel{\
    color:QLinearGradient(x1:0, y1:0, x2:0, y2:1,stop:0 #CC00CC, stop:1 #CCFF99);\
    border:1px solid #AAAAAA;\
    background: QLinearGradient(x1:0, y1:0, x2:0, y2:1,stop:0 #0066FF, stop:1 #33FFFF);\
}\
"

LabelTest::LabelTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LabelTest)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("基础标签"));

    //因为setupUi方法是构造方法调用后才执行，故必须重写设置
    //setupUi方法中修改过的属性
    ui->weixinLab->setIcon(MuiFont::ICON_WEINXIN);
    ui->weixinLab->setStyleSheet(LABEL_STYLE);
    ui->weixinLab->setIconSize(45);

    //使用一个新的图标库生成一个图标
    ui->lockLab->setNewFont(FontawesomeWebfont());
    ui->lockLab->setIcon(FontawesomeWebfont::ICON_LOCK);
    ui->lockLab->setStyleSheet(LABEL_STYLE2);
    ui->lockLab->setIconSize(45);
}

LabelTest::~LabelTest()
{
    delete ui;
}
