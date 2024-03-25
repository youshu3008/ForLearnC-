#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* cur = dummy;
        while(cur->next && cur->next->next){
            ListNode* tmp1 = cur->next, *tmp2 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = tmp1;
            tmp1->next = tmp2;
            cur = cur->next->next;
        }

        return dummy->next;
    }
};

// 打印链表
void printList(ListNode *head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// 测试函数
void test() {
    Solution solution;
    
    // 创建链表：1 -> 2 -> 3 -> 4
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "原始链表：";
    printList(head);

    // 交换相邻节点
    ListNode *newHead = solution.swapPairs(head);

    cout << "交换后链表：";
    printList(newHead);
}

int main() {
    test();
    return 0;
}
/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

 

示例 1：


输入：head = [1,2,3,4]
输出：[2,1,4,3]
示例 2：

输入：head = []
输出：[]
示例 3：

输入：head = [1]
输出：[1]
 

提示：

链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100

*/