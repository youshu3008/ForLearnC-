#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    
    void dfs(vector<int>& nums, int startIndex) {
        if (path.size() >= 2) {
            result.push_back(path);
        }
        // 用于记录当前递归层中已经选择过的元素，避免重复选择相同的元素
        vector<int> used(201, 0);
        for (int i = startIndex; i < nums.size(); i++) {
            // 当前元素已经被选择过，跳过
            if (!path.empty() && nums[i] < path.back()) {
                continue;
            }
            // 当前元素在本层中已经被选择过，跳过
            if (used[nums[i] + 100] == 1) {
                continue;
            }
            // 选择当前元素
            path.push_back(nums[i]);
            used[nums[i] + 100] = 1;
            // 进入下一层递归
            dfs(nums, i + 1);
            // 回溯
            path.pop_back();
        }
    }
    
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {6, 7, 7};
    vector<vector<int>> result = sol.findSubsequences(nums);

    cout << "All possible increasing subsequences are: " << endl;
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << "[";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if (j < result[i].size() - 1) {
                cout << ",";
            }
        }
        cout << "]";
        if (i < result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}
