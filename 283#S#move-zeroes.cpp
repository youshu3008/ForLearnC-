#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        while (i < nums.size())
        {
            if (nums[i] != 0)
            {
                nums[j++] = nums[i];
            }
            i++;     
        }
        while (j < nums.size())
        {
            nums[j++] = 0;
        }
        
    }
};

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int nonZeroIndex = 0; // 用于记录非零元素的位置

//         // 将非零元素移到数组前部
//         for (int i = 0; i < nums.size(); ++i) {
//             if (nums[i] != 0) {
//                 nums[nonZeroIndex++] = nums[i];
//             }
//         }
//         // 将剩余位置补零
//         while (nonZeroIndex < nums.size()) {
//             nums[nonZeroIndex++] = 0;
//         }
        
//     }
// };

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int dest = -1,cur = 0;
//         while(cur<nums.size())
//         {
//             if(nums[cur]!=0)
//             {
//                 swap(nums[dest+1],nums[cur]);
//                 ++dest;++cur;
//             }
//             else
//             ++cur;
//         }
//     }
// };


int main() {
     Solution solution;

    // 创建字符串向量
    vector<int> input1 = {0,1,0,3,12};
    vector<int> input2 = {0};
  
    // 测试示例
    solution.moveZeroes(input1);
    solution.moveZeroes(input2);

    // 输出结果
    for (int num : input1) {
        cout << num << " ";
    }
    cout << endl;

    for (int num : input2) {
        cout << num << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}


/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。

 

示例 1:

输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
示例 2:

输入: nums = [0]
输出: [0]
 

提示:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

进阶：你能尽量减少完成的操作次数吗？

*/