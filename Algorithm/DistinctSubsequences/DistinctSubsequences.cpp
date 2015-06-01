/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting
some (can be none) of the characters without disturbing the relative positions of the remaining characters.
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    // DP solution
    int numDistinct(const string& s, const string& t)
    {
        if (s.empty() || t.empty() || s.size() < t.size())
        {
            return 0;
        }
        int s_size = s.size();
        int t_size = t.size();
        vector<vector<int> > dp(s_size + 1, vector<int>(t_size + 1, 0));
        for (int i = 0; i <= s_size; ++i)
        {
            dp[i][0] = 1;
        }
        for (int i = 0; i <= s_size; ++i)
        {
            for (int j = 1; j <= t_size; ++j)
            {
                if (i < j)
                {
                    continue;
                }
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s_size][t_size];
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%d\n", s.numDistinct("a", "b"));
    printf("%d\n", s.numDistinct("ABCDE", "ACE"));
    printf("%d\n", s.numDistinct("rabbbit", "rabbit"));
    return 0;
}
