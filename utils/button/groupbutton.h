#ifndef GROUPBUTTON_H
#define GROUPBUTTON_H

#include "baselabel.h"

class GroupButton : public QPushButton
{
    Q_OBJECT
public:
    explicit GroupButton(QWidget *parent = 0);

    explicit GroupButton(const AbstractFont &fontLib, int iconIndex, \
                         int w, int h, const QString &text, const QString &style1, const QString &style2);

    BaseLabel *getIconLab(){return labIcon;}
    QLabel *getTextLab(){return labText;}

signals:

public slots:

private:
    BaseLabel *labIcon;  //放图形
    QLabel *labText;  //放文字
};

#endif // GROUPBUTTON_H
