/**
 ** @author:   浓咖啡
 ** @date:	   2018.6.1
 ** @brief:    重写标题栏:由于作者不懂设计，故望懂设计的码友帮忙重新做下样式
 */

#include "titlebar.h"
#include "fontawesomewebfont.h"

#define BUTTON_HEIGHT 30        // 按钮高度;
#define BUTTON_WIDTH 30         // 按钮宽度;
#define TITLE_HEIGHT 30         // 标题栏高度;

#define BUTTON_STYLE "\
QPushButton{\
    color:#000000;\
    border:1px solid #AAAAAA;\
    background-color:#FFFFFF;\
}\
QPushButton:pressed{\
    color:#FFFFFF;\
    background-color:#AAAAAA;\
}\
QPushButton:hover{\
    color: red;\
}\
"

#define DISABLE_BUTTON_STYLE "\
QPushButton{\
    color:#000000;\
    border:1px solid #AAAAAA;\
    background-color:#A9A9A9;\
}\
"

#define LABEL_STYLE "\
QLabel{\
    color:#FF00FF;\
    border:0px;\
    background-color:#8FBC8F;\
}\
"

#define TOTAL_STYLE "\
QWidget{\
    background-color:#8FBC8F;\
}\
"

#define PARENT_STYLE "\
#TitleParent{\
    background-color:#FFFAFA;\
    border:2px solid rgba(176, 196, 222);\
}\
"

TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent)
{
    //设置父窗体属性
    parentWig = parent;
    parentWig->setWindowFlags(Qt::FramelessWindowHint);
    parentWig->setObjectName("TitleParent");
    parentWig->setStyleSheet(PARENT_STYLE);

    //设置托盘显示属性
    isSysTray = true;
    initSysTray();

    //窗体主属性
    this->setFixedHeight(TITLE_HEIGHT);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->resize(this->parentWidget()->width(), TITLE_HEIGHT);
    this->setStyleSheet(TOTAL_STYLE);

    //应用图标
    iconLab = new BaseLabel(FontawesomeWebfont(), FontawesomeWebfont::ICON_WINDOW_SIGNAL);
    iconLab->setStyleSheet(LABEL_STYLE);
    iconLab->setIconSize(TITLE_HEIGHT/2);
    iconLab->setFixedSize(TITLE_HEIGHT, TITLE_HEIGHT);

    //标题
    titleLab = new QLabel;
    titleLab->setText(QString("通用标题栏"));
    titleLab->setStyleSheet("font-weight:bold");

    //右侧按钮
    minBtn = new BaseButton(FontawesomeWebfont(), FontawesomeWebfont::ICON_WINDOW_MINIMIZE);
    minBtn->setFixedSize(TITLE_HEIGHT, TITLE_HEIGHT);
    minBtn->setStyleSheet(BUTTON_STYLE);
    minBtn->setToolTip(QStringLiteral("最小化"));

    restoreBtn = new BaseButton(FontawesomeWebfont(), FontawesomeWebfont::ICON_WINDOW_RESTORE);
    restoreBtn->setFixedSize(TITLE_HEIGHT, TITLE_HEIGHT);
    restoreBtn->setStyleSheet(BUTTON_STYLE);
    restoreBtn->setToolTip(QStringLiteral("还原"));

    maxBtn = new BaseButton(FontawesomeWebfont(), FontawesomeWebfont::ICON_WINDOW_MAXIMIZE);
    maxBtn->setFixedSize(TITLE_HEIGHT, TITLE_HEIGHT);
    maxBtn->setStyleSheet(BUTTON_STYLE);
    maxBtn->setToolTip(QStringLiteral("最大化"));

    closeBtn = new BaseButton(FontawesomeWebfont(), FontawesomeWebfont::ICON_WINDOW_CLOSE);
    closeBtn->setFixedSize(TITLE_HEIGHT, TITLE_HEIGHT);
    closeBtn->setStyleSheet(BUTTON_STYLE);
    closeBtn->setToolTip(QStringLiteral("关闭"));

    QHBoxLayout* totalLay = new QHBoxLayout(this);
    totalLay->addWidget(iconLab);
    totalLay->addWidget(titleLab);
    totalLay->addWidget(minBtn);
    totalLay->addWidget(restoreBtn);
    totalLay->addWidget(maxBtn);
    totalLay->addWidget(closeBtn);

    totalLay->setMargin(0);
    totalLay->setSpacing(0);

    //信号与槽连接
    QObject::connect(minBtn, SIGNAL(clicked()),
                     this,  SLOT(minSlot()));
    QObject::connect(maxBtn, SIGNAL(clicked()),
                     this,  SLOT(maxSlot()));
    QObject::connect(restoreBtn, SIGNAL(clicked()),
                     this,  SLOT(restoreSlot()));
    QObject::connect(closeBtn, SIGNAL(clicked()),
                     this,  SLOT(closeSlot()));
}

/**
 * @brief 设置是否允许最大化
 * @param per
 */
void TitleBar::setPermitMax(bool per)
{
    isPermitMax = per;

    if(!per){
        //如果不允许最大化，改变下最大化按钮的样式
        maxBtn->setStyleSheet(DISABLE_BUTTON_STYLE);
        maxBtn->setEnabled(false);
    }else{
        maxBtn->setStyleSheet(BUTTON_STYLE);
        maxBtn->setEnabled(true);
    }
}

/**
 * @brief 设置最大化状态
 */
