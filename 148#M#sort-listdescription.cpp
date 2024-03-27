#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> sortlist;
        while(head){
            sortlist.push_back(head->val);
            head = head->next;
        }
        sort(sortlist.begin(),sortlist.end());
        ListNode* ans = new ListNode(0);
        ListNode* tmp = ans;
        for(int num : sortlist){
            tmp->next = new ListNode(num);
            tmp = tmp->next;
        }
        return ans->next;
    }
};

// Function to create a linked list from an array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; ++i) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

// Function to delete the linked list
void deleteList(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

int main() {
    // Example test case
    int arr[] = {4, 2, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    ListNode* head = createList(arr, n);

    Solution sol;
    ListNode* sortedHead = sol.sortList(head);

    cout << "Sorted linked list: ";
    printList(sortedHead);

    deleteList(sortedHead);

    return 0;
}
