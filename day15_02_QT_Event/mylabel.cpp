#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{

}

// 鼠标进入
void MyLabel::enterEvent(QEvent *)
{
    qDebug() << "鼠标进入了";
}

// 鼠标离开
void MyLabel::leaveEvent(QEvent *)
{
    qDebug() << "鼠标离开了";
}

// 鼠标按下
void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    // 如果鼠标按左键就提示，右键不提示
    if(ev->button() == Qt::LeftButton)
    {
        // 按下的位置
        QString str = QString("鼠标按下了!! x=%1,y=%2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
    }
}

bool MyLabel::event(QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent * ev = static_cast<QMouseEvent *>(e);
        QString str = QString("event::鼠标按下了!! x=%1,y=%2").arg(ev->x()).arg(ev->y());
        qDebug() << str;
        return true;
    }
    // 其他事件让父亲处理
    return QLabel::event(e);

}
