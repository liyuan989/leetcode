/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
*/

#include <vector>

class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> dp(n);
        dp[0] = 1;
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        for (int i = 1; i < n; ++i) {
            int min = std::min(dp[index2] * 2, std::min(dp[index3] * 3, dp[index5] * 5));
            if (dp[index2] * 2 == min) {
                ++index2;
            }
            if (dp[index3] * 3 == min) {
                ++index3;
            }
            if (dp[index5] * 5 == min) {
                ++index5;
            }
            dp[i] = min;
        }
        return dp[n - 1];
    }
};

