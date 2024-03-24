#include <iostream>
#include <vector>

using namespace std;

// 单链表的定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0); // 虚拟节点用于简化在头部插入
        ListNode* current = dummy; // 指向合并链表中当前节点的指针
        
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }
        
        // 添加剩余的节点（如果有）
        if(list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }
        
        ListNode* mergedList = dummy->next; // 合并后链表的头
        delete dummy; // 释放虚拟节点的内存
        
        return mergedList;
    }
};


// 从数值矢量创建链表的函数
ListNode* createLinkedList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : values) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

// 打印链表的函数
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // 使用示例
    vector<int> values1 = {1,2,4};
    ListNode* list1 = createLinkedList(values1);

    vector<int> values = {1,3,4};
    ListNode* list2 = createLinkedList(values);
    
    // cout << "Original List: ";
    // printLinkedList(list1);
    // printLinkedList(list2);
    
    Solution solution;
    ListNode* reversedList = solution.mergeTwoLists(list1,list2);
    
    
    
    cout << "Last List: ";
    printLinkedList(reversedList);
    
    return 0;
}
/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例 1：


输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]
 

提示：

两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列
请问您在哪类招聘中遇到此题？
1/5
社招
校招
实习
未遇到
通过次数
1.6M
提交次数
2.5M
通过率
66.4%
*/