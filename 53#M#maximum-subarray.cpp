#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//     // -2,1,-3,4,-1,2,1,-5,4
//     int sum = 0, ans = nums[0];
//     if(nums.size() == 1){
//         ans = nums[0];
//     }
//         for(int i = 0; i < nums.size(); ++i){
//             sum = nums[i];
//             int j = i + 1;
//             ans = max(ans,sum);
//             while(j < nums.size())
//             {
//                 sum += nums[j];
//                 j++;
//                 ans = max(ans,sum);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int res = nums[0];
        int sum = 0;
        for (int num : nums) {
            if (sum > 0)
                sum += num;
            else
                sum = num;
            res = max(res, sum);
        }
        return res;
    }
    
};


int main() {
     Solution solution;

    // 创建字符串向量
    vector<int> input1 = {-2,1};
    vector<int> input2 = {-2,1,-3,4,-1,2,1,-5,4};
  
    // 测试示例

    // 输出结果
    cout << solution.maxSubArray(input1) << endl; // 1
    cout << solution.maxSubArray(input2) << endl; // 6

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