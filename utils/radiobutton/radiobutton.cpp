#include "radiobutton.h"
#include "ui_radiobutton.h"

RadioButton::RadioButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RadioButton)
{
    ui->setupUi(this);
}

RadioButton::~RadioButton()
{
    delete ui;
}
