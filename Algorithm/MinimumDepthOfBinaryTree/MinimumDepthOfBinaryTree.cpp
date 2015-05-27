/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path
from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int depth_left = minDepth(root->left);
        int depth_right = minDepth(root->right);
        if (depth_left == 0 && depth_right == 0)
        {
            return 1;
        }
        if (depth_left == 0)
        {
            return depth_right + 1;
        }
        if (depth_right == 0)
        {
            return depth_left + 1;
        }
        return depth_left < depth_right ? depth_left + 1 : depth_right + 1;
    }
};
