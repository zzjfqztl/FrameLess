#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "FramelessHelper.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_btnMin_clicked();
    void on_btnMax_clicked();
    void on_btnExit_clicked();
    void slotMax(bool bMax);

private:
    Ui::MainWindow *ui;
    FramelessHelper* mHelper;   //无边框窗口工具类

};

#endif
