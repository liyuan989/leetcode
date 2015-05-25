/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
    vector<TreeNode*> generateTrees(int n)
    {
        return doGenerate(1, n);
    }

    vector<TreeNode*> doGenerate(int low, int high)
    {
        vector<TreeNode*> vec;
        if (low > high || low <= 0 || high <= 0)
        {
            vec.push_back(NULL);
            return vec;
        }
        if (low == high)
        {
            vec.push_back(new TreeNode(low));
            return vec;
        }
        for (int i = low; i <= high; ++i)
        {
            vector<TreeNode*> left_vec = doGenerate(low, i - 1);
            vector<TreeNode*> right_vec = doGenerate(i + 1, high);
            for (int l = 0; l < left_vec.size(); ++l)
            {
                for (int r = 0; r < right_vec.size(); ++r)
                {
                    TreeNode* p = new TreeNode(i);
                    p->left = left_vec[l];
                    p->right = right_vec[r];
                    vec.push_back(p);
                }
            }
        }
        return vec;
    }
};
