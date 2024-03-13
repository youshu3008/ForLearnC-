#include "test001.h"  // 包含 test001 类的头文件
#include "ui_test001.h"  // 包含 test001 类的 UI 头文件
#include <QMessageBox>  // 包含 QMessageBox 类的头文件
#include <QTimer>  // 包含 QTimer 类的头文件

test001::test001(QWidget* parent)
    : QMainWindow(parent), ui(new Ui_test001)  // 在堆上创建一个 Ui_test001 对象实例并赋值给 ui 指针
{
    ui->setupUi(this);  // 设置当前窗口的 UI

    countdownTimer = new QTimer(this);  // 在堆上创建一个 QTimer 对象实例并赋值给 countdownTimer 指针
    connect(countdownTimer, &QTimer::timeout, this, &test001::updateCountdown);  // 连接计时器的 timeout 信号和 updateCountdown 槽函数
    connect(ui->pushButton1, &QPushButton::clicked, this, &test001::handleButtonClicked);  // 连接按钮的 clicked 信号和 handleButtonClicked 槽函数
}

void test001::handleButtonClicked()
{
    remainingTime = 10;  // 设置初始倒计时时间为10秒
    countdownTimer->start(1000);  // 每隔1秒触发一次计时器的 timeout 信号
}

void test001::updateCountdown()
{
    remainingTime--;  // 倒计时时间减一
    if (remainingTime >= 0) {
        ui->countdownLabel->setText("倒计时：" + QString::number(remainingTime) + "秒");  // 更新倒计时标签的文本
    } else {
        countdownTimer->stop();  // 停止计时器
        QMessageBox::information(this, "提醒", "时间到");  // 弹出消息框显示时间到达的信息
    }
}

test001::~test001()
{
    delete ui;  // 释放堆上分配的 ui 对象
}