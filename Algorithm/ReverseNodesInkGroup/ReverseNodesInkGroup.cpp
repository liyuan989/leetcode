/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

#include <stdio.h>

// Definition for singly-linked list.
struct ListNode
{
    int        val;
    ListNode*  next;

    ListNode(int x)
        : val(x), next(NULL)
    {
    }
};


class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (head == NULL || k <= 1)
        {
            return head;
        }
        int length = 0;
        for (ListNode* p = head; p; p = p->next)
        {
            ++length;
        }
        ListNode pre_head(0);
        pre_head.next = head;
        ListNode* pre = &pre_head;
        while (length >= k)
        {
            ListNode* current = pre->next;
            ListNode* next = current->next;
            for (int i = 0; i < k - 1; ++i)
            {
                current->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = current->next;
            }
            pre = current;
            length -= k;
        }
        return pre_head.next;
    }

    // This solution is slower.
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode pre_head(0);
        pre_head.next = head;
        ListNode* prev = &pre_head;
        while (prev && prev->next)
        {
            int step = 0;
            ListNode* p = prev;
            while (step < k && p && p->next)
            {
                p = p->next;
                ++step;
            }
            if (step < k)
            {
                break;
            }
            ListNode* back = p->next;
            ListNode* prev_tmp = prev;
            prev = prev->next;
            prev_tmp->next = p;
            ListNode* p_start = prev->next;
            prev->next = back;
            ListNode* p_start_prev = prev;
            while (p_start && p_start != back)
            {
                ListNode* tmp_next = p_start->next;
                p_start->next = p_start_prev;
                p_start_prev = p_start;
                p_start = tmp_next;
            }
        }
        return pre_head.next;
    }
};
