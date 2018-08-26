#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

#include <QWidget>

namespace Ui {
class RadioButton;
}

class RadioButton : public QWidget
{
    Q_OBJECT

public:
    explicit RadioButton(QWidget *parent = 0);
    ~RadioButton();

private:
    Ui::RadioButton *ui;
};

#endif // RADIOBUTTON_H
