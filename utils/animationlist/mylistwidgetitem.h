#ifndef MYLISTWIDGETITEM_H
#define MYLISTWIDGETITEM_H

#include <QGraphicsItem>
#include <QWidget>

class MyListWidgetItem
{
public:
    MyListWidgetItem();
    MyListWidgetItem(QString str):m_strData(str){}
    QRectF boundingRect() const;
    void paintEvent();
    void setColor(const QColor &color){brushColor = color;}
    QString getText() const;
private:
    QColor brushColor;
    QString m_strData;

};

#endif // MYLISTWIDGETITEM_H
