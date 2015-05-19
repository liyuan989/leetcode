/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

#include <string>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool isMatch(const string& s, const string& p)
    {
        return match(s.c_str(), p.c_str());
    }

    bool match(const char* s, const char* p)
    {
        const char* s_last = NULL;
        const char* p_last = NULL;
        while (*s != '\0')
        {
            if (*p == '*')
            {
                ++p;
                if (*p == '\0')
                {
                    return true;
                }
                s_last = s;
                p_last = p;
            }
            else if (*p == '?' || *p == *s)
            {
                ++p;
                ++s;
            }
            else if (s_last != NULL)
            {
                p = p_last;
                s = ++s_last;
            }
            else
            {
                return false;
            }
        }
        while (*p == '*')
        {
            ++p;
        }
        return *p == '\0';
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%d\n", s.isMatch("abbabbbaabaaabbbbbabbabbabbbabbaaabbbababbabaaabbab", "*aabb***aa**a******aa*"));
    return 0;
}
