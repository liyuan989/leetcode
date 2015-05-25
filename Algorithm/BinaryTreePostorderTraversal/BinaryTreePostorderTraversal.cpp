/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

#include <utility>
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }
        srand(time(NULL));
        if (rand() & 1)
        {
            postorder_loop(root, result);
        }
        else
        {
            postorder_recursive(root, result);
        }
        return result;
    }

    void postorder_recursive(TreeNode* node, vector<int>& result)
    {
        if (node == NULL)
        {
            return;
        }
        postorder_recursive(node->left, result);
        postorder_recursive(node->right, result);
        result.push_back(node->val);
    }

    void postorder_loop(TreeNode* node, vector<int>& result)
    {
        stack<pair<TreeNode*, int> > stack;
        while (node)
        {
            stack.push(make_pair(node, 0));
            node = node->left;
        }
        while (!stack.empty())
        {
            while (!stack.empty() && stack.top().second == 1)
            {
                result.push_back(stack.top().first->val);
                stack.pop();
            }
            if (!stack.empty())
            {
                stack.top().second = 1;
                node = stack.top().first->right;
            }
            while (node)
            {
                stack.push(make_pair(node, 0));
                node = node->left;
            }
        }
    }
};
