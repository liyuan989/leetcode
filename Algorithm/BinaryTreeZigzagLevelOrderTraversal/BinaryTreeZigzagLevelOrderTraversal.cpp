/*
Given a binary tree, return the zigzag level order traversal of its nodes' values.
(ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
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
#include <queue>
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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int> > result;
        if (root == NULL)
        {
            return result;
        }
        queue<pair<TreeNode*, int> > queue;
        queue.push(make_pair(root, 1));
        while (!queue.empty())
        {
            TreeNode* node = queue.front().first;
            int level = queue.front().second;
            queue.pop();
            if (level > result.size())
            {
                if (!result.empty() && !(result.size() & 1))
                {
                    std::reverse(result.back().begin(), result.back().end());
                }
                result.push_back(vector<int>(1, node->val));
            }
            else
            {
                result.back().push_back(node->val);
            }
            if (node->left)
            {
                queue.push(make_pair(node->left, level + 1));
            }
            if (node->right)
            {
                queue.push(make_pair(node->right, level + 1));
            }
        }
        if (!result.empty() && !(result.size() & 1))
        {
            std::reverse(result.back().begin(), result.back().end());
        }
        return result;
    }
};
