#include "widget.h"
#include <QPushButton>

// 需求： 创建两个类 Teacher类 Student类
// 下课后 Teacher类 dy 发出一个信号：饿了
// 学生响应型号 处理型号的槽函数：请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    dy = new Teacher(this);
    ljt = new Student(this);
    // 连接 老师和学生
    //connect(dy, &Teacher::hungry, ljt, &Student::treat);

    // 有参数的连接
    // 函数指针 执行函数地址
    // void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    // void(Student:: *studentSlot)(QString) = &Student::treat;
    // connect(dy, teacherSignal, ljt, studentSlot);

    // 下课
    // classIsOver();

    // 点击按钮 触发下课
    QPushButton * btn = new QPushButton("下课", this);
    // 促发无参 信号和槽
    void(Teacher:: *noTeacherSignal)(void) = &Teacher::hungry;
    void(Student:: *noStudentSlot)(void) = &Student::treat;

    connect(btn, &QPushButton::clicked, dy, noTeacherSignal);
    // connect(btn, &QPushButton::clicked, this, &Widget::close);
    connect(dy, noTeacherSignal, ljt, noStudentSlot);

    // 断开信号和槽
    //disconnect(dy, noTeacherSignal, ljt, noStudentSlot);

    // 拓展
    // 1.信号可以连接信号
    // 2.信号和槽可以断开 disconnect
    // 3.一个信号可以触发多个槽函数
    // 4.多个信号可以连接同一个槽
    // 5.信号和槽参数必须一一对应
    // 6.信号的参数个数可以多余槽参数个数，但是必须类型一一对应

    // QT4的写法,类型不匹配不检测
    connect(dy, SIGNAL(hungry(Qstring)), ljt, SLOT(treat(Qstring)));

    // 重置大小
    resize(600, 400);

    QPushButton * btn2 = new QPushButton("test", this);
    [=](){
        btn2->setText("bbb");
    }();
}

Widget::~Widget()
{

}

void Widget::classIsOver(){
    // 触发老师饿了的信号
    // 老师饿了的信号属于自定义信号
    // 触发自定义信号关键字 emit
    emit dy->hungry();
    emit dy->hungry("宫保鸡丁");
}
