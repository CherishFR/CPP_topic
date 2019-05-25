#include "widget.h"
#include "ui_widget.h"
#include <QDataStream>
#include <QMessageBox>
#include <QDateTime>
#include <QFileDialog>
#include <QColorDialog>

Widget::Widget(QWidget *parent, QString name) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 初始化操作
    udpsocket = new QUdpSocket(this);
    // 用户名获取
    uName = name;
    // 端口号
    this->port = 9999;

    // 绑定端口号  绑定模式 共享地址 | 断线重连
    udpsocket->bind(this->port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);

    // 发送新用户进入
    sndMsg(UsrEnter);

    // 点击按钮发送消息
    connect(ui->sendBtn, &QPushButton::clicked,[=](){
        sndMsg(Msg);
    });

    // 监听别人发送的数据
    connect(udpsocket, &QUdpSocket::readyRead, this, &Widget::ReceiveMessage);

    // 点击退出按钮关闭窗口
    connect(ui->exitBtn,&QPushButton::clicked,[=](){
        this->close();
    });

    //字体
    connect(ui->fontCbx,&QFontComboBox::currentFontChanged,[=](const QFont &font){
        ui->msgTextEdit->setCurrentFont(font);
        ui->msgTextEdit->setFocus();
    });

    //字号
    void(QComboBox:: *cbxsingal)(const QString &text) = &QComboBox::currentIndexChanged;
    connect(ui->sizeCbx,cbxsingal,[=](const QString &text ){
        ui->msgTextEdit->setFontPointSize(text.toDouble());
        ui->msgTextEdit->setFocus();
    });

    //加粗
    connect(ui->boldTBtn,&QToolButton::clicked,[=](bool isCheck){
        if(isCheck)
        {
            ui->msgTextEdit->setFontWeight(QFont::Bold);
        }
        else
        {
            ui->msgTextEdit->setFontWeight(QFont::Normal);
        }
    });

    //倾斜
    connect(ui->italicTBtn,&QToolButton::clicked,[=](bool check){

        ui->msgTextEdit->setFontItalic(check);
    });

    //下划线
    connect(ui->underlineTBtn,&QToolButton::clicked,[=](bool check){
        ui->msgTextEdit->setFontUnderline(check);
    });

    //字体颜色
    connect(ui->colorTBtn,&QToolButton::clicked,[=](){
        QColor color = QColorDialog::getColor(Qt::red);
        ui->msgTextEdit->setTextColor(color);

    });

    //清空聊天记录
    connect(ui->clearTBtn,&QToolButton::clicked,[=](){
        ui->msgBrowser->clear();
    });

    //保存聊天记录
    connect(ui->saveTBtn,&QToolButton::clicked,[=](){
        if(ui->msgBrowser->document()->isEmpty())
        {
            QMessageBox::warning(this,"警告","内容不能为空");
            return;

        }
        else
        {
             QString path = QFileDialog::getSaveFileName(this,"保存记录","聊天记录","(*.txt)");
             QFile file(path);
             //打开模式加换行操作
             file.open(QIODevice::WriteOnly | QIODevice::Text);
             QTextStream stream(&file);
             stream << ui->msgBrowser->toPlainText();
             file.close();
        }

    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::closeEvent(QCloseEvent * e){
    emit this->closeWidget();
    sndMsg(UsrLeft);
    udpsocket->close();
    udpsocket->destroyed();
    QWidget::closeEvent(e);
}

void Widget::sndMsg(MsgType type){
    // 发送的消息分为3种类型
    // 发送的数据做分段处理 第一段 类型 第二段 用户名 第三段 具体内容
    QByteArray array;
    QDataStream stream(&array,QIODevice::WriteOnly);

    stream << type << getUsr();  // 第一段、第二段内容添加到流中
    switch (type) {
    case Msg:  // 普通消息
        if(ui->msgTextEdit->toPlainText() == "")  // 如果用户没有输入内容，则不发
        {
            QMessageBox::warning(this, "警告", "发送内容不能为空");
            return ;
        }
        // 第二段数据，具体说的话
        stream << getMsg();
        break;
    case UsrEnter:  // 新用户进入消息

        break;
    case UsrLeft:  // 用户离开消息

        break;
    default:
        break;
    }

    // 书写报文  广播发送
    udpsocket->writeDatagram(array, QHostAddress::Broadcast, port);
}

QString Widget::getMsg(){
    QString str = ui->msgTextEdit->toHtml();

    //清空输入框
    ui->msgTextEdit->clear();
    ui->msgTextEdit->setFocus();
    return str;
}

void Widget::ReceiveMessage(){
    // 拿数据报文
    qint64 size = udpsocket->pendingDatagramSize();
    QByteArray array = QByteArray(size,0);
    udpsocket->readDatagram(array.data(),size);
    // 解析数据
    // 第一段 类型 第二段 用户名 第三段 具体内容
    QDataStream stream (&array,QIODevice::ReadOnly);
    int msgType;
    QString usrName;
    QString msg;
    stream >> msgType >> usrName;

    // 获取当前时间
    QString time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

    switch (msgType) {
        case Msg:  // 普通消息
            stream >> msg;

            // 追加聊天记录
            ui->msgBrowser->setTextColor(Qt::blue);
            ui->msgBrowser->append("[" + usrName + "]" + time);
            ui->msgBrowser->append(msg);
            break;
        case UsrEnter:  // 新用户进入消息
            usrEnter(usrName);
            break;
        case UsrLeft:  // 用户离开消息
            usrLeft(usrName, time);
            break;
        default:
            break;
    }
}

QString Widget::getUsr(){
    return this->uName;
}

void Widget::usrEnter(QString username){
    // 判断是否存在
    bool isempty = ui->usrTbeWidget->findItems(username, Qt::MatchExactly).isEmpty();
    if(isempty)
    {
        QTableWidgetItem * usr = new QTableWidgetItem(username);

        // 更新右侧的TableWidget
        ui->usrTbeWidget->insertRow(0);
        ui->usrTbeWidget->setItem(0,0,usr);

        // 最加聊天信息
        ui->msgBrowser->setTextColor(Qt::gray);
        ui->msgBrowser->append(QString("%1上线了").arg(username));

        // 在线人数更新
        ui->usrNumLbl->setText(QString("在线用户：%1人").arg(ui->usrTbeWidget->rowCount()));

        // 触发其他人更新
        sndMsg(UsrEnter);
    }
}

void Widget::usrLeft(QString username, QString time){
    bool isempty = ui->usrTbeWidget->findItems(username, Qt::MatchExactly).isEmpty();
    if(!isempty)
    {
        int row = ui->usrTbeWidget->findItems(username,Qt::MatchExactly).first()->row();
        ui->usrTbeWidget->removeRow(row);

        // 追加聊天记录
        ui->msgBrowser->setTextColor(Qt::gray);
        ui->msgBrowser->append(QString("%1与%2离开了").arg(username).arg(time));

        // 在线人数更新
        ui->usrNumLbl->setText(QString("在线用户：%1人").arg(ui->usrTbeWidget->rowCount()));

    }
}
