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
         if (inorder.size() == 0 || preorder.size() == 0) return NULL;
         return help(preorder, inorder);
    }
    TreeNode* help(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        int rootValue = preorder[0];
        TreeNode* root = new TreeNode(rootValue);
        int delimiterIndex = 0;
        for(delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++){
            if(inorder[delimiterIndex] == rootValue) break;
        }
        vector<int> leftinorder(inorder.begin(),inorder.begin() + delimiterIndex);
        vector<int> rightinorder(inorder.begin() + delimiterIndex + 1, inorder.end());

        vector<int> leftpreorder(preorder.begin() + 1,preorder.begin() + 1 + leftinorder.size());
        vector<int> rightpreorder(preorder.begin() + 1 + leftinorder.size(), preorder.end());
        root->left = help(leftpreorder,leftinorder);
        root->right = help(rightpreorder,rightinorder);
        return root;
    }


    // 后序和中序遍历
    TreeNode* traversal (vector<int>& inorder, vector<int>& postorder) {
    // 第一步
    if (postorder.size() == 0) return NULL;

    // 第二步：后序遍历数组最后一个元素，就是当前的中间节点
    int rootValue = postorder[postorder.size() - 1];
    TreeNode* root = new TreeNode(rootValue);

    // 叶子节点
    if (postorder.size() == 1) return root;

    // 第三步：找切割点
    int delimiterIndex;
    for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++) {
        if (inorder[delimiterIndex] == rootValue) break;
    }

    // 第四步：切割中序数组，得到 中序左数组和中序右数组
    // 左闭右开区间：[0, delimiterIndex)
    vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
    // 第五步：切割后序数组，得到 后序左数组和后序右数组
    // [delimiterIndex + 1, end)
    vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end() );

    // postorder 舍弃末尾元素，因为这个元素就是中间节点，已经用过了
    postorder.resize(postorder.size() - 1);

    // 左闭右开，注意这里使用了左中序数组大小作为切割点：[0, leftInorder.size)
    vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
    // [leftInorder.size(), end)
    vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

    // 第六步
    root->left = traversal(leftInorder, leftPostorder);
    root->right = traversal(rightInorder, rightPostorder);

    return root;
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