void TitleBar::setMaxState()
{
    maxBtn->setVisible(false);
    restoreBtn->setVisible(true);
    isMaxState = true;

    QRect desktopRect = QApplication::desktop()->availableGeometry();
    parentWig->setGeometry(desktopRect);
}

/**
 * @brief 设置窗体到普通状态
 */
void TitleBar::setNormalState()
{
    maxBtn->setVisible(true);
    restoreBtn->setVisible(false);
    isMaxState = false;

    parentWig->setGeometry(storeRect);
}

/**
 * @brief 设置窗体到最小状态
 */
void TitleBar::setMinimiState()
{
    if(isSysTray){ //如果允许使用系统托盘
        parentWig->hide();
        sysTrayIcon->show();
    }else{
        parentWig->showMinimized();
    }
}

void TitleBar::minSlot()
{
    emit minSignal();
    setMinimiState();
}

void TitleBar::maxSlot()
{
    emit maxSignal();
    setMaxState();
}

void TitleBar::restoreSlot()
{
    emit restoreSignal();
    setNormalState();
}

void TitleBar::closeSlot()
{
    emit closeSignal();
    parentWig->close();
}

/**
 * @brief 显示父窗体并存储父窗体首次显示的位置
 * 设置一些初始化参数
 */
void TitleBar::show()
{
    setPermitMax(true);
    parentWig->show();
    storeRect = parentWig->geometry();
    setNormalState();
}

/**
 * @brief 重绘事件需要重设自己宽度和父窗体一样大
 * @param event
 */
void TitleBar::paintEvent(QPaintEvent *event)
{
    if (this->width() != (parentWig->width()))
    {
        this->setFixedWidth(parentWig->width());
    }
    QWidget::paintEvent(event);
}

/**
 * @brief 处理双击事件
 * @param e
 */
void TitleBar::mouseDoubleClickEvent(QMouseEvent *e)
{
    //如果不允许最大化
    if(!isPermitMax){
        return;
    }

    //如果已经是在最大化状态
    if(isMaxState){
        setNormalState();
    }else{
        setMaxState();
    }

    return QWidget::mouseDoubleClickEvent(e);
}

/**
 * @brief TitleBar::mousePressEvent
 * @param event
 */
void TitleBar::mousePressEvent(QMouseEvent *event)
{
    isPressed = true;
    curMousePos = event->globalPos();

    return QWidget::mousePressEvent(event);
}

/**
 * @brief TitleBar::mouseReleaseEvent
 * @param event
 */
void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    isPressed = false;

    return QWidget::mouseReleaseEvent(event);
}

/**
 * @brief 和鼠标的点击和按下事件共同实现窗体的拖动效果
 * 先记录鼠标的点击位置，比如(100, 100)
 * 鼠标移动按下移动到(300, 50)的位置
 * 那么相对位移就是(200, -50)
 * 只要用窗体原位置和这个位置相加即可得到窗体拖动后新位置
 */
void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if (isPressed)
    {
        //如果窗体已经在最大化状态，那么先让它复原
        if(isMaxState){
            //保持鼠标位置在窗体移动一刻时候比例：这个逻辑不要想了，做出来就算了，杀脑细胞
            int xres = QApplication::desktop()->availableGeometry().width();
            int xMove = event->globalPos().x();
            int storeWidth = storeRect.width();
            int x = xMove - xMove * storeWidth / xres;

            storeRect.moveTo(x, 0);
            setNormalState();
            return QWidget::mouseMoveEvent(event);
        }
        QPoint movePoint = event->globalPos() - curMousePos;
        QPoint widgetPos = parentWig->pos();
        this->parentWidget()->move(movePoint + widgetPos);
        curMousePos = event->globalPos();
        storeRect = parentWig->geometry();
    }

    return QWidget::mouseMoveEvent(event);
}

#if 1
//下面代码是托盘显示程序
void TitleBar::initSysTray()
{
    sysTrayIcon = new QSystemTrayIcon(this);

    QIcon icon = QIcon(":/images/resourse/images/titlebar/icon.png");
    sysTrayIcon->setIcon(icon);
    sysTrayIcon->setToolTip("自定义标题栏");

    //给QSystemTrayIcon添加槽函数
    connect(sysTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),\
            this, SLOT(sysTrayIconSlot(QSystemTrayIcon::ActivationReason)));

    //初始化菜单项
    QAction *showMainAction = new QAction(QObject::trUtf8("显示主界面"), this);
    connect(showMainAction, SIGNAL(triggered()), \
            this, SLOT(showMainAction()));

    QAction *exitAppAction = new QAction(QObject::trUtf8("退出"), this);
    connect(exitAppAction, SIGNAL(triggered()), \
            this,SLOT(exitAppAction()));

    //初始化菜单
    QMenu *menu = new QMenu(this);
    menu->addAction(showMainAction);
    menu->addSeparator();
    menu->addAction(exitAppAction);

    sysTrayIcon->setContextMenu(menu);
}

void TitleBar::sysTrayIconSlot(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason){
    case QSystemTrayIcon::Trigger:
        this->show();
        break;
    case QSystemTrayIcon::DoubleClick:
        sysTrayIcon->showMessage(QObject::trUtf8("Message Title"),
                                 QObject::trUtf8("欢迎使用此程序"),
                                 QSystemTrayIcon::Information, 1000);
        break;
    default:
        break;
    }
}

void TitleBar::showMainAction()
{
    parentWig->show();
}

void TitleBar::exitAppAction()
{
    parentWig->close();
}
#endif
