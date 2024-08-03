#include <iostream>
using namespace std;
 
// int main()
// {
// 	//const volatile int a = 7;
// 	const int a = 7;
// 	int *p = (int *)(&a);
// 	*p = 8;
// 	cout << "a=" << a << endl;
// 	cout << "*p=" << *p << endl;
// 	system("pause");
// 	return 0;
// }

// 全新典中典来了：已知inline不能修饰虚函数。请问以下代码会输出什么，还是报错？为什么
class Base {
public:
    static int flag;
	inline virtual void f()
	{
		cout<<"Base"<<endl;
	}
	int flags = 0;
};
int Base::flag = 0;

class Derived : public Base {
public:
	inline virtual void f()
	{
		cout<<"Derived"<<endl;
	}
};
int main()
{
	Base* p=new Derived;
    cout << Base::flag << endl;
    cout << p->flags << endl;
	p->f();
}
