/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    //DP solution
    //
    //dp[i][j] means s1[0...i] and s2[0...j] match s3[0...i+j]
    //
    //formula:
    //
    //dp[i][j] = (s1[i-1] == s3[i+j-1] && dp[i-1][j]) ||
    //           (s2[j-1] == s3[i+j-1] && dp[i][j-1])
    //
    //dp[0][0] = 1
    bool isInterleave(const string& s1, const string& s2, const string& s3)
    {
        int size1 = s1.size();
        int size2 = s2.size();
        int size3 = s3.size();
        if (size1 + size2 != size3)
        {
            return false;
        }
        vector<vector<int> > dp(size1 + 1, vector<int>(size2 + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= size2; ++i)
        {
            if (s2[i - 1] == s3[i - 1])
            {
                dp[0][i] = 1;
            }
            else
            {
                break;
            }
        }
        for (int i = 1; i <= size1; ++i)
        {
            if (s1[i - 1] == s3[i - 1])
            {
                dp[i][0] = 1;
            }
            else
            {
                break;
            }
        }
        for (int i = 1; i <= size1; ++i)
        {
            for (int j = 1; j <= size2; ++j)
            {
                if (s1[i - 1] == s3[i + j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                if (s2[j - 1] == s3[i + j - 1])
                {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }
        return dp[size1][size2];
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%d\n", s.isInterleave("aabcc", "dbbca", "aadbbcbcac"));
    printf("%d\n", s.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
    printf("%d\n", s.isInterleave("aabc", "abad", "aabadabc"));
    return 0;
}
