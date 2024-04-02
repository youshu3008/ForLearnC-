#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = sortedArrayToBST(nums, left, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, right);
        
        return root;
    }
};

// Utility function to print the tree (inorder traversal)
// 前序遍历 
void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << " NULL" << " ";
        return;
    }
    
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()){
        int len = que.size();
        while (len--){
            TreeNode* curr = que.front();que.pop();
            if (curr != nullptr) {
                cout << curr->val << " ";
                que.push(curr->left);
                que.push(curr->right);
            } else {
                cout << " NULL ";
            }
        }
    }
}


int main() {
    Solution sol;
    vector<int> nums1 = {-10, -3, 0, 5, 9};
    TreeNode* root1 = sol.sortedArrayToBST(nums1);
    cout << "BST from nums1: ";
    printTree(root1);
    cout << endl;
    
    vector<int> nums2 = {1, 3};
    TreeNode* root2 = sol.sortedArrayToBST(nums2);
    cout << "BST from nums2: ";
    printTree(root2);
    cout << endl;
    
    return 0;
}
