#pragma once  // 预处理指令，确保头文件只被编译一次

#include "ui_test001.h"  // 包含 test001 类的 UI 头文件
#include <QMainWindow>  // 包含 QMainWindow 类的头文件

class test001 : public QMainWindow {  // test001 类继承自 QMainWindow 类
    Q_OBJECT  // 宏定义，用于启用 Qt 的元对象系统支持
    
public:
    test001(QWidget* parent = nullptr);  // 构造函数声明，可接受一个 QWidget 指针类型的参数，默认值为 nullptr
    ~test001();  // 析构函数声明

private:
    Ui_test001* ui;  // 指向 Ui_test001 类对象的指针
    QTimer* countdownTimer;  // 指向 QTimer 类对象的指针
    int remainingTime;  // 倒计时剩余时间变量

private slots:  // 槽函数声明
    void handleButtonClicked();  // 处理按钮点击的槽函数声明
    void updateCountdown();  // 更新倒计时的槽函数声明
};