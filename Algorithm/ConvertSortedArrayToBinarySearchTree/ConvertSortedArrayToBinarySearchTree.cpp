/*
Given an array where elements are sorted in ascending order,
convert it to a height balanced BST.
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
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        if (nums.empty())
        {
            return NULL;
        }
        return generateBST(nums, 0, nums.size() - 1);
    }

    TreeNode* generateBST(vector<int>& nums, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }
        int index = start + (end - start + 1) / 2;
        TreeNode* node = new TreeNode(nums[index]);
        node->left = generateBST(nums, start, index - 1);
        node->right = generateBST(nums, index + 1, end);
        return node;
    }
};

void print(TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    print(root->left);
    printf("%d ", root->val);
    print(root->right);
}

int main(int argc, char* argv[])
{
    vector<int> array = {1,2,3,4,5,6,7,8,9};
    Solution s;
    TreeNode* root = s.sortedArrayToBST(array);
    print(root);
    printf("\n");
    return 0;
}
