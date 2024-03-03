#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> prefixSumCount;

        // 以前缀总和 0 初始化
        prefixSumCount[0] = 1;

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            // 检查是否存在总和等于 k 的子数组
            if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
                count += prefixSumCount[sum - k];
            }

            // 更新前缀总数
            prefixSumCount[sum]++;
        }

        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3};
    int k1 = 3;
    int ans = solution.subarraySum(nums1, k1);

    cout << "Number of subarrays with sum " << k1 << ": " << ans << endl;
    system("pause");
    return 0;
}

/*
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。

子数组是数组中元素的连续非空序列。

 

示例 1：

输入：nums = [1,1,1], k = 2
输出：2
示例 2：

输入：nums = [1,2,3], k = 3
输出：2
 

提示：

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107

*/