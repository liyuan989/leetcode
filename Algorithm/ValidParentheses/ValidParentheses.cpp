/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool isValid(const string& s)
    {
        if (s.empty())
        {
            return false;
        }
        int hash[256];
        int map[256];
        memset(hash, 0, sizeof(hash));
        memset(map, 0, sizeof(map));
        char left[] = "([{";
        char right[] = ")]}";
        for (int i = 0; i < 3; ++i)
        {
            hash[left[i]] = 1;
            map[right[i]] = left[i];
        }
        vector<char> stack;
        for (int i = 0; i < s.size(); ++i)
        {
            if (hash[s[i]] == 1)
            {
                stack.push_back(s[i]);
            }
            else
            {
                if (stack.empty() || stack.back() != map[s[i]])
                {
                    return false;
                }
                stack.pop_back();
            }
        }
        if (stack.empty())
        {
            return true;
        }
        return false;
    }
};
