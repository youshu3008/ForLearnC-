#include <iostream>

using namespace std;
// 类
// class A
// {
// private:
//     const int a;                // 常对象成员，只能在初始化列表赋值

// public:
//     // 构造函数
//     A() : a(0) { };
//     A(int x) : a(x) { };        // 初始化列表

//     // const可用于对重载函数的区分
//     int getValue();             // 普通成员函数
//     int getValue() const;       // 常成员函数，不得修改类中的任何数据成员的值
// };


// void function()
// {
//     // 对象
//     A b;                        // 普通对象，可以调用全部成员函数、更新常成员变量
//     const A a;                  // 常对象，只能调用常成员函数
//     const A *p = &a;            // 指针变量，指向常对象
//     const A &q = a;             // 指向常对象的引用

//     // 指针
//     char greeting[] = "Hello";
//     char* p1 = greeting;                // 指针变量，指向字符数组变量
//     const char* p2 = greeting;          // 指针变量，指向字符数组常量（const 后面是 char，说明指向的字符（char）不可改变）
//     char* const p3 = greeting;          // 自身是常量的指针，指向字符数组变量（const 后面是 p3，说明 p3 指针自身不可改变）
//     const char* const p4 = greeting;    // 自身是常量的指针，指向字符数组常量
// }

// // 函数
// void function1(const int Var);           // 传递过来的参数在函数内不可变
// void function2(const char* Var);         // 参数指针所指内容为常量
// void function3(char* const Var);         // 参数指针为常量
// void function4(const int& Var);          // 引用参数在函数内为常量

// // 函数返回值
// const int function5();      // 返回一个常数
// const int* function6();     // 返回一个指向常量的指针变量，使用：const int *p = function6();
// int* const function7();     // 返回一个指向变量的常指针，使用：int* const p = function7();
int main(){
    int a = 5;
    int b = 7;
    int c = 8;

    const int* p_a = &a;   // 常量指针，指向一个常量整型，指针的值可以改变
    cout << "*p_a:"  << *p_a << endl;
    int* const p_b = &b;   // 指针常量，指向一个整型，指针的值不能改变
    const int* const p_c = &c; // 常量指针常量，指向一个常量整型，指针的值不能改变
    // p_a = &b; // 合法
    *p_a = 6; // 不合法 error: assignment of read-only location '* p_a'
    cout << "p_a:"  << p_a << endl;
    cout << "*p_a:"  << *p_a << endl;
    // p_b = &a; // 不合法 error: assignment of read-only variable 'p_b'
    cout << "*p_a:"  << p_a << endl;
    cout << "*p_b:"  << p_b << endl;
    cout << "*p_c:"  << p_c << endl;

    // cout << "*p_a: " << *p_a << endl;  // 输出 p_a 所指向的值，即 a 的值 5
    // cout << "*p_b: " << *p_b << endl;  // 输出 p_b 所指向的值，即 b 的值 7
    // cout << "*p_c: " << *p_c << endl;  // 输出 p_c 所指向的值，即 c 的值 8
    // system("pause");
    return 0;
}
