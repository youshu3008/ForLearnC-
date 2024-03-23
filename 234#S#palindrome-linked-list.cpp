#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // if(head->next->next == nullptr) return false;
        vector<int> nums;
        ListNode* pre = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            nums.push_back(curr->val);
            ListNode* tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }
        // reverse(nums.begin(),nums.end());
        for(int num : nums){
            if(pre != nullptr && num == pre->val ){
                pre = pre->next;
            }else{return false;}
        }
        return true;
        
        
    }
};




int main() {
     Solution solution;
     ListNode* intervals = new ListNode(1,new ListNode(2, new ListNode(2, new ListNode(1))));
     bool output = solution.isPalindrome(intervals);
    if(output == 0){
        cout << "false" << endl;
    }else{cout << "true" << endl;}

    return 0;
}


/*
给你一个单链表的头节点 head ，请你判断该链表是否为
回文链表
。如果是，返回 true ；否则，返回 false 。

 

示例 1：


输入：head = [1,2,2,1]
输出：true
示例 2：


输入：head = [1,2]
输出：false
 

提示：

链表中节点数目在范围[1, 105] 内
0 <= Node.val <= 9
 

进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？


*/