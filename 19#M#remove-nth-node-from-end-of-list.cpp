#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0); // 创建虚拟头节点
        dummy->next = head; // 将虚拟头节点连接到原始链表头部
        ListNode *fast = dummy, *slow = dummy; // 初始化快慢指针

        // 将快指针向前移动 n+1 步
        for (int i = 0; i < n + 1; ++i) {
            fast = fast->next;
        }

        // 同时移动快慢指针，直到快指针到达链表末尾
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // 删除倒数第 n 个节点
        slow->next = slow->next->next;

        return dummy->next; // 返回头节点
    }
};

// 测试函数
void test() {
    Solution solution;
    
    // 创建链表：1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // 删除倒数第 2 个节点
    int n = 2;
    ListNode *newHead = solution.removeNthFromEnd(head, n);

    // 输出删除节点后的链表
    while (newHead != nullptr) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;
}

int main() {
    test();
    return 0;
}
/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

 

示例 1：


输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1,2], n = 1
输出：[1]
 

提示：

链表中结点的数目为 sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/