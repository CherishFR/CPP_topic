#include "mywidget.h"
#include <QApplication>


// 程序入口  argc命令行的变量数量  argv命令行变量的数组
int main(int argc, char *argv[])
{
    // 应用程序对象a,在QT中有且仅有一个应用程序对象
    QApplication a(argc, argv);
    // 创建MyWidget对象w，MyWidget基类QWidget
    MyWidget w;
    // 窗口默认不会弹出，如果想弹出调用show()
    w.show();

    // a.exec()进入消息循环机制
    return a.exec();
}
