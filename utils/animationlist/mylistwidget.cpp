#include "mylistwidget.h"
#include "mylistwidgetitem.h"
#include <QPainter>
#include <QMouseEvent>
#include <QToolTip>
#include <QLabel>
#include <QDebug>

MyListWidget::MyListWidget(QWidget *parent) : QWidget(parent)
{
    item_start_y = 0;
    setMouseTracking(true);
    rectBackGround = 0;
    oldChooseBackGround = 0;
    newChooseBackGround = 0;
    chooseBackGround_y = 0;
    mouse_state = 0;
    sliderTimer = new QTimer(this);
    sliderTimer->setInterval(1);
    connect(sliderTimer, SIGNAL(timeout()), this, SLOT(doSlider()));
}

void MyListWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    drawListWidget(&painter);
    drawChooseItem(&painter);
    drawItem(&painter);
}

void MyListWidget::mouseMoveEvent(QMouseEvent *event)
{
    QString pos = QString("%1, %2").arg(event->pos().x()).arg(event->pos().y());
    //QToolTip::showText(event->globalPos(), pos, this);
    if((event->pos().x()<length) && (event->pos().y())){
        if(event->pos().y() <= myItem.count()*ITEM_HIGHT){
            rectBackGround = event->pos().y()/ ITEM_HIGHT;
            update();
        }
    }
}

void MyListWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){               //如果是鼠标左键按下
        if((event->pos().x()<length) && (event->pos().y())){
            if(event->pos().y() <= myItem.count()*ITEM_HIGHT){
                newChooseBackGround = event->pos().y()/ ITEM_HIGHT;
                sliderTimer->start();
            }
        }
    }
}

void MyListWidget::addItem(const QString&str)
{
    MyListWidgetItem item(str);
    myItem.push_back(item);
}

void MyListWidget::resize(qreal x, qreal y)
{
    this->setFixedSize(x,y);
    height = y;
    length = x;
}

void MyListWidget::drawItem(QPainter *painter)
{
    int item_num = 0;
    //画ITEM位置，循环画出
    for(item_num=0; item_num<myItem.count();item_num++){
        if(item_num == rectBackGround)
        {
            if(rectBackGround != newChooseBackGround){
                painter->setPen(Qt::NoPen);
                QBrush brush(QColor(50, 50, 50), Qt::SolidPattern);
                painter->setBrush(brush);
                painter->drawRect(0, rectBackGround*ITEM_HIGHT, length, ITEM_HIGHT);
            }

            QRectF rect(0, rectBackGround*ITEM_HIGHT, length, ITEM_HIGHT);
            painter->setPen(QPen(QBrush("red"), 3));
            QFont font("黑体", 13, 10, false);
            painter->setFont(font);
            painter->drawText(rect, myItem.at(item_num).getText(), Qt::AlignVCenter|Qt::AlignHCenter);
            if(item_num+1 < myItem.count())
                item_start_y = item_start_y+ITEM_HIGHT;
            painter->setPen(QPen(QBrush("white"), 3));
        }
        else{
            QFont font("黑体", 13, 10, false);
            painter->setFont(font);
            painter->setPen(QPen(QBrush("white"), 3));
            QRectF rect(0, item_start_y, length, ITEM_HIGHT);
            painter->drawText(rect, myItem.at(item_num).getText(), Qt::AlignVCenter|Qt::AlignHCenter);
            if(item_num+1 < myItem.count())
                item_start_y = item_start_y+ITEM_HIGHT;
        }
    }
    item_start_y = 0;
}

void MyListWidget::drawChooseItem(QPainter* painter)
{
    painter->setPen(Qt::NoPen);
    QBrush brush(QColor(88, 86, 86), Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawRect(0, chooseBackGround_y, length-5, ITEM_HIGHT);
    brush.setColor(QColor(200, 33, 37));
    painter->setBrush(brush);
    painter->drawRect(length-5, chooseBackGround_y, 5, ITEM_HIGHT);


}

void MyListWidget::drawListWidget(QPainter* painter)
{
    QPen pen(Qt::NoPen);
    painter->setPen(pen);
    //反锯齿
    painter->setRenderHint(QPainter::Antialiasing);

    QLinearGradient linerGradient(QPointF(0,0), QPointF(0,this->height));
    linerGradient.setColorAt(0.0, QColor(30, 30, 39));
    linerGradient.setColorAt(1.0, QColor(35, 36, 40));
    painter->setBrush(linerGradient);
    painter->drawRect(0,0,length,this->height);

}

void MyListWidget::doSlider()
{
    if(chooseBackGround_y!=newChooseBackGround*ITEM_HIGHT){
        if(chooseBackGround_y>newChooseBackGround*ITEM_HIGHT)
            chooseBackGround_y--;
        else
            chooseBackGround_y++;
    }else{
        oldChooseBackGround= newChooseBackGround;
        sliderTimer->stop();
    }

    update();

}
