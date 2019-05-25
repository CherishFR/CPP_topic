#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

    enum MsgType {Msg, UsrEnter, UsrLeft};

public:
    explicit Widget(QWidget *parent, QString name);
    ~Widget();

    // 关闭事件
    void closeEvent(QCloseEvent *);

    void sndMsg(MsgType type);  // 广播UDP消息
    void usrEnter(QString username);  // 处理新用户加入
    void usrLeft(QString username, QString time);  // 处理用户离开
    QString getUsr();  // 获取用户名
    QString getMsg();  // 获取聊天信息
private:
    Ui::Widget *ui;

    QUdpSocket * udpsocket;
    quint16 port;
    QString uName;

    void ReceiveMessage();  // 接受UDP消息

signals:
    // 关闭窗口发送关闭信号
    void closeWidget();
};

#endif // WIDGET_H
