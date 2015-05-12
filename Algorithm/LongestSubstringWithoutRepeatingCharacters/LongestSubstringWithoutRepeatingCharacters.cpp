/*
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc",
which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include <string>
#include <iostream>
#include <string.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
        {
            return 0;
        }
        int hash[256];
        memset(hash, 0, sizeof(hash));
        int result = -1;
        int begin = 0;
        int end = 0;
        int current_len = 0;
        while (end < s.size())
        {
            int count = ++hash[s[end]];
            if (count <= 1)
            {
                ++end;
                ++current_len;
            }
            else
            {
                if (current_len > result)
                {
                    result = current_len;
                }
                --hash[s[end]];
                while (s[begin] != s[end])
                {
                    if (hash[s[begin]])
                    {
                        hash[s[begin]] = 0;
                    }
                    ++begin;
                }
                ++begin;
                ++end;
                current_len = end - begin;
            }
        }
        if (current_len > result)
        {
            result = current_len;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    cout << s.lengthOfLongestSubstring("tmmzuxt");
    return 0;
}
