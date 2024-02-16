#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 时间复杂度O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());  // 将 nums 转换为哈希表，提高查找速度
        int longestStreak = 0;

        for (int num : numSet) {
            // 只考虑连续序列的起始元素，因为后续元素会在其他起始元素的迭代中处理
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // 继续查找连续序列的下一个元素
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};

// 时间复杂度O(nlogn)
// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size() == 0) return 0;
           // 这一步最大时间复杂度O(nlogn)
//         sort(nums.begin(),nums.end()); 
//         int res = 1,len = 1;
//         for(int i = 1;i < nums.size();i++){
//             if(nums[i]==nums[i-1])continue;//去重
//            if(nums[i] == nums[i-1] + 1)len++;
//            else len = 1;
//            res = max(res,len);
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//        sort(nums.begin(),nums.end());
//        int res = 1 ,lianxu = 1;
//        for(int i= 0; i < nums.size(); i++){
//             if(nums[i-1] == nums[i]) continue;
//             if(nums[i-1] == nums[i]-1){
//                 lianxu++;
//             }
//             else{
//                 lianxu = 1;
//             }
//             res = max(res,lianxu);
//        }
//        return res;
//     }
// };

int main() {
     Solution solution;

    // 创建字符串向量
    vector<int> input1 = {100,4,200,1,3,2};
    vector<int> input2 = {0,3,7,2,5,8,4,6,0,1};
  

    // 测试示例
    cout << solution.longestConsecutive(input1) << endl;
    cout << solution.longestConsecutive(input2) << endl;
  
    system("pause");
    return 0;
}


/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

 

示例 1：

输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
示例 2：

输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
 

提示：

0 <= nums.length <= 105
-109 <= nums[i] <= 109

*/