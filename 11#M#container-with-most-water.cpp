#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {

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
    vector<int> input1 = {1,8,6,2,5,4,8,3,7};
    vector<int> input2 = {1,1};
  
    // 测试示例
    solution.maxArea(input1);
    solution.maxArea(input2);

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
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。

示例 1：


输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
示例 2：

输入：height = [1,1]
输出：1
 

提示：

n == height.length
2 <= n <= 105
0 <= height[i] <= 104

*/