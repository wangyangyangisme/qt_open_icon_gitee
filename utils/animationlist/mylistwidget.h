#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QWidget>
#include "mylistwidgetitem.h"
#include <QLabel>
#include <QTimer>

#define ITEM_HIGHT 40
#define ITEM_LEGHT 100

class MyListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyListWidget(QWidget *parent = 0);
    void resize(qreal x, qreal y);
    void addItem(const QString&);

    QVector<MyListWidgetItem> myItem;
    QLabel* lable;

signals:

protected:
    void paintEvent(QPaintEvent* event);
    void mouseMoveEvent(QMouseEvent*);
    void mousePressEvent(QMouseEvent*);

    void drawItem(QPainter *painter);
    void drawChooseItem(QPainter* painter);
    void drawListWidget(QPainter* painter);

    int length;
    int height;

    int rectBackGround;                             //鼠标滑动背景
    int oldChooseBackGround;                        //之前选择部件位置
    int newChooseBackGround;                        //当前选择部件位置

    int item_start_y;
    int chooseBackGround_y;                         //记录动态方框Y轴起始
    int mouse_state;                                //鼠标在第几项
    QImage itemBack;

    QTimer* sliderTimer;

protected slots:
    void doSlider();



};

#endif // MYLISTWIDGET_H
