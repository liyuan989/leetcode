/*
 * te: This is an extension of House Robber.
 *
 * After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 *
 * Credits:
 * Special thanks to @Freezen for adding this problem and creating all test cases.
*/

#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums.front();
        }
        int ret1 = robCommon(nums, 0, nums.size() - 1);
        int ret2 = robCommon(nums, 1, nums.size());
        return std::max(ret1, ret2);
    }

    int robCommon(std::vector<int>& nums, int start, int end) {
        int select = 0;
        int no_select = 0;
        for (int i = start; i < end; ++i) {
            int tmp = no_select;
            no_select = std::max(select, no_select);
            select = tmp + nums[i];
        }
        return std::max(select, no_select);
    }
};

