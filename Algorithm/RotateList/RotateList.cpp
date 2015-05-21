/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head == NULL || k <= 0)
        {
            return head;
        }
        int length = 0;
        for (ListNode* p = head; p; p = p->next)
        {
            ++length;
        }
        k = k % length;
        if (k == 0)
        {
            return head;
        }
        ListNode pre_node(0);
        pre_node.next = head;
        ListNode* last = &pre_node;
        ListNode* prev = &pre_node;
        for (int i = 0; i < k; ++i)
        {
            last = last->next;
        }
        while (last->next)
        {
            last = last->next;
            prev = prev->next;
        }

        ListNode* result = prev->next;
        if (prev->next != head)
        {
            prev->next = NULL;
            last->next = head;
        }
        return result;
    }
};
