#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
    }
};


int main() {
     Solution solution;

    // 创建字符串向量
    vector<int> input1 = {3,9,20,null,null,15,7};
    vector<int> input2 = {1};
    vector<int> input3 = {};

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
https://leetcode.cn/problems/n-ary-tree-level-order-traversal/
给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。

树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。

 

示例 1：



输入：root = [1,null,3,2,4,null,5,6]
输出：[[1],[3,2,4],[5,6]]
示例 2：



输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
 

提示：

树的高度不会超过 1000
树的节点总数在 [0, 10^4] 之间
*/