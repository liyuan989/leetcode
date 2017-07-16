/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.
*/

#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int select = 0;
        int no_select = 0;
        for (int val : nums) {
            int tmp = no_select;
            no_select = std::max(select, no_select);
            select = tmp + val;
        }
        return std::max(select, no_select);
    }
};

