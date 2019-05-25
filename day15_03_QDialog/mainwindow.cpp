#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 点击新建菜单 弹出对话框
    connect(ui->actionNew,&QAction::triggered,this,[=](){
        // 对话框：模态对话框(不可对其他窗口操作)&非模态对话框(可对其他窗口操作)
        // QDialog dlg(this);
        // dlg.resize(200,100);
        // dlg.exec();  // 创建模态对话框，并阻塞

        // QDialog dlg(this);  // 创建在栈上 一闪而过
        // dlg.resize(200,100);
        // QDialog * dlg2 = new QDialog(this);  // 创建在堆上
        // dlg2->resize(200,100);
        // dlg2->show();  // 创建非模态对话框，不阻塞
        // 需要设置属性 dlg2
        // dlg2->setAttribute(Qt::WA_DeleteOnClose);  // 点击"X"释放指针，因为在堆上不会主动释放

        // 使用标准对话框 QMessageBox
        // 错误对话框
        // QMessageBox::critical(this, "错误！", "critical");
        // 信息对话框
        // QMessageBox::information(this, "信息", "info");
        // 询问对话框
        // （父亲，标题，提示内容，按键类型，关联回车的默认案件）
        // if(QMessageBox::Save == QMessageBox::question(this, "问题", "question", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Cancel))
        // {
        //     qDebug() << "点击的是保存";
        // }
        // else
        // {
        //     qDebug() << "点击的是取消";
        // }
        // 警告对话框
        // QMessageBox::warning(this, "警告！", "warning");

        // 颜色对话框
        // QColor color = QColorDialog::getColor(QColor(255,0,0));

        // 文件对话框
        // QString path = QFileDialog::getOpenFileName(this, "打开文件", "C:\\", "(*.txt *.png)");
        // qDebug() << path;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
