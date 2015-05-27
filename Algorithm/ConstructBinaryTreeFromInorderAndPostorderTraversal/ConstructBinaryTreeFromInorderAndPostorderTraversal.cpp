/*
Given inorder and postorder traversal of a tree, construct the binary tree.

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0)
        {
            return NULL;
        }
        return initTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* initTree(vector<int>& inorder, int start1, int end1, vector<int>& postorder, int start2, int end2)
    {
        if (start1 > end1 || start2 > end2)
        {
            return NULL;
        }
        int index = start1;
        while (index <= end1 && inorder[index] != postorder[end2])
        {
            ++index;
        }
        int length = index - start1;
        TreeNode* node = new TreeNode(postorder[end2]);
        node->left = initTree(inorder, start1, index - 1, postorder, start2, start2 + length - 1);
        node->right = initTree(inorder, index + 1, end1, postorder, start2 + length, end2 - 1);
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
    vector<int> v1 = {2, 1, 3};
    vector<int> v2 = {2, 3, 1};
    Solution s;
    TreeNode* root = s.buildTree(v1, v2);
    print(root);
    printf("\n");
    return 0;
}
