#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


// 时间复杂度O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size(), ans = 0;
        if (len < 2) return ans;
        int l = 0, r = len - 1, lmax = 0, rmax = 0;
        while (l < r)
        {
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if (lmax < rmax) {
                ans += lmax - height[l];
                l++;
            } else {
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};

// 时间复杂度O(n^2)
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int len = height.size(), ans = 0 , water = 0;
//         vector<int> lmax(len, 0), rmax(len, 0);
//         if (len < 2) return ans;
//         for (int i = 0; i < len; i++)
//         {
//             for (int j = 0; j < i; j++)
//             {
//                 lmax[i] = max(lmax[i],height[j]);
//             }
//             for (int k = len; k > i; k--)
//             {
//                 rmax[i] = max(rmax[i],height[k]);
//             }
//             water = max(min(lmax[i], rmax[i]) - height[i], 0);
//             ans += water;
//         }
//         return ans;  
//     }
// };

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int len = height.size();
//         int ans = 0, water = 0;
//         if (len < 2) return ans;
//         vector<int> lmax(len, 0);
//         vector<int> rmax(len, 0);
//         // 计算每个位置的左侧最高柱
//         lmax[0] = height[0];
//         for (int i = 1; i < len; i++) {
//             lmax[i] = max(lmax[i - 1], height[i]);
//         }
//         // 计算每个位置的右侧最高柱
//         rmax[len - 1] = height[len - 1];
//         for (int i = len - 2; i >= 0; i--) {
//             rmax[i] = max(rmax[i + 1], height[i]);
//         }
//         // 计算每个位置能容纳的雨水量并累加到答案中
//         for (int i = 0; i < len; i++) {
//             water = min(lmax[i], rmax[i]) - height[i];
//             ans += water;
//         }
//         return ans;
//     }
// };

int main() {
     Solution solution;
    /*
    输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
    输出：6
    解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
    示例 2：

    输入：height = [4,2,0,3,2,5]
    输出：9
    */
    // 创建字符串向量
    vector<int> input1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> input2 = {4,2,0,3,2,5};
    vector<int> input3 = {2,1,0,2};

    // 测试示例
    cout <<  "1:       " << solution.trap(input1) << endl; //  6
    cout <<  "2:       " << solution.trap(input2) << endl; //  9
    cout <<  "3:       " << solution.trap(input3) << endl; //  3

    
    system("pause");
    return 0;
}


/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

示例 1：



输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9
 

提示：

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
*/