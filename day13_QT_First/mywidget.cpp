#include "mywidget.h"
#include <QPushButton>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)  // 初始化列表
{
    // 按钮
    QPushButton * btn = new QPushButton;
    // btn->show();  //show用顶层的方式弹出，如果想在MyWidget窗口中显示，就需要依赖MyWidget窗口
    // 设置父亲
    btn->setParent(this);

    // 设置文字
    btn->setText("天涯明月刀");  // 将char*隐式类型转换为QString

    // 创建按钮的第二种方式 窗口按照btn2大小显示
    QPushButton * btn2 = new QPushButton("第二个按钮", this);
    // 重置窗口大小
    this->resize(600, 400);

    // 移动第二个按钮
    btn2->move(100, 100);

    // 重置第二个按钮大小
    btn2->resize(100,50);

    // 重置窗口标题
    setWindowTitle("Qt第一个窗口");

    // 设置固定窗口大小
    setFixedSize(600, 400);

}

MyWidget::~MyWidget()
{

}
