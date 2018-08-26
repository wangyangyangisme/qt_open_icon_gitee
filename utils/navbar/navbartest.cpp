#include "navbartest.h"
#include "ui_navbartest.h"
#include "muifont.h"

#define BTN_STYLE "\
QPushButton{\
    color:#0000FF;\
    border:0px;\
    border-radius:0;\
}\
QPushButton:pressed{\
    color:#79CDCD;\
}\
"

#define TOTAL_STYLE "\
QWidget{\
    background-color:#FFEFD5;\
}\
"

NavbarTest::NavbarTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NavbarTest)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("通用导航栏"));

    //全部展示
    ui->total->setTitle("全部展示");

    //仅有标题
    ui->onlyTitle->hideLBtn();
    ui->onlyTitle->hideRBtn();
    ui->onlyTitle->setTitle("仅标题");

    //没有返回
    ui->noBack->hideLBtn();
    ui->noBack->setTitle("无返回按钮");
    ui->noBack->setRText("选项");

    //没有功能按钮
    ui->noFunc->hideRBtn();
    ui->noFunc->setTitle("无功能按钮");

#if (QT_VERSION >= QT_VERSION_CHECK(5,0,0))
    //自定义按钮和样式
    int barH = ui->userBar->height();

    //左边按钮
    BaseButton *newBackBtn = new BaseButton(MuiFont(), MuiFont::ICON_BACK);
    newBackBtn->setMinimumHeight(barH);
    newBackBtn->setStyleSheet(BTN_STYLE);  //新的按钮样式
    newBackBtn->setIconSize(2*barH/3);
    newBackBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    //右边的按钮
    BaseButton *newFuncBtn = new BaseButton(MuiFont(), MuiFont::ICON_BARS);
    newFuncBtn->setMinimumHeight(barH);
    newFuncBtn->setStyleSheet(BTN_STYLE);  //新的按钮样式
    newFuncBtn->setIconSize(2*barH/3);
    newFuncBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    //统一替换
    ui->userBar->setLBtn(newBackBtn);
    ui->userBar->setRBtn(newFuncBtn);
    ui->userBar->setTitle("自定义样式");

    //设置新的样式
    ui->userBar->setStyleSheet(TOTAL_STYLE);
#endif

    //信号和槽连接
    connect(ui->total, SIGNAL(lBtnSig()),
                     this, SLOT(lBtnSlot()));
    connect(ui->total, SIGNAL(rBtnSig()),
                     this, SLOT(rBtnSlot()));
}

void NavbarTest::lBtnSlot()
{
    qDebug()<<"lBtnSlot";
}

void NavbarTest::rBtnSlot()
{
    qDebug()<<"rBtnSlot";
}

NavbarTest::~NavbarTest()
{
    delete ui;
}
