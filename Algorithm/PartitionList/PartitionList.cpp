/*
Given a linked list and a value x,
partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x)
    {
        if (head == NULL)
        {
            return NULL;
        }
        ListNode small(0);
        ListNode big(0);
        ListNode* smaller = &small;
        ListNode* bigger = &big;
        while (head)
        {
            if (head->val < x)
            {
                smaller->next = head;
                head = head->next;
                smaller = smaller->next;
            }
            else
            {
                bigger->next = head;
                head = head->next;
                bigger = bigger->next;
            }
        }
        bigger->next = NULL;
        smaller->next = big.next;
        return small.next;
    }
};
