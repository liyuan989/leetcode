/*
Given a binary tree and a sum, determine if the tree has a
root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode* root, int sum)
    {
        if (root == NULL)
        {
            return false;
        }
        return hasPathSum(root, 0, sum);
    }

    bool hasPathSum(TreeNode* node, int val, int sum)
    {
        if (node == NULL)
        {
            return false;
        }
        int current = val + node->val;
        if (current == sum && node->left == NULL && node->right == NULL)
        {
            return true;
        }
        else
        {
            return hasPathSum(node->left, current, sum) || hasPathSum(node->right, current, sum);
        }
    }
};
