#include <iostream>

using namespace std;

// 定义链表节点
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode *head = nullptr, *tail = nullptr;
//         int carry = 0;
//         while (l1 || l2) {
//             int n1 = l1 ? l1->val: 0;
//             int n2 = l2 ? l2->val: 0;
//             int sum = n1 + n2 + carry;
//             if (!head) {
//                 head = tail = new ListNode(sum % 10);
//             } else {
//                 tail->next = new ListNode(sum % 10);
//                 tail = tail->next;
//             }
//             carry = sum / 10;
//             if (l1) {
//                 l1 = l1->next;
//             }
//             if (l2) {
//                 l2 = l2->next;
//             }
//         }
//         if (carry > 0) {
//             tail->next = new ListNode(carry);
//         }
//         return head;
//     }
// };

// 链表对应位置相加，通过整除的方式得到进位的值，通过求余的方式得到当前位置的值

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0), *cur = dummy;
        int sum = 0;
        while (l1 || l2 || sum)
        {
            if(l1) sum += l1->val, l1 = l1->next;
            if(l2) sum += l2->val, l2 = l2->next;
            cur->next = new ListNode(sum%10);
            cur = cur->next;
            sum/=10;
        }
        return dummy->next;

    }
};

int main() {
    Solution solution;

    // 创建测试用例
    ListNode* input1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* input2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    // 测试示例
    ListNode* result = solution.addTwoNumbers(input1, input2);

    // 输出结果
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    // 释放动态分配的内存
    delete input1;
    delete input2;
    system("pause");
    return 0;
}

/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储一位数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例 1：


输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
示例 2：

输入：l1 = [0], l2 = [0]
输出：[0]
示例 3：

输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
 

提示：

每个链表中的节点数在范围 [1, 100] 内
0 <= Node.val <= 9
题目数据保证列表表示的数字不含前导零
*/