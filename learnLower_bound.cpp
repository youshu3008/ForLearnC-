#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main()
{
	vector<int> v = { 3,4,1,2,8 };
	// 先排序
	sort(v.begin(), v.end());  // 1 2 3 4 8
 
	// 定义两个迭代器变量
	vector<int>::iterator iter1;
	vector<int>::iterator iter2;
 
	// 在动态数组中寻找 >=3 出现的第一个数 并以迭代器的形式返回
	iter1 = lower_bound(v.begin(), v.end(), 3);  // -- 指向3
	// 在动态数组中寻找 >=7 出现的第一个数 并以迭代器的形式返回
	iter2 = lower_bound(v.begin(), v.end(), 7);  // -- 指向8
 
	cout << distance(v.begin(), iter1) << endl; //下标 2
	cout << distance(v.begin(), iter2) << endl; //下标 4 

    int *p = NULL;
	long long n = 1000000;
	p = (int *)malloc(sizeof(long long)*n);
    cout << "p  " << p << endl;
    cout << "*p  " << *p << endl;
    int* p22 = new(int);
    *p22 = 5;
    cout << "*p22  " << *p22 << endl;
    cout << "p22  " << p22 << endl;
    free(p);
    delete(p22);
	return 0;
}