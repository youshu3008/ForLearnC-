#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> nodes;
        preorderTraversal(root, nodes);
        for (int i = 1; i < nodes.size(); ++i) {
            nodes[i - 1]->left = nullptr;
            nodes[i - 1]->right = nodes[i];
        }
    }
    
    void preorderTraversal(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        nodes.push_back(root);
        preorderTraversal(root->left, nodes);
        preorderTraversal(root->right, nodes);
    }
};

// Helper function to print flattened tree
void printFlattenedTree(TreeNode* root) {
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    // Test case 1
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->right = new TreeNode(6);

    Solution sol;
    sol.flatten(root1);
    cout << "Flattened tree for test case 1: ";
    printFlattenedTree(root1);

    // Test case 2
    TreeNode* root2 = nullptr;
    sol.flatten(root2);
    cout << "Flattened tree for test case 2: ";
    printFlattenedTree(root2);

    // Test case 3
    TreeNode* root3 = new TreeNode(0);
    sol.flatten(root3);
    cout << "Flattened tree for test case 3: ";
    printFlattenedTree(root3);

    return 0;
}
/*
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。
 

示例 1：


输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [0]
输出：[0]
 

提示：

树中结点数在范围 [0, 2000] 内
-100 <= Node.val <= 100
 

进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？
*/