/**
 ** @author:   浓咖啡
 ** @date:	   2018.6.1
 ** @brief:    重写标题栏:由于作者不懂设计，故望懂设计的码友帮忙重新做下样式
 */

#ifndef TITLEBAR_H
#define TITLEBAR_H

#include "basebutton.h"
#include "baselabel.h"

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    enum ButtonType
    {
        MIN_BUTTON = 0,         // 最小化和关闭按钮;
        MIN_MAX_BUTTON ,        // 最小化、最大化和关闭按钮;
        ONLY_CLOSE_BUTTON       // 只有关闭按钮;
    };

    //这里必须传递父部件指针
    explicit TitleBar(QWidget *parent);

    bool permitMax(){return isPermitMax;}
    void setPermitMax(bool);
    void setUseSysTray(bool val){isSysTray = val;}

    BaseLabel *iconLab;  //图标
    QLabel *titleLab;  //标题
    BaseButton *minBtn; //最小化按钮
    BaseButton *maxBtn;  //最大化按钮
    BaseButton *restoreBtn; //恢复按钮
    BaseButton *closeBtn; //关闭按钮
    QSystemTrayIcon *sysTrayIcon; //托盘图标

public slots:
    void show();

signals:
    void minSignal();
    void maxSignal();
    void restoreSignal();
    void closeSignal();

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void mouseDoubleClickEvent(QMouseEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);

private slots:
    void minSlot();
    void maxSlot();
    void restoreSlot();
    void closeSlot();
    void sysTrayIconSlot(QSystemTrayIcon::ActivationReason);
    void showMainAction();
    void exitAppAction();

private:
    QWidget *parentWig;  //保存父窗体

    bool isMaxState;  //是否已经在最大化状态
    bool isPermitMax; //是否允许最大化窗口
    bool isSysTray; //是否使用系统托盘

    QRect storeRect;  //用来记录原始位置和大小
    QPoint curMousePos;  //记录拖动时候鼠标位置
    bool isPressed;  //鼠标按下

    void setMaxState();
    void setNormalState();
    void setMinimiState();
    void initSysTray();
};

#endif // TITLEBAR_H
