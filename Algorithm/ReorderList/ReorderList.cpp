/*
 Given a singly linked list L: L0?L1?…?Ln-1?Ln,
 reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…

 You must do this in-place without altering the nodes' values.
 
 For example,
 Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        int len = 0;
        for (ListNode* l = head; l; l = l->next) {
            ++len;
        }
        int mid = (len + 1) / 2 ;
        ListNode* separate = head;
        for (int i = 0; i < mid - 1; ++i) {
            separate = separate->next;
        }
        ListNode* l = separate->next;
        separate->next = NULL;
        ListNode* start = NULL;
        while (l) {
            ListNode* tmp = l->next;
            l->next = start;
            start = l;
            l = tmp;
        }
        while (head && start) {
            ListNode* tmp1 = head->next;
            ListNode* tmp2 = start->next;
            head->next = start;
            start->next = tmp1;
            head = tmp1;
            start = tmp2;
        }
    }
};
