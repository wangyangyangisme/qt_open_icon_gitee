#include "progressbar2.h"
#include "ui_progressbar2.h"

#define  PROGRESS_TOTAL_STYLE (QString(""\
    "QProgressBar {"\
    "background-color: #dbdee0;"\
    "border: 0px;"\
    ""\
    "}"\
    "QProgressBar::chunk {"\
    "background-color:  #FF5500" "}"))

ProgressBar2::ProgressBar2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProgressBar2)
{
    ui->setupUi(this);
    ui->leftBar->setStyleSheet(PROGRESS_TOTAL_STYLE);
    ui->rightBar->setStyleSheet(PROGRESS_TOTAL_STYLE);
    progressNum = 0;
    ui->leftBar->setValue(0);
    ui->rightBar->setValue(0);
}

void ProgressBar2::wheelEvent(QWheelEvent *event)
{
    int numDegrees = event->delta() / 8;//滚动的角度，*8就是鼠标滚动的距离
    int numSteps = numDegrees / 15;//滚动的步数，*15就是鼠标滚动的角度

    progressNum += numSteps;
    if(progressNum >=0){
        ui->rightBar->setValue(progressNum);
        ui->leftBar->setValue(0);
    }else{
        ui->leftBar->setValue(qAbs(progressNum));
        ui->rightBar->setValue(0);
    }

    ui->valLab->setNum(progressNum);
}
