#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    // 定时器事件
    void timerEvent(QTimerEvent *);

    // 定时器标识号
    int id1;
    int id2;
};

#endif // WIDGET_H
