/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

#include <assert.h>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool isMatch(const char* s, const char* p)
    {
        if (*p == '\0')
        {
            return *s == '\0';
        }
        if (*s == '\0')
        {
            return *(p + 1) == '*' && isMatch(s, p + 2);
        }
        if (*(p + 1) == '*')
        {
            return isMatch(s, p + 2) || ((*s == *p || *p == '.') && isMatch(s + 1, p));
        }
        else
        {
            return (*s == *p || *p == '.') && isMatch(s + 1, p + 1);
        }
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    assert(!s.isMatch("aa","a"));
    assert(s.isMatch("aa","aa"));
    assert(!s.isMatch("aaa","aa"));
    assert(s.isMatch("aa", "a*"));
    assert(s.isMatch("aa", ".*"));
    assert(s.isMatch("ab", ".*"));
    assert(s.isMatch("aab", "c*a*b"));
    assert(s.isMatch("aaa", "ab*a*c*a"));
    return 0;
}
