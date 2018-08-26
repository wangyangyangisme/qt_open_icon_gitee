#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "buttontest.h"
#include "dialogtest.h"
#include "animationtest.h"
#include "wheeltest.h"
#include "toast.h"
#include "timetotal.h"
#include "desktop.h"
#include "listtest.h"
#include "digitalinputtest.h"
#include "progressbar2.h"
#include "navbartest.h"
#include "labeltest.h"
#include "titlebar.h"
#include "mylistwidget.h"
#include "mylistwidgetitem.h"
#include "databasewig.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(QString("主窗体"));

#ifdef RUN_EMBEDDED
    #include <QWSServer>
    QWSServer::setCursorVisible(false);
#else
    this->move((qApp->desktop()->width()-width())/2, (qApp->desktop()->height()-height())/2);
#endif
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_labTest_clicked()
{
    LabelTest *w = new LabelTest;
    w->show();
}

void MainWindow::on_btnTest_clicked()
{
    ButtonTest *w = new ButtonTest;
    w->show();
}

void MainWindow::on_dialogTest_clicked()
{
    DialogTest *w = new DialogTest;
    w->show();
}

void MainWindow::on_animationTest_clicked()
{
    AnimationTest *w = new AnimationTest;
    w->show();
}

void MainWindow::on_wheelTest_clicked()
{
    if(QT_VERSION >= QT_VERSION_CHECK(5,0,0)){
        bool touch = qApp->arguments().contains(QLatin1String("--touch"));
        WheelTest *w = new WheelTest(touch);
        w->show();
    }else{
        Toast *toast = new Toast(this, "当前版本不支持");
        toast->toast();
    }
}

void MainWindow::on_timeSetTest_clicked()
{
    if(QT_VERSION >= QT_VERSION_CHECK(5,0,0)){
        TimeTotal *w = new TimeTotal;
        w->setWindowTitle(QString("时间设置组件"));
        w->show();
    }else{
        Toast *toast = new Toast(this, "当前版本不支持");
        toast->toast();
    }
}

void MainWindow::on_deskTopTest_clicked()
{
    Desktop *w = new Desktop;
    w->show();
}

void MainWindow::on_listTest_clicked()
{
    ListTest *w = new ListTest;
    w->show();
}

void MainWindow::on_databaseTest_clicked()
{
    DataBaseWig *w = new DataBaseWig;
    w->setWindowTitle(QString("数据库测试"));
    w->show();
    return;
}

void MainWindow::on_progressBar2Test_clicked()
{
    ProgressBar2 *w = new ProgressBar2;
    w->setWindowTitle(QString("双路进度条"));
    w->show();
}

void MainWindow::on_digitalInputTest_clicked()
{
    DigitalInputTest *w = new DigitalInputTest;
    w->show();
}

void MainWindow::on_navBarTest_clicked()
{
    NavbarTest *w = new NavbarTest;
    w->show();
}

void MainWindow::on_titleBtn_clicked()
{
    QWidget *w = new QWidget;
    w->resize(500, 500);

    TitleBar *titleWig = new TitleBar(w);
    titleWig->show();
}

void MainWindow::on_btn_5_clicked()
{
    MyListWidget* w = new MyListWidget;
    w->resize(200,this->frameGeometry().height());
    w->addItem("智能家居");
    w->addItem("远程控制");
    w->addItem("环境温度");
    w->addItem("基础配置");
    w->show();
}
