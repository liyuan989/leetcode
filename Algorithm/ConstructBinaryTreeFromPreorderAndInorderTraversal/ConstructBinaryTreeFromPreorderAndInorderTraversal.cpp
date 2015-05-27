/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if (preorder.size() == 0 || inorder.size() == 0)
        {
            return NULL;
        }
        return initTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* initTree(vector<int>& preorder, int start1, int end1, vector<int>& inorder, int start2, int end2)
    {
        if (start1 > end1 || start2 > end2)
        {
            return NULL;
        }
        int index = start2;
        while (index <= end2 && inorder[index] != preorder[start1])
        {
            ++index;
        }
        TreeNode* node = new TreeNode(preorder[start1]);
        int length = index - start2;
        node->left = initTree(preorder, start1 + 1, start1 + length, inorder, start2, index - 1);
        node->right = initTree(preorder, start1 + length + 1, end1, inorder, index + 1, end2);
        return node;
    }
};

void print(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->val);
    print(root->left);
    print(root->right);
}

int main(int argc, char* argv[])
{
    vector<int> v1 = {1,2};
    vector<int> v2 = {2,1};
    Solution s;
    TreeNode* root = s.buildTree(v1, v2);
    print(root);
    printf("\n");
    return 0;
}
