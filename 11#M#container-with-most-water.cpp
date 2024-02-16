#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;
// 时间复杂度O(n^2)
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int ans = 0;
//         for (int left = 0; left < height.size(); left++)
//         {
//            for (int right = left; right < height.size(); right++)
//            {
//             int chang = right - left ;
//             ans = max(ans,min(height[left]*chang,height[right]*chang));
//            }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, res = 0;
        while(i < j) {
            res = height[i] < height[j] ? 
                max(res, (j - i) * height[i++]): 
                max(res, (j - i) * height[j--]); 
        }
        return res;  
    }
};


int main() {
     Solution solution;

    // 创建字符串向量
    vector<int> input1 = {1,8,6,2,5,4,8,3,7};
    vector<int> input2 = {1,1};
  
    // 测试示例

    // 输出结果
    cout << solution.maxArea(input1) << endl;
    cout << solution.maxArea(input2) << endl;

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