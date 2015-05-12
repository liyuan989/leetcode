/*
Given a string S, find the longest palindromic substring in S.
You may assume that the maximum length of S is 1000,
and there exists one unique longest palindromic substring.
*/

#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string longestPalindrome(const string& s)
    {
        if (s.empty())
        {
            return "";
        }
        if (s.size() == 1)
        {
            return s;
        }
        int start = 0;
        int length = 1;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (s.size() - i < length / 2)
            {
                break;
            }
            int begin = i;
            int end = i;
            while (end < s.size() - 1 && s[end] == s[end + 1])
            {
                ++end;
            }
            while (begin > 0 && end < s.size() - 1 && s[begin - 1] == s[end + 1])
            {
                --begin;
                ++end;
            }
            int size = end - begin + 1;
            if (size > length)
            {
                length = size;
                start = begin;
            }
        }
        return s.substr(start, length);
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    string str(1000,'a');
    cout << s.longestPalindrome(str);
    return 0;
}
