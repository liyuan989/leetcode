/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode pre_head(0);
        ListNode* prev = &pre_head;
        ListNode* last = head;
        while (last->next)
        {
            if (last->val != last->next->val)
            {
                prev->next = last;
                last = last->next;
                prev = prev->next;
            }
            else
            {
                last = last->next;
            }
        }
        if (prev == &pre_head || last->val != prev->val)
        {
            prev->next = last;
            prev = prev->next;
        }
        prev->next = NULL;
        return pre_head.next;
    }
};
