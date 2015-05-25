/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
*/

#include <stack>
#include <vector>
#include <time.h>
#include <stdlib.h>
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
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }
        srand(time(NULL));
        if (rand() & 1)
        {
            preorder_loop(root, result);
        }
        else
        {
            preorder_recursive(root, result);
        }
        return result;
    }

    void preorder_recursive(TreeNode* node, vector<int>& result)
    {
        if (node == NULL)
        {
            return;
        }
        result.push_back(node->val);
        preorder_recursive(node->left, result);
        preorder_recursive(node->right, result);
    }

    void preorder_loop(TreeNode* node, vector<int>& result)
    {
        stack<TreeNode*> stack;
        while (node)
        {
            result.push_back(node->val);
            stack.push(node);
            node = node->left;
        }
        while (!stack.empty())
        {
            node = stack.top()->right;
            stack.pop();
            while (node)
            {
                result.push_back(node->val);
                stack.push(node);
                node = node->left;
            }
        }
    }
};
