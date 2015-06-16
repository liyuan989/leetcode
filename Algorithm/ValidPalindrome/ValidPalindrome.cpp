/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

#include <string>
#include <ctype.h>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.empty())
        {
            return true;
        }
        int size = s.size();
        int prev = 0;
        int last = s.size() - 1;
        while (prev < last)
        {
            while (!isAlphaOrNum(s[prev]) && prev < last)
            {
                ++prev;
            }
            while (!isAlphaOrNum(s[last]) && prev < last)
            {
                --last;
            }
            if (s[prev] != s[last])
            {
                return false;
            }
            ++prev;
            --last;
        }
        return true;
    }

    bool isAlphaOrNum(char& n)
    {
        if ('A' <= n && n <= 'Z')
        {
            n += 'a' - 'A';
            return true;
        }
        if (('a' <= n && n <= 'z') ||
            ('0' <= n && n <= '9'))
        {
            return true;
        }
        return false;
    }
};
