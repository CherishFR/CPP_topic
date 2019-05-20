#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 通过ui寻找控件
    // ui->actionNew->setIcon(QIcon("C:/Users/47115/Pictures/Icon/timg.jpg"));
    // 添加资源文件到项目中
    // 使用资源文件 ": + 前缀名 + 文件名"
    ui->actionNew->setIcon(QIcon(":/Icon/timg.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
