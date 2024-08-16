#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    stringstream ss;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    
    // 将 nums 的内容写入 ss
    for (int num : nums) {
        ss << num;
    }
    string result = ss.str();
    cout << result << " " << nums.size() << " " << nums.capacity()<< endl;
    
    // 调整 nums 的大小
    nums.resize(3);
    
    // 清空 ss
    ss.str("");
    ss.clear();
    
    // 将调整后的 nums 的内容写入 ss
    for (int num : nums) {
        ss << num;
    }
    result = ss.str();
    cout << result << " " << nums.size() << " " << nums.capacity()<< endl;

    return 0;
}
