/*
Given a singly linked list where elements are sorted in ascending order,
convert it to a height balanced BST.
*/

#include <stdio.h>

 //Definition for singly-linked list.
 struct ListNode
 {
     int        val;
     ListNode*  next;

     ListNode(int x)
         : val(x), next(NULL)
     {
     }
 };


//Definition for a binary tree node.
struct TreeNode
{
    int        val;
    TreeNode*  left;
    TreeNode*  right;

    TreeNode(int x)
        : val(x), left(NULL), right(NULL)
    {
    }
};


// 利用链表的下标号建立一个关于下标的BST, 然后再用中序遍历根据有序链表建立BST.
class Solution
{
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        int list_size = 0;
        for (ListNode* p = head; p; p = p->next)
        {
            ++list_size;
        }
        return makeBST(head, 0, list_size - 1);
    }

    TreeNode* makeBST(ListNode*& head, int start, int end)
    {
        if (start > end || head == NULL)
        {
            return NULL;
        }
        int middle = (start + end + 1) / 2;
        TreeNode* left = makeBST(head, start, middle - 1);
        TreeNode* current  = new TreeNode(head->val);
        current->left = left;
        head = head->next;
        current->right = makeBST(head, middle + 1, end);
        return current;
    }
};
