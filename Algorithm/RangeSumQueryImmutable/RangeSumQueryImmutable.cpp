/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

#include <vector>

class NumArray {
public:
    NumArray(std::vector<int> nums) 
        : dp_(nums.size()) {
        if (nums.empty()) {
            return;
        }
        dp_[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp_[i] += dp_[i - 1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if (i > j) {
            return 0;
        }
        if (i == 0) {
            return dp_[j];
        } else {
            return dp_[j] - dp_[i - 1];
        }
    }
private:
    std::vector<int> dp_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

