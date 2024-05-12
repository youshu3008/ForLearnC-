#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking (vector<int>& nums, vector<bool>& used) {
        // 此时说明找到了一组
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue; // path里已经收录的元素，直接跳过
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> result; // 存储最终结果的二维向量
//         dfs(nums, 0, result); // 调用深度优先搜索函数
//         return result; // 返回结果
//     }

// private:
//     void dfs(vector<int>& nums, int start, vector<vector<int>>& result) {
//         if (start == nums.size()) { // 如果已经遍历完所有元素
//             result.push_back(nums); // 将当前排列加入结果中
//             return; // 返回上一层递归
//         }

//         for (int i = start; i < nums.size(); ++i) { // 遍历当前位置之后的所有元素
//             swap(nums[start], nums[i]); // 将当前位置的元素与后面的元素进行交换
//             dfs(nums, start + 1, result); // 递归进入下一层，开始固定下一个位置
//             swap(nums[start], nums[i]); // 恢复数组，进行回溯，以便进行下一次交换
//         }
//     }
// };

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         // 使用next_permutation函数生成所有可能的排列
//         vector<vector<int>> result;
//         sort(nums.begin(), nums.end());
//         do {
//             result.push_back(nums);
//         } while (next_permutation(nums.begin(), nums.end()));
//         return result;
//     }
// };

int main() {
    // 输入数据
    vector<int> nums = {1, 2, 3};

    // 创建解决方案对象
    Solution solution;

    // 调用函数计算全排列
    vector<vector<int>> result = solution.permute(nums);

    // 输出结果
    cout << "All permutations:" << endl;
    for (const auto& permutation : result) {
        cout << "[";
        for (int i = 0; i < permutation.size(); ++i) {
            cout << permutation[i];
            if (i != permutation.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
