#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
#include <QTextStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 点击按钮选取文件
    connect(ui->pushButton, &QPushButton::clicked,[=](){
        QString path = QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\jszx1\\Desktop");
        if(path.isEmpty()){
            QMessageBox::warning(this,"警告","打开失败");
        }
        else {
            // 将路径放入到lineEdit
            ui->lineEdit->setText(path);
            // 读文件
            QTextCodec * codec = QTextCodec::codecForName("gbk");
            QFile file(path); // 参数路径名称,默认格式utf-8
            // 指定打开方式
            // file.open(QIODevice::ReadOnly);
            file.open(QFileDevice::ReadOnly);

            QByteArray array;
            array = file.readAll();

            // 设置到文本编辑框中
            // ui->textEdit->setText(array);
            // 读gbk
            ui->textEdit->setText(codec->toUnicode(array));
            file.close();

            // 写文件
            // 重新指定打开方式
//            file.open(QFileDevice::Append);
//            file.write("哈哈哈哈哈哈");
//            file.close();

            // 通过QFileInfo读取文件信息
            QFileInfo info(path);
            qDebug() << "路径：" << info.filePath() << " 名称：" << info.fileName()
                     << " 文件大小：" << info.size() << " 后缀名：" << info.suffix();
            qDebug() << "创建日期：" << info.birthTime().toString("yyyy-MM-dd hh:mm:ss");
            qDebug() << "修改日期：" << info.lastModified().toString("yyyy/MM/dd hh:mm:ss");
        }
    });

    // 文件流读写文件
    // 分类：文本流（基础数据类型） 和 数据流(大型QImage)

    //文本流
//    QFile file("aaa.txt");
//    file.open(QFileDevice::WriteOnly);
//    QTextStream stream(&file);
//    stream << QString("hello world");
//    file.close();
//    // 读取
//    file.open(QFileDevice::ReadOnly);
//    QString str;
//    // stream >> str;  // 读到空格结束
//    str = stream.readAll();
//    qDebug() << str;

    // 数据流 以二进制进行写入
    QFile file("bbb.txt");
    file.open(QFileDevice::WriteOnly);
    QDataStream stream(&file);
    stream << QString("hello world") << 123456;
    file.close();

    //读取
    file.open(QFileDevice::ReadOnly);
    QString str;
    int num;
    stream >> str >> num;
    qDebug() << str << num;
}

Widget::~Widget()
{
    delete ui;
}
