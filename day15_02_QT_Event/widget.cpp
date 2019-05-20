#include "widget.h"
#include "ui_widget.h"
#include <QTimerEvent>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 启动定时器
    id1 = startTimer(1000);  // 每1000毫秒调用一次
    id2 = startTimer(2000);

    // 定时器第二种方式
    QTimer * timer1 = new QTimer(this);
    // 启用定时器对象
    timer1->start(500);  // 单位毫秒
    // 每隔0.5秒发送信号
    connect(timer1, &QTimer::timeout,[=](){
        static int num = 0;
        ui->label_4->setText(QString::number(num++));
    });
}

// 定时器事件
void Widget::timerEvent(QTimerEvent * ev)
{
    if(ev->timerId() == id1){
        static int num = 0;
        ui->label_2->setText(QString::number(num++));
    }
    if(ev->timerId() == id2){
        static int num2 = 0;
        ui->label_3->setText(QString::number(num2++));
    }
}


Widget::~Widget()
{
    delete ui;
}


