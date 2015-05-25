/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        if (head == NULL || m == n)
        {
            return head;
        }
        ListNode pre_head(0);
        pre_head.next = head;
        ListNode* p = &pre_head;
        for (int i = 0; i < m - 1; ++i)
        {
            p = p->next;
        }
        ListNode* prev = p->next;
        ListNode* last = p->next;
        for (int i = 0; i < n - m; ++i)
        {
            last = last->next;
        }
        p->next = last;
        ListNode* last_end = last->next;
        for (ListNode* node = last_end; prev != last_end;)
        {
            ListNode* tmp = prev;
            prev = prev->next;
            tmp->next = node;
            node = tmp;
        }
        return pre_head.next;
    }
};
