#include "student.h"
#include<QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug() << "请客吃饭";
}

void Student::treat(QString foodName)
{
    qDebug() << "请客吃饭," << foodName;
    // QString 转 char*
    // 1.转成QByteArray类型
    // 2.再转char*
    qDebug() << "请客吃饭," << foodName.toUtf8().data();
}
