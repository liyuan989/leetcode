/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path
from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return left_depth > right_depth ? left_depth + 1 : right_depth + 1;
};
