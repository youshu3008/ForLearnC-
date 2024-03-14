#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <deque>
#include <unordered_set>
// 单调队列
using namespace std;
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         cout << k << endl;
//         k = k % nums.size();
//         reverse(nums, 0, nums.size() - 1);
//         reverse(nums, 0, k - 1);
//         reverse(nums, k, nums.size() - 1);
//     }

//     void reverse(vector<int>& nums, int a, int b) {
//         while (a < b) {
//             int tmp = nums[a];
//             nums[a] = nums[b];
//             nums[b] = tmp;
//             a++;
//             b--;
//         }
//     }
// };

class Solution 
{
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        k = k % n;
        std::reverse(nums.begin(),nums.end());
        std::reverse(nums.begin()+k,nums.end());
        std::reverse(nums.begin(),nums.begin()+k);
        
        return;
    }
};





int main() {
     Solution solution;

    // 创建字符串向量
    vector<int> input1 = {1,2,3,4,5,6,7};
    int k1 = 3;
    // 7 6 5 4 3 2 1 
    // 5 6 7 1 2 3 4
    // 5 6 7 4 3 2 1

    // 测试示例
    solution.rotate(input1,k1);
   

    // 输出结果
    for (int num : input1) {
        cout << num << " ";
    }
    cout << endl;


    system("pause");
    return 0;
}


/*
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

 

示例 1:
轮转数组

输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入：nums = [-1,-100,3,99], k = 2
输出：[3,99,-1,-100]
解释: 
向右轮转 1 步: [99,-1,-100,3]
向右轮转 2 步: [3,99,-1,-100]
 

提示：

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

进阶：

尽可能想出更多的解决方案，至少有 三种 不同的方法可以解决这个问题。
你可以使用空间复杂度为 O(1) 的 原地 算法解决这个问题吗？

*/