#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//https://blog.csdn.net/GoForwardToStep/article/details/53494800
#include <QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_labTest_clicked();

    void on_btnTest_clicked();

    void on_dialogTest_clicked();

    void on_animationTest_clicked();

    void on_wheelTest_clicked();

    void on_timeSetTest_clicked();

    void on_deskTopTest_clicked();

    void on_listTest_clicked();

    void on_databaseTest_clicked();

    void on_progressBar2Test_clicked();

    void on_digitalInputTest_clicked();

    void on_navBarTest_clicked();

    void on_titleBtn_clicked();

    void on_btn_5_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
