/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree
in which the depth of the two subtrees of every node never differ by more than 1.
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
    bool isBalanced(TreeNode* root)
    {
        if (root == NULL)
        {
            return true;
        }
        int depth;
        return isBalanced(root, depth);
    }

    bool isBalanced(TreeNode* root, int& depth)
    {
        if (root == NULL)
        {
            depth = 0;
            return true;
        }
        int depth_left;
        int depth_right;
        if (isBalanced(root->left, depth_left) && isBalanced(root->right, depth_right))
        {
            int diff = depth_left - depth_right;
            if (-1 <= diff && diff <= 1)
            {
                depth = depth_left > depth_right ? depth_left + 1 : depth_right + 1;
                return true;
            }
            return false;
        }
        return false;
    }
};
