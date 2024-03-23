#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr; // 空链表或只有一个节点的链表一定没有环
        }
        
        ListNode *slow = head; // 慢指针
        ListNode *fast = head; // 快指针
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next; // 慢指针每次移动一步
            fast = fast->next->next; // 快指针每次移动两步
            
            if (slow == fast) { // 当慢指针和快指针相遇时
                ListNode *ptr = head; // 从头节点开始遍历
                
                while (ptr != slow) { // 当慢指针和遍历指针不相遇时
                    ptr = ptr->next; // 遍历指针和慢指针同时向后移动一步
                    slow = slow->next;
                }
                
                return ptr; // 返回环的入口节点
            }
        }
        
        return nullptr; // 链表中不存在环
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

    // 判断链表中是否存在环，并返回环的入口节点
    ListNode *cycleNode = solution.detectCycle(node1);

    // 输出结果
    if (cycleNode != nullptr) {
        std::cout << "链表中存在环，环的入口节点值为：" << cycleNode->val << std::endl;
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
给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。

 

示例 1：



输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：



输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：



输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。
 

提示：

链表中节点的数目范围在范围 [0, 104] 内
-105 <= Node.val <= 105
pos 的值为 -1 或者链表中的一个有效索引
 

进阶：你是否可以使用 O(1) 空间解决此题？
*/