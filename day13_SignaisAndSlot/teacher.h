#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    // 自定义的型号 需要写到signals下面
    // 返回类型必须是void
    // 信号只需要声明不需要实现
    // 信号可以由参数，可以重载
    void hungry();

    void hungry(QString foodName);

public slots:
};

#endif // TEACHER_H
