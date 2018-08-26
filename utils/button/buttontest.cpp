#include "buttontest.h"
#include "ui_buttontest.h"
#include "muifont.h"

//渐变样式示例
#define SWITCH_BUTTON_STYLE "\
QPushButton{\
    color:QLinearGradient(x1:0, y1:0, x2:0, y2:1,stop:0 #CC00CC, stop:1 #CCFF99);\
    border:1px solid #AAAAAA;\
    border-radius:5;\
    background: QLinearGradient(x1:0, y1:0, x2:0, y2:1,stop:0 #0066FF, stop:1 #33FFFF);\
}\
QPushButton:pressed{\
    color:QLinearGradient(x1:0, y1:0, x2:0, y2:1,stop:0 #CCEEFF, stop:1 #F0BBFF);\
    background: QLinearGradient(x1:0, y1:0, x2:0, y2:1,stop:0 #FF8800, stop:1 #FFFF77);\
}\
"

#define DEFULT_LABEL_STYLE "\
QLabel{\
    color:#000000;\
    font:40px;\
    border:0px;\
    background-color:rgb(0,0,0,0);\
}\
"

//组合按钮

#define ICON_STYLE "\
QLabel{\
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

ButtonTest::ButtonTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ButtonTest)
{
    ui->setupUi(this);

    ui->baseButton->setNewFont(MuiFont());
    ui->baseButton->setIcon(MuiFont::ICON_WEINXIN);
    ui->baseButton->setIconSize(70);

    ui->batteryButton->setNewFont(FontawesomeWebfont());
    ui->batteryButton->setIcon(BatteryButton::EMPTY);

    ui->switchButton->setIcon(FontawesomeWebfont::ICON_UNLOCK);
    ui->switchButton->setStyleSheet(SWITCH_BUTTON_STYLE);
    ui->switchButton->setIconSize(80);

#if 0
    int w = ui->groupButton->width();
    int h = ui->groupButton->height();

    ui->groupButton->getIconLab()->setFixedSize(w, h*2/3);
    ui->groupButton->getIconLab()->setNewFont(MuiFont());
    ui->groupButton->getIconLab()->setIcon(MuiFont::ICON_WEINXIN);
    ui->groupButton->setStyleSheet(ICON_STYLE);
    ui->groupButton->getIconLab()->setIconSize(30);

    ui->groupButton->getTextLab()->setFixedSize(w, h*1/3);
    ui->groupButton->setStyleSheet(TEXT_STYLE);
    ui->groupButton->setStyleSheet(ALL_STYLE);
#endif
}

ButtonTest::~ButtonTest()
{
    delete ui;
}
