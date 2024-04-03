#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 二叉树节点的定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        for(int i = 0; i < inorder.size(); i++)
            dic[inorder[i]] = i;
        return recur(0, 0, inorder.size() - 1);
    }
private:
    vector<int> preorder;
    unordered_map<int, int> dic;
    TreeNode* recur(int root, int left, int right) { 
        // root:当前递归的子树在先序遍历根节点的索引位置 left:中序遍历子树左边界 right:中序遍历子树右边界
        if (left > right) return nullptr;                        // 递归终止
        TreeNode* node = new TreeNode(preorder[root]);          // 建立根节点
        int i = dic[preorder[root]];                            // 根据前序遍历得到的节点 寻找对应在中序遍历中的位置；划分根节点、左子树、右子树
        node->left = recur(root + 1, left, i - 1);              // 开启左子树递归
        node->right = recur(root + i - left + 1, i + 1, right); // 开启右子树递归
        return node;                                            // 回溯返回根节点
    }
};


// 辅助函数，输出二叉树的前序遍历结果
void preorderTraversal(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    Solution sol;
    // 示例测试用例
    vector<int> preorder1 = {3, 9, 20, 15, 7};
    vector<int> inorder1 = {9, 3, 15, 20, 7};
    TreeNode* root1 = sol.buildTree(preorder1, inorder1);
    cout << "示例测试用例1的前序遍历结果: ";
    preorderTraversal(root1);
    cout << endl;

    vector<int> preorder2 = {-1};
    vector<int> inorder2 = {-1};
    TreeNode* root2 = sol.buildTree(preorder2, inorder2);
    cout << "示例测试用例2的前序遍历结果: ";
    preorderTraversal(root2);
    cout << endl;

    return 0;
}
