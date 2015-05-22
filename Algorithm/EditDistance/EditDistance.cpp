/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2.
(each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    // DP solution.
    // A[i][j] = A[i - 1][j - 1], if(word1[i] == word2[j])
    //
    // A[i][j] = min(A[i - 1][j], A[i][j - 1], A[i - 1][j - 1]) + 1, if(word1[i] != word2[j])
    // 1) delete the last char in word1
    // 2) delete the last char in word2
    // 3) change the last char
    int minDistance(const string& word1, const string& word2)
    {
        int word1_size = word1.size();
        int word2_size = word2.size();
        vector<int> line(word2_size + 1, 0);
        vector<vector<int> > dp(word1_size + 1, line);
        for (int i = 0; i <= word2_size; ++i)
        {
            dp[0][i] = i;
        }
        for (int i = 0; i <= word1_size; ++i)
        {
            dp[i][0] = i;
        }
        for (int i = 1; i <= word1_size; ++i)
        {
            for (int j = 1; j <= word2_size; ++j)
            {
                if (word1[i - 1] == word2[ j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = minOfThree(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                }
            }
        }
        return dp[word1_size][word2_size];
    }

    int minOfThree(int a, int b, int c)
    {
        return std::min(a, std::min(b, c));
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%d\n", s.minDistance("ab", "ba"));
    return 0;
}
