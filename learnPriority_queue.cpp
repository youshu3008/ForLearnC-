#include <iostream>
#include <queue>
using namespace std;

int main()
{
    //1.基本数据类型-int,double...
    priority_queue<int,vector<int>,less<int>> p1;     //默认大根堆<==>priority_queue<int> p1
    p1.push(2); p1.push(1); p1.push(3);     
    cout<< "p1.top(): " << endl;          //输出 3 2 1
    while(p1.empty()== false){
        cout <<p1.top()<< " ";
        p1.pop();
    }
    cout << endl;
    
    priority_queue<int,vector<int>,greater<int>> p2;  //小根堆
    p2.push(2); p2.push(1); p2.push(3);               //输出 1 2 3
    cout <<"p2.top(): " << endl;
    while(p2.empty()== false){
        cout << p2.top()<<" ";
        p2.pop();
    }
    cout << endl;

    //2.基本数据类型-pair-pair类型默认先比较第一个元素，第一个相等比较第二个
    priority_queue<pair<int, int> > a;
    a.push(pair<int,int>{1,2});
    a.push(pair<int,int>{1,3});
    a.push(pair<int,int>{2,5});
    
    while (a.empty()== false){
        cout<< "a.top().first: " <<a.top().first<<" "<< "a.top().second: " << a.top().second<<endl;
        a.pop();
    }
    cout << endl;
    //输出:
    //2 5
    //1 3
    //1 2

    return 0;
}
