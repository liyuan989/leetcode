/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    int minCut(std::string s) {
        if (s.empty()) {
            return 0;
        }
        int len = static_cast<int>(s.size());
        std::vector<int> min(len + 1);
        for (int i = 0; i < len; ++i) {
            min[i] = len - i;
        }
        std::vector<std::vector<char>> matrix(len);
        for(auto& v : matrix) {
            v.resize(len);
        }
        for (int i = len - 1; i >=0; --i) {
            for (int j = i; j < len; ++j) {
                if ((j - i < 2 && s[i] == s[j]) ||
                    (matrix[i + 1][j - 1] && s[i] == s[j])) {
                    matrix[i][j] = 1;
                    min[i] = std::min(min[i], min[j + 1] + 1);
                }
            }
        }
        return min[0] - 1;
    }
};

int main(int argc, const char* argv[]) {
    Solution s;
    int result = s.minCut("aab");
    std::cout << result << std::endl;
    return 0;
}

