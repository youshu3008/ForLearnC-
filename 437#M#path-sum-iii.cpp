#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
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
    long long res = 0;
    void dfs(TreeNode* node, long long sum){
        if(!node) return;
        if(node->val == sum) res++;
        dfs(node->left, sum - node->val);
        dfs(node->right, sum - node->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root){
            dfs(root, targetSum);
            pathSum(root->left,targetSum);
            pathSum(root->right, targetSum);
        }
        return res;
    }
};

// 从输入数组构建二叉树
TreeNode* buildTree(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (arr[i] != -1) {
            node->left = new TreeNode(arr[i]);
            q.push(node->left);
        }
        i++;
        if (i < arr.size() && arr[i] != -1) {
            node->right = new TreeNode(arr[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

// 输出二叉树结构
void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "NULL" << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            TreeNode* curr = q.front();
            q.pop();
            if (curr == nullptr) {
                cout << "NULL ";
                continue;
            }
            cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        }
        cout << endl;
    }
}

int main() {
    vector<int> arr1 = {10, 5, -3, 3, 2, -1, 11, 3, -2, -1, 1};
    TreeNode* root1 = buildTree(arr1);
    int targetSum1 = 8;
    
    vector<int> arr2 = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1};
    TreeNode* root2 = buildTree(arr2);
    int targetSum2 = 22;

    Solution solution;
    cout << "示例1的输入:" << endl;
    cout << "二叉树为：" << endl;
    printTree(root1);
    cout << "目标和为：" << targetSum1 << endl;
    cout << "路径数目为：" << solution.pathSum(root1, targetSum1) << endl;
    cout << endl;

    cout << "示例2的输入:" << endl;
    cout << "二叉树为：" << endl;
    printTree(root2);
    cout << "目标和为：" << targetSum2 << endl;
    cout << "路径数目为：" << solution.pathSum(root2, targetSum2) << endl;

    return 0;
}

/*
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

 

示例 1：



输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
输出：3
解释：和等于 8 的路径有 3 条，如图所示。
示例 2：

输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
输出：3
 

提示:

二叉树的节点个数的范围是 [0,1000]
-109 <= Node.val <= 109 
-1000 <= targetSum <= 1000 
*/