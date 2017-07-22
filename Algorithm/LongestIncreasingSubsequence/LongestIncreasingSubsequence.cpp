/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/

#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::vector<int> dp(nums.size());
        dp[0] = 1;
        int result = 1;
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            result = std::max(result, dp[i]);
        }
        return result;
    }
};

