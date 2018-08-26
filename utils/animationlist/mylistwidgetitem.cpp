#include "mylistwidgetitem.h"
#include <QPainter>
MyListWidgetItem::MyListWidgetItem()
{
    brushColor = Qt::red;

}

QRectF MyListWidgetItem::boundingRect() const
{
    qreal adjust = 0.5;
    return QRectF(-10-adjust,-10-adjust,
                  20+adjust, 20+adjust);
}


QString MyListWidgetItem::getText() const
{
    return m_strData;
}
