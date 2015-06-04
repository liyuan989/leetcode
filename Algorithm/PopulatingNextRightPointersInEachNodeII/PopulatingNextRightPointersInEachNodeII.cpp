/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
 */

#include <queue>
#include <stdio.h>

using namespace std;

// Definition for binary tree with next pointer.
struct TreeLinkNode
{
    int            val;
    TreeLinkNode*  left;
    TreeLinkNode*  right;
    TreeLinkNode*  next;

    TreeLinkNode(int x)
        : val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};

class Solution
{
public:
    void connect(TreeLinkNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        queue<pair<TreeLinkNode*, int> > queue;
        queue.push(make_pair(root, 1));
        while (!queue.empty())
        {
            TreeLinkNode* node = queue.front().first;
            int level = queue.front().second;
            queue.pop();
            if (queue.empty() || level < queue.front().second)
            {
                node->next = NULL;
            }
            else
            {
                node->next = queue.front().first;
            }
            if (node->left)
            {
                queue.push(make_pair(node->left, level + 1));
            }
            if (node->right)
            {
                queue.push(make_pair(node->right, level + 1));
            }
        }
    }
};
