/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.
*/

#include <vector>

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m][n];
        int max = 0;
        for (int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            max = std::max(dp[i][0], max);
        }
        for (int i = 0; i < n; ++i) {
            dp[0][i] = matrix[0][i] == '1' ? 1 : 0;
            max = std::max(dp[0][i], max);
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
                } else {
                    dp[i][j] = 0;
                }
                max = std::max(dp[i][j], max);
            }
        }
        return max * max;
    }
};

