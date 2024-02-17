#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

/*
TreeNode 结构体表示二叉树的节点，包含三个成员变量：
int val 表示节点的值。
TreeNode *left 表示左子节点的指针。
TreeNode *right 表示右子节点的指针。
构造函数用于初始化节点，提供了三种不同的构造方式：
TreeNode()：默认构造函数，将节点的值初始化为 0，左右子节点指针初始化为 nullptr。
TreeNode(int x)：带一个参数的构造函数，用于初始化节点的值为 x，左右子节点指针初始化为 nullptr。
TreeNode(int x, TreeNode *left, TreeNode *right)：带三个参数的构造函数，
用于初始化节点的值为 x，左子节点指针为 left，右子节点指针为 right。
*/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 定义结果数组
        vector<vector<int>> ans;
        // 如果根节点为空，则直接返回
        if (!root) return ans;
        // 定义一个队列
        queue<TreeNode*> q;
        // 把根节点添加到队列
        q.push(root);
        // 当队列非空的时候进行循环
        while (!q.empty())
        {   
            // 获取当前队列的节点数量
            int cnt = q.size();
            // 定义存储当前层全部节点的数组
            vector<int> cur;
            // 进行cnt次的pop操作
            while (cnt--)
            {
                // 弹出的节点加入到数组中
                TreeNode* node = q.front(); q.pop();
                cur.push_back(node->val);
                // 弹出的节点的左右孩子加入到队列
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                
            }
            // 当前层遍历结束 加入到结果
            ans.push_back(cur);
        }
        return ans;
    }
};


int main() {
     Solution solution;
//    3
//   / \
//  9  20
//    /  \
//   15   7

    // 创建字符串向量 root = [3,9,20,null,null,15,7]
    TreeNode* input1 = new TreeNode(
        3,new TreeNode(9),new TreeNode(20, new TreeNode(15), new TreeNode(7)));  // [[3],[9,20],[15,7]]
    TreeNode* input2 = new TreeNode(1);
    TreeNode* input3 = nullptr;

    // 测试示例
    vector<vector<int>> output1 = solution.levelOrder(input1);
    vector<vector<int>> output2 = solution.levelOrder(input2);
    vector<vector<int>> output3 = solution.levelOrder(input3);

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
https://leetcode.cn/problems/binary-tree-level-order-traversal/description/?envType=daily-question&envId=2024-02-17
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

 

示例 1：


输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]
示例 2：

输入：root = [1]
输出：[[1]]
示例 3：

输入：root = []
输出：[]
 

提示：

树中节点数目在范围 [0, 2000] 内
-1000 <= Node.val <= 1000
*/