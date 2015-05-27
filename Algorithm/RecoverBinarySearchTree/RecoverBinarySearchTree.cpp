/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
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

#include <algorithm>
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
    void recoverTree(TreeNode* root)
    {
        if (root == NULL)
        {
            return;
        }
        TreeNode* prev = NULL;
        TreeNode* node1 = NULL;
        TreeNode* node2 = NULL;
        recoverTreeInoreder(root, prev, node1, node2);
        if (node1 && node2)
        {
            std::swap(node1->val, node2->val);
        }

    }

    void recoverTreeInoreder(TreeNode* node, TreeNode*& prev, TreeNode*& node1, TreeNode*& node2)
    {
        if (node == NULL)
        {
            return;
        }
        recoverTreeInoreder(node->left, prev, node1, node2);
        if (prev && prev->val >= node->val)
        {
            if (node1 == NULL)
            {
                node1 = prev;
            }
            node2 = node;
        }
        prev = node;
        recoverTreeInoreder(node->right, prev, node1, node2);
    }
};
