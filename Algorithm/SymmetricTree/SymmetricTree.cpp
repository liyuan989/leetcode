/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
 */

#include <stdio.h>

// Definition for a binary tree node.
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

class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == NULL)
        {
            return true;
        }
        return isMatch(root->left, root->right);
    }

    bool isMatch(TreeNode* node1, TreeNode* node2)
    {
        if (node1 == NULL && node2 == NULL)
        {
            return true;
        }
        if (node1 == NULL || node2 == NULL)
        {
            return false;
        }
        if (node1->val == node2->val)
        {
            return isMatch(node1->left, node2->right) && isMatch(node1->right, node2->left);
        }
        else
        {
            return false;
        }
    }
};
