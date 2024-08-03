#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // 使用unordered_map来存储属性和值
    unordered_map<string, int> attributes;
    string attr;
    
    // 循环读取输入直到结束
    while (cin >> attr) {
        int mainValue, subCount;
        cin >> mainValue >> subCount;
        
        // 更新主属性的值
        attributes[attr] += mainValue;
        
        // 读取并更新子属性的值
        for (int i = 0; i < subCount; ++i) {
            string subAttr;
            int subValue;
            cin >> subAttr >> subValue;
            attributes[subAttr] += subValue;
        }
    }
    
    // 打印输出
    cout << "atk " << attributes["atk"] << endl;
    cout << "atkper " << attributes["atkper"] << endl;
    cout << "def " << attributes["def"] << endl;
    cout << "spd " << attributes["spd"] << endl;
    
    return 0;
}
