/**
 ** @author:	   浓咖啡
 ** @date:	   2015.4.18
 ** @brief:     动画演示窗口，注意要把三幅图路径配置好
 */

#ifndef ANIMATIONTEST_H
#define ANIMATIONTEST_H

#include "animationwidget.h"

class AnimationTest : public QMainWindow
{
    Q_OBJECT
public:
    explicit AnimationTest(QWidget *parent = 0);
    void initMenuBar();
    void initToolBar();
    void initCenterWidget();
    void initStatusBar();
    void initConnect();

signals:

private slots:
    void finishSlot();

    void upSlot();
    void downSlot();

    void changeToSlide();
    void changeToCover();
    void changeToCenter();
    void changeToFly();
    void changeToSharp();

private:
    QMenu *menuAnimation;
    QAction *actSlide;
    QAction *actCover;
    QAction *actCenter;
    QAction *actFly;
    QAction *actSharp;

    QToolBar *toolBar;
    QAction *up;
    QAction *down;

    QLabel *status;

    AnimationWidget *center;
    QList<QWidget *> list;
    QWidget *wig1;
    QWidget *wig2;
    QWidget *wig3;
    int curWig;

    static const int w=510;
    static const int h=305;
};

#endif // ANIMATIONTEST_H
