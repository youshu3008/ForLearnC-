#include "test001.h"  // 包含 test001 类的头文件

#include <QApplication>  // 包含 Qt 应用程序类的头文件
#pragma comment(lib, "user32.lib")  // 添加对 user32.lib 库的链接

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // 创建 QApplication 实例

    test001 w;  // 创建 test001 类的对象实例
    w.show();  // 显示 test001 窗口

    return a.exec();  // 运行应用程序的主事件循环
}