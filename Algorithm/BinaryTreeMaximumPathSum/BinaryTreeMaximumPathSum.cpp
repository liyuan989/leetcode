/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/

#include <algorithm>
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
    int maxPathSum(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int max_path = 0x80000000;
        doMaxPathSum(root, max_path);
        return max_path;
    }

    int doMaxPathSum(TreeNode* root, int& max_path)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left_sum = std::max(0, doMaxPathSum(root->left, max_path));
        int right_sum = std::max(0, doMaxPathSum(root->right, max_path));
        max_path = std::max(max_path, left_sum + right_sum + root->val);
        return std::max(left_sum, right_sum) + root->val;
    }
};
