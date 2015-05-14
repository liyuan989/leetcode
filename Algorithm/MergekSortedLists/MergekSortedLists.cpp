/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/

#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty())
        {
            return NULL;
        }
        if (lists.size() < 2)
        {
            return lists.front();
        }
        return doMerge(lists, 0, lists.size() - 1);
    }

    ListNode* doMerge(vector<ListNode*>& lists, int begin, int end)
    {
        if (begin == end)
        {
            return lists[begin];
        }
        int pivot = (begin + end + 1) / 2;
        ListNode* l1 = doMerge(lists, begin, pivot - 1);
        ListNode* l2 = doMerge(lists, pivot, end);
        return mergeTwoLists(l1, l2);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode head(0);
        ListNode* p = &head;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1 == NULL)
        {
            p->next = l2;
        }
        else
        {
            p->next = l1;
        }
        return head.next;
    }
};

int main(int argc, char* argv[])
{
    vector<ListNode*> v(1000);
    for (int i = 0; i < 1000; ++i)
    {
        v[i] = new ListNode(i);
    }
    Solution s;
    ListNode* head = s.mergeKLists(v);
    while (head)
    {
        printf("%d\n", head->val);
        head = head->next;
    }
    for (int i = 0; i < 1000; ++i)
    {
        delete v[i];
    }
    return 0;
}
