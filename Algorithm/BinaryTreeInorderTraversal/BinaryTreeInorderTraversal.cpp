/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal,
where '#' signifies a path terminator where no node exists below.

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

#include <stack>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


//Definition for a binary tree node.
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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }
        srand(time(NULL));
        if (rand() & 1)
        {
            inorder_loop(root, result);
        }
        else
        {
            inorder_recursive(root, result);
        }
        return result;
    }

    void inorder_recursive(TreeNode* node, vector<int>& result)
    {
        if (node == NULL)
        {
            return;
        }
        inorder_recursive(node->left, result);
        result.push_back(node->val);
        inorder_recursive(node->right, result);
    }

    void inorder_loop(TreeNode* node, vector<int>& result)
    {
        stack<TreeNode*> stack;
        while (node)
        {
            stack.push(node);
            node = node->left;
        }
        while (!stack.empty())
        {
            node = stack.top();
            stack.pop();
            result.push_back(node->val);
            node = node->right;
            while (node)
            {
                stack.push(node);
                node = node->left;
            }
        }
    }
};
