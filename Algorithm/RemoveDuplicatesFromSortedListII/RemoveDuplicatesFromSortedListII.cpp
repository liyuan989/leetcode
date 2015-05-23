/*
Given a sorted linked list, delete all nodes that have duplicate numbers,
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
        ListNode* last = head;
        ListNode pre_head(0);
        ListNode* prev = &pre_head;
        int duplicate = 0x80000000;
        while (last->next)
        {
            if (last->val != last->next->val && last->val != duplicate)
            {
                prev->next = last;
                last = last->next;
                prev = prev->next;
            }
            else
            {
                duplicate = last->val;
                last = last->next;
            }
        }
        if (prev->val != last->val && last->val != duplicate)
        {
            prev->next = last;
            prev = prev->next;
        }
        prev->next = NULL;
        return pre_head.next;
    }
};
