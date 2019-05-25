#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 单选按钮 默认选择男
    ui->radioMan->setChecked(true);

    // 点击女的就打印一句话
    connect(ui->radioWoman, &QRadioButton::clicked,[=](){
        qDebug()<< "选中女的";
    });

    // 多选框 选中后打印内容
    // 选中是2 未选中是0
    connect(ui->checkBox, &QCheckBox::stateChanged,[=](int state){
        qDebug() << state;
    });

    // 利用listWidget写诗
    // QListWidgetItem * item = new QListWidgetItem("苟利国家生死以");
    // 设置对其方式
    // item->setTextAlignment(Qt::AlignCenter);
    // ui->listWidget->addItem(item);

    //QStringList -- QList<String>
    QStringList list;
    list << "苟利国家生死以" << "岂因祸福避趋之";
    ui->listWidget->addItems(list);

    // treeWidget控件
    // 添加头
    QStringList list2;
    list2 << "英雄" << "英雄介绍";
    ui->treeWidget->setHeaderLabels(list2);
    // 添加项目
    QTreeWidgetItem * liItem = new QTreeWidgetItem(QStringList() << "力量");
    QTreeWidgetItem * minItem = new QTreeWidgetItem(QStringList() << "敏捷");
    QTreeWidgetItem * zhiItem = new QTreeWidgetItem(QStringList() << "智力");
    // 添加顶层项目
    ui->treeWidget->addTopLevelItem(liItem);
    ui->treeWidget->addTopLevelItem(minItem);
    ui->treeWidget->addTopLevelItem(zhiItem);
    // 追加子项目
    QStringList heroL1;
    QStringList heroL2;
    heroL1 << "钢背兽" << "前排坦克，可吸收伤害";
    heroL2 << "船长" << "前排坦克，可肉可输出可控场";
    QTreeWidgetItem * li1 = new QTreeWidgetItem(heroL1);
    QTreeWidgetItem * li2 = new QTreeWidgetItem(heroL2);
    liItem->addChild(li1);
    liItem->addChild(li2);

    // QTableWidget控件
    // 告诉控件一共多少列
    QStringList list3;
    list3 << "姓名" << "性别" << "年龄";
    ui->tableWidget->setColumnCount(list3.size());
    // 设置水平方向的头
    ui->tableWidget->setHorizontalHeaderLabels(list3);
    // 设置行数
    ui->tableWidget->setRowCount(1);
    // 设置正文
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("刘锦涛"));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem("男"));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem("23"));
    // 点击按钮添加
    connect(ui->addBtn,&QPushButton::clicked,[=](){
        // 先判断是否有赵熙，有则不添加
        if(ui->tableWidget->findItems("赵熙",Qt::MatchExactly).empty())
        {
            ui->tableWidget->insertRow(0);
            ui->tableWidget->setItem(0, 0, new QTableWidgetItem("赵熙"));
            ui->tableWidget->setItem(0, 1, new QTableWidgetItem("女"));
            ui->tableWidget->setItem(0, 2, new QTableWidgetItem("22"));
        }
        else
        {
            QMessageBox::warning(this,"警告","已有赵熙");
        }

    });
    // 点击按钮删除
    connect(ui->delBtn,&QPushButton::clicked,[=](){
        // 先判断是否有赵熙，有则不添加
        if(ui->tableWidget->findItems("赵熙",Qt::MatchExactly).empty())
        {
            QMessageBox::warning(this,"警告","没有赵熙");
        }
        else
        {
            // 找到赵熙的行数
            int row = ui->tableWidget->findItems("赵熙",Qt::MatchExactly).first()->row();
            ui->tableWidget->removeRow(row);
            ui->tableWidget->setItem(0, 0, new QTableWidgetItem("赵熙"));
            ui->tableWidget->setItem(0, 1, new QTableWidgetItem("女"));
            ui->tableWidget->setItem(0, 2, new QTableWidgetItem("22"));
        }

    });
}

Widget::~Widget()
{
    delete ui;
}
