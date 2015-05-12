/*
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/


// Definition for singly-linked list.

#include <stdio.h>

using namespace std;

struct ListNode
{
    int        val;
    ListNode*  next;

    ListNode(int x) :
       val(x), next(NULL)
   {
   }
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        ListNode* head = new ListNode(0);
        ListNode* result = head;
        int mask = makeSum(l1, l2, result);
        ListNode* longer = l1 ? l1 : l2;
        while (longer)
        {
            int val = longer->val + mask;
            mask = val / 10;
            ListNode* p = new ListNode(val % 10);
            result->next = p;
            result = result->next;
            longer = longer->next;
        }
        if (mask)
        {
            result->next = new ListNode(mask);
        }
        ListNode* ret = head->next;
        delete head;
        return ret;
    }

    int makeSum(ListNode*& l1, ListNode*& l2, ListNode*& result)
    {
        int mask = 0;
        while (l1 && l2)
        {
            int val = l1->val + l2->val + mask;
            mask = val / 10;
            ListNode* p = new ListNode(val % 10);
            result->next = p;
            result = result->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        return mask;
    }
};
