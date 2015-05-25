/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    // DP solution
    // dp[i] means total ways for a string which end from index i
    int numDecodings(const string& s)
    {
        if (s.empty())
        {
            return 0;
        }
        if (s.size() == 1)
        {
            return s[0] != '0';
        }
        int size = s.size();
        vector<int> dp(size + 1, 0);
        dp[0] = 1;
        dp[1] = ('1' <= s[0] && s[9] <= '9') ? 1 : 0;
        if (dp[1] == 0)
        {
            return 0;
        }
        for (int i = 2; i <= size; ++i)
        {
            int factor1 = 0;
            int factor2 = 0;
            if (s[i - 1] != '0')
            {
                factor1 = dp[i - 1];
                if (s[i - 2] == '1')
                {
                    factor2 = dp[i - 2];
                }
                else if (s[i - 2] == '2' && '1' <= s[i - 1] && s[i - 1] <= '6')
                {
                    factor2 = dp[i - 2];
                }
            }
            else
            {
                if ('1' <= s[i - 2] && s[i - 2] <= '2')
                {
                    factor2 = dp[i - 2];
                }
            }
            dp[i] = factor1 + factor2;
        }
        return dp[size];
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%d\n", s.numDecodings("12"));
    printf("%d\n", s.numDecodings("230"));
    return 0;
}
