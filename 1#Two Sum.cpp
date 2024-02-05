#include <iostream>
using namespace std;

struct Result {
    int first;
    int second;
};

Result twoSum(int nums[], int target) {
    Result result = {-1, -1};  // 初始化结构体

    int len = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (nums[i] + nums[j] == target) {
                result.first = i;
                result.second = j;
                return result;
            }
        }
    }

    return result;  // 返回结构体
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;

    Result result = twoSum(nums, target);

    if (result.first != -1 && result.second != -1) {
        cout << "[" << result.first << ", " << result.second << "]" << endl;
    } else {
        cout << "No matching values were found." << endl;
    }
    system("pause");
    return 0;
    
}
