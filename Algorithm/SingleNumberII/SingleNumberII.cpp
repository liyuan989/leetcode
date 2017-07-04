/*
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int one = 0;
        int two = 0;
        int three = 0;
        for (int n : nums) {
            two |= (one & n);
            one ^= n; 
            three = one & two;
            one &= ~three;
            two &= ~three;
        }
        return one;
    }
};

