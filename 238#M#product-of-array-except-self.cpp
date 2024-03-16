#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       // 1,2,3,4
       int len = nums.size(),tmp = 1;
       if (len == 0) return {};
       vector<int>prefix(len,1);
       vector<int>suffix(len,1);
       vector<int>answer(len,1);
       for(int i = 1;i < len; ++i){
            prefix[i] = prefix[i - 1] * nums[i - 1];
       }
       for(int i = len - 2; i >= 0; --i){
            suffix[i] = suffix[i + 1] * nums[i + 1];
       }
        for (int i = 0; i < len; i++)
        {
            answer[i]= (prefix[i] * suffix[i]);
        }
        return answer;
    }
};

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> answer;
//         int linshi = 1;
//         for(int i = 0,j = 0;i < nums.size(); ++i,j=0,linshi = 1){
//             int Prefix = 1;
//             while(j < nums.size()){
//                 if(j != i){
//                     linshi *= nums[j++];
//                 }else{
//                     j++;
//                     continue;
//                 }
//             }
//             answer.push_back(linshi);
//         }
//         return answer;
//     }
// };


/*
1 2 3 4 
1 1 1 1
*/

int main() {
     Solution solution;

    // 创建字符串向量
    vector<int> input1 = {1,2,3,4};
    vector<int> input2 = {-1,1,0,-3,3};
  
    // 测试示例
    vector<int> output1 = solution.productExceptSelf(input1);
    vector<int> output2 = solution.productExceptSelf(input2);

    // 输出结果
    for (int num : output1) {
        cout << num << " ";
    }
    cout << endl;

    for (int num : output2) {
        cout << num << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}


/*
除自身以外数组的乘积

给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请 不要使用除法，且在 O(n) 时间复杂度内完成此题。

 

示例 1:

输入: nums = [1,2,3,4]
输出: [24,12,8,6]
示例 2:

输入: nums = [-1,1,0,-3,3]
输出: [0,0,9,0,0]
 

提示：

2 <= nums.length <= 105
-30 <= nums[i] <= 30
保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内
 

进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？
（ 出于对空间复杂度分析的目的，输出数组 不被视为 额外空间。）

*/