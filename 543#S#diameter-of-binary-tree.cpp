#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        max_diameter = 0;
        dfs(root);
        return max_diameter;
    }
    
private:
    int max_diameter;
    
    int dfs(TreeNode* node) {
        if (!node)
            return 0;
        
        int left_height = dfs(node->left); 
        int right_height = dfs(node->right);
        
        max_diameter = max(max_diameter, left_height + right_height);
        
        return max(left_height, right_height) + 1;
    }
};

// 用于构建二叉树的辅助函数
TreeNode* constructTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return nullptr;
    
    TreeNode* root = new TreeNode(arr[i]);
    root->left = constructTree(arr, n, 2 * i + 1);
    root->right = constructTree(arr, n, 2 * i + 2);
    return root;
}

// 释放二叉树的辅助函数
void deleteTree(TreeNode* root) {
    if (!root)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // 输入示例二叉树的数组表示
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {1, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    Solution sol;
    
    // 构建示例二叉树
    TreeNode* root1 = constructTree(arr1, n1, 0);
    TreeNode* root2 = constructTree(arr2, n2, 0);
    
    // 计算直径并输出结果
    cout << "示例 1 的直径为：" << sol.diameterOfBinaryTree(root1) << endl;
    cout << "示例 2 的直径为：" << sol.diameterOfBinaryTree(root2) << endl;
    
    // 释放内存
    deleteTree(root1);
    deleteTree(root2);
    
    return 0;
}
