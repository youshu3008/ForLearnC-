#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
/*
使用前缀和的方法可以解决这个问题，因为我们需要找到和为k的连续子数组的个数。通过计算前缀和，
我们可以将问题转化为求解两个前缀和之差等于k的情况。

假设数组的前缀和数组为prefixSum，其中prefixSum[i]表示从数组起始位置到第i个位置的元素之和。
那么对于任意的两个下标i和j（i < j），如果prefixSum[j] - prefixSum[i] = k，
即从第i个位置到第j个位置的元素之和等于k，那么说明从第i+1个位置到第j个位置的连续子数组的和为k。

通过遍历数组，计算每个位置的前缀和，并使用一个哈希表来存储每个前缀和出现的次数。在遍历的过程中，
我们检查是否存在prefixSum[j] - k的前缀和，如果存在，说明从某个位置到当前位置的连续子数组的和为k，
我们将对应的次数累加到结果中。

这样，通过遍历一次数组，我们可以统计出和为k的连续子数组的个数，并且时间复杂度为O(n)，其中n为数组的长度。
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;  // 初始化前缀和为0的次数为1

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];  // 计算当前位置的前缀和

            // 查找之前的前缀和中是否有与当前前缀和之差为k的子数组
            if (prefixSumCount.count(sum - k) > 0) {
                count += prefixSumCount[sum - k];  // 更新子数组个数
            }

            prefixSumCount[sum]++;  // 更新前缀和的次数
        }

        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3};
    int k1 = 3;
    int ans = solution.subarraySum(nums1, k1);

    cout << "有总和的子数组数 " << ans << endl;
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