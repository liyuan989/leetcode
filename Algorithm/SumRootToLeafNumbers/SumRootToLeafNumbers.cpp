/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
 */

#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) {
            return 0;
        }
        std::vector<int> vec;
        int sum = 0;
        caculate(root, 0, vec, sum);
        return sum;
    }

    void caculate(TreeNode* node, int level, std::vector<int>& vec, int& sum) {
        if (!node) {
            return;
        }
        vec.push_back(node->val);
        if (!node->left && !node->right) {
            for (int bit = level, i = 0; bit >=0 && i < static_cast<int>(vec.size()); --bit, ++i) {
                sum += vec[i] * pow(10, bit);
            }
        }
        caculate(node->left, level + 1, vec, sum);
        caculate(node->right, level + 1, vec, sum);
        vec.pop_back();
    }

    int pow(int base, int index) {
        int result = 1;
        for (int i = 0; i < index; ++i) {
            result *= base;
        }
        return result;
    }
};

