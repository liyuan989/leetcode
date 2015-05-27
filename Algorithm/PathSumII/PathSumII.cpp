/*
Given a binary tree and a sum,
find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

#include <vector>
#include <stdio.h>

using namespace std;

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
    vector<vector<int> > pathSum(TreeNode* root, int sum)
    {
        vector<vector<int> > result;
        if (root == NULL)
        {
            return result;
        }
        vector<int> array;
        getPathSum(root, 0, sum, array, result);
        return result;
    }

    void getPathSum(TreeNode* node, int val, int sum, vector<int>& array, vector<vector<int> >& result)
    {
        if (node == NULL)
        {
            return;
        }
        array.push_back(node->val);
        int current = val + node->val;
        if (current == sum && node->left == NULL && node->right == NULL)
        {
            result.push_back(array);
        }
        getPathSum(node->left, current, sum, array, result);
        getPathSum(node->right, current, sum, array, result);
        array.pop_back();
    }
};
