#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);


    setStyleSheet("QMainWindow{color:#E8E8E8;background:#43CD80;}\
                  QWidget#widgetTitle{background:#363636;}\
                  QLabel#labelTitle{color:white;padding:8px 0px 5px;}\
                  QPushButton#btnMin,QPushButton#btnMax,QPushButton#btnExit{\
                      border-radius:0px;\
                      color: #F0F0F0;\
                      background-color:rgba(0,0,0,0);\
                      border-style:none;}\
                  QPushButton#btnMin:hover,QPushButton#btnMax:hover{\
                      background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(25, 134, 199, 0), stop:1 #5CACEE);}\
                  QPushButton#btnExit:hover{\
                      background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(238, 0, 0, 128), stop:1 rgba(238, 44, 44, 255));}");

    ui->btnMin->setIcon(QIcon(":/image/min.png"));
    ui->btnMax->setIcon(QIcon(":/image/max1.png"));
    ui->btnExit->setIcon(QIcon(":/image/exit.png"));

    mHelper = new FramelessHelper(this);
    mHelper->activateOn(this);              //激活当前窗体
    mHelper->setTitleHeight(30);            //设置窗体的标题栏高度
    mHelper->setWidgetMovable(true);        //设置窗体可移动
    mHelper->setWidgetResizable(true);      //设置窗体可缩放
    //mHelper->setRubberBandOnResize(true); //设置橡皮筋效果-可缩放
    //mHelper->setRubberBandOnMove(true);   //设置橡皮筋效果-可移动
    //mHelper->setMax(this,true);           //最大化
    //绑定最大化/取消最大化信号，修改最大化图标
    connect(mHelper, &FramelessHelper::sigMax, this, &MainWindow::slotMax);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnMin_clicked()
{
    showMinimized();
}

void MainWindow::on_btnMax_clicked()
{
    mHelper->setMax(this, !mHelper->isMax(this));
}

void MainWindow::on_btnExit_clicked()
{
//    qApp->exit();
    close();
}

void MainWindow::slotMax(bool bMax)
{
    if (bMax)
    {
        ui->btnMax->setIcon(QIcon(":/image/max2.png"));
    }
    else
    {
        ui->btnMax->setIcon(QIcon(":/image/max1.png"));
    }
}
