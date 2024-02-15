#include<iostream>
#include<unordered_map>
#include<map>
#include<string>
using namespace std;

int main()
{
    // 注意：c++11才开始支持括号初始化
    unordered_map<int, string> myMap = {{5, "zhangsan"},{6, "lisi"}};  // 使用{}赋值
    myMap[2] = "wanger";  // 使用[ ] 进行当个插入，若已存在键值2，则赋值修改，若无则插之。
    myMap.insert(pair<int, string>(3, "mazi"));  // 使用insert和pair插入。

    // 遍历输出+迭代器的使用。
    auto iter = myMap.begin();  // auto自动识别为迭代器类型unordered_map<int, string>::iterator
    while(iter != myMap.end())
    {
        cout << iter->first << "," << iter->second << endl;
        ++iter;
    }

    // 查找元素并输出 + 迭代器的使用
    auto iterator = myMap.find(6);  // find()返回一个指向2的迭代器。
    if(iterator != myMap.end())
        cout << endl << iterator->first << "," << iterator->second << endl;
    system("pause");
    return 0;
}
