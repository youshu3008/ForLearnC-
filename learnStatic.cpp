#include <iostream>
using namespace std;
 
class MyClass {
public:
  // 普通成员函数可以访问 static 和 non-static 成员属性
  void changeParam1(int param) {
    mParam = param;
    sNum = param;
  }
  // 静态成员变量和函数只能访问 static 成员属性
  static int sNum;
  static void changeParam2(int param) {
    sNum = param;
  }
private:
  int mParam;
};
 
// 定义静态成员变量
int MyClass::sNum = 0;
 
int main() {
  // 通过类名来访问静态成员变量和函数
  MyClass::sNum = 10; // 修改静态成员变量
  MyClass::changeParam2(20); // 调用静态成员函数
  cout << MyClass::sNum << endl; // 20
 
  // 创建对象来访问非静态成员
  MyClass obj;
  obj.changeParam1(30); // 修改非静态成员变量
  cout << obj.sNum << endl; // 30
  return 0;
}