/*
Given a string s1,
we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool isScramble(const string& s1, const string& s2)
    {
        if (s1.empty() || s2.empty() || s1.size() != s2.size())
        {
            return false;
        }
        if (s1 == s2)
        {
            return true;
        }
        string ss1 = s1;
        string ss2 = s2;
        std::sort(ss1.begin(), ss1.end());
        std::sort(ss2.begin(), ss2.end());
        if (ss1 != ss2)
        {
            return false;
        }
        for (int i = 1; i < s1.size(); ++i)
        {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i)))
            {
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i, i)) &&
                isScramble(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i)))
            {
                return true;
            }
        }
        return false;
    }

    // DP sotution
    //
    // dp[k][i][j]
    // i, means the substr of s1 start from i.
    // j, means the substr of s2 start from j.
    // k, means the length of substr.
    //
    // formula:
    //
    // dp[1][i][j] = (s1[i] == s2[j]) ? 1 : 0 (k == 1)
    //
    // dp[k][i][j] = (dp[pivot][i][j] && dp[k - pivot][i + pivot][j + pivot]) ||
    //               (dp[pivot][i][j + k - pivot] && dp[k - pivot][i + pivot][j])
    // ps: pivot partition the string , so 1 <= pivot < k.
    //
    // This thought is samilar with the recursive method.
    bool isScramble_dp(const string& s1, const string& s2)
    {
        if (s1.empty() || s2.empty() || s1.size() != s2.size())
        {
            return false;
        }
        if (s1 == s2)
        {
            return true;
        }
        int size = s1.size();
        vector<vector<vector<int> > > dp(size + 1, vector<vector<int> >(size, vector<int>(size, 0)));
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (s1[i] == s2[j])
                {
                    dp[1][i][j] = 1;
                }
            }
        }
        for (int k = 2; k <= size ; ++k)
        {
            for (int i = 0; i < size - k + 1; ++i)
            {
                for (int j = 0; j < size - k + 1; ++j)
                {
                    for (int pivot = 1; pivot < k && dp[k][i][j] == 0; ++pivot)
                    {
                        dp[k][i][j] = (dp[pivot][i][j] && dp[k - pivot][i + pivot][j + pivot]) ||
                                      (dp[pivot][i][j + k - pivot] && dp[k - pivot][i + pivot][j]);
                    }
                }
            }
        }
        return dp[size][0][0];
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%d\n", s.isScramble("tqxpxeknttgwoppemjkivrulaflayn", "afaylnlurvikjmeppowgttnkexpxqt"));
    printf("%d\n", s.isScramble_dp("tqxpxeknttgwoppemjkivrulaflayn", "afaylnlurvikjmeppowgttnkexpxqt"));
    printf("%d\n", s.isScramble("great", "greta"));
    printf("%d\n", s.isScramble_dp("great", "greta"));
    return 0;
}
