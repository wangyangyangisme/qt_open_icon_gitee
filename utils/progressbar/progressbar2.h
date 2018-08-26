#ifndef PROGRESSBAR2_H
#define PROGRESSBAR2_H

#include <QtWidgets>

namespace Ui {
class ProgressBar2;
}

/**
 * @brief 双路进度条
 */
class ProgressBar2 : public QWidget
{
    Q_OBJECT

public:
    explicit ProgressBar2(QWidget *parent = 0);

protected:
    virtual void wheelEvent(QWheelEvent *);

private:
    Ui::ProgressBar2 *ui;
    int progressNum;
};

#endif // PROGRESSBAR2_H
