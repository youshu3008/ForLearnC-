#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <deque>
#include <unordered_set>

using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0 || k == 0) return {};
        deque<int> deque; // {1,3,-1,-3,5,3,6,7}
        vector<int> res(nums.size() - k + 1);
        for(int j = 0, i = 1 - k; j < nums.size(); i++, j++) {
            // 删除 deque 中对应的 nums[i-1] (保证队列队头在窗口内)
            if(i > 0 && deque.front() == nums[i - 1])
                deque.pop_front();
            // 保持 deque 递减
            while(!deque.empty() && deque.back() < nums[j])
                deque.pop_back();
            deque.push_back(nums[j]);
            // 记录窗口最大值
            if(i >= 0)
                res[i] = deque.front();
        }
        return res;
    }
};




int main() {
     Solution solution;

    // 创建字符串向量
    vector<int> input1 = {1,7,6,5,4,3,2,1};
    int k1 = 3;
    
    // 测试示例
    vector<int> output1 = solution.maxSlidingWindow(input1,k1);
   

    // 输出结果
    for (int num : output1) {
        cout << num << " ";
    }
    cout << endl;


    system("pause");
    return 0;
}


/*
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。

 

示例 1：

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
示例 2：

输入：nums = [1], k = 1
输出：[1]
 

提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length

*/