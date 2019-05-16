#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:
    // 自定义槽函数
    // 高版本可以写在public或者全局函数下
    // 槽函数返回值也是void
    // 槽函数需要声明也需要实现
    // 槽函数也可以由参数，可以重载
    void treat();

    void treat(QString foodName);
};

#endif // STUDENT_H
