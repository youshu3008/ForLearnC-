#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false; // 空链表或只有一个节点的链表一定没有环
        }
        
        ListNode *slow = head; // 慢指针
        ListNode *fast = head->next; // 快指针
        
        while (slow != fast) { // 当慢指针和快指针不相遇时
            if (fast == nullptr || fast->next == nullptr) {
                return false; // 快指针到达链表尾部，说明没有环
            }
            slow = slow->next; // 慢指针每次移动一步
            fast = fast->next->next; // 快指针每次移动两步
        }
        
        return true; // 慢指针和快指针相遇，说明链表中存在环
    }
};

int main() {
    // 创建链表节点
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);

    // 构建环
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2; // 将链表尾部连接到第二个节点，构成环

    // 创建Solution对象
    Solution solution;

    // 判断链表中是否存在环
    bool hasCycle = solution.hasCycle(node1);

    // 输出结果
    if (hasCycle) {
        std::cout << "链表中存在环" << std::endl;
    } else {
        std::cout << "链表中不存在环" << std::endl;
    }

    // 释放链表节点的内存
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}

/*
给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

如果链表中存在环 ，则返回 true 。 否则，返回 false 。

 

示例 1：



输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：



输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：



输入：head = [1], pos = -1
输出：false
解释：链表中没有环。
 

提示：

链表中节点的数目范围是 [0, 104]
-105 <= Node.val <= 105
pos 为 -1 或者链表中的一个 有效索引 。
 

进阶：你能用 O(1)（即，常量）内存解决此问题吗？
*/