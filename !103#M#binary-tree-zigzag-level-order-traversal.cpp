#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root) q.push(root);
        bool rev = false;
        while (q.size()) {
            int sz = q.size();
            vector<int> tmp;
            while (sz--) {
                auto cur = q.front(); q.pop();
                tmp.push_back(cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            if (rev) ranges::reverse(tmp);
            ans.push_back(tmp);
            rev ^= 1;
        }
        return ans;
    }
};


int main() {
     Solution solution;

    // 创建字符串向量
    vector<int> input1 = {3,9,20,null,null,15,7};
    vector<int> input2 = {1};
    vector<int> input3 = {};

    // 测试示例
    vector<vector<int>> output1 = solution.zigzagLevelOrder(input1);
    vector<vector<int>> output2 = solution.zigzagLevelOrder(input2);
    vector<vector<int>> output3 = solution.zigzagLevelOrder(input3);

    // 输出结果
    cout << "[";
    for (const auto& group : output1) {
        cout << "[";
        for (const auto& str : group) {
            cout << "\"" << str << "\",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    cout << "[";
    for (const auto& group : output2) {
        cout << "[";
        for (const auto& str : group) {
            cout << "\"" << str << "\",";
        }
        cout << "],";
    }
    cout << "]" << endl;

    cout << "[";
    for (const auto& group : output3) {
        cout << "[";
        for (const auto& str : group) {
            cout << "\"" << str << "\",";
        }
        cout << "],";
    }
    cout << "]" << endl;
    system("pause");
    return 0;
}


/*
https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/
给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。
（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

示例 1：

输入：root = [3,9,20,null,null,15,7]
输出：[[3],[20,9],[15,7]]
示例 2：

输入：root = [1]
输出：[[1]]
示例 3：

输入：root = []
输出：[]
 

提示：

树中节点数目在范围 [0, 2000] 内
-100 <= Node.val <= 100
*/