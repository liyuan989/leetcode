/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    // KMP
    int strStr(const string& haystack, const string& needle)
    {
        if (needle.empty() && haystack.empty())
        {
            return 0;
        }
        if (needle.empty())
        {
            return -1;
        }
        vector<int>&& next = makeNextArray(needle);
        int str = 0;
        int sub = 0;
        while (str < haystack.size() && sub < needle.size())
        {
            if (haystack[str] == needle[sub])
            {
                ++str;
                ++sub;
            }
            else
            {
                if (sub == 0)
                {
                    ++str;
                }
                else
                {
                    sub = next[sub];
                }
            }
        }
        if (sub == needle.size())
        {
            return str - needle.size();
        }
        return -1;
    }

    vector<int> makeNextArray(const string& needle)
    {
        vector<int> next(needle.size());
        next[0] = 0;
        int k = -1;
        int j = 0;
        while (j < needle.size() - 1)
        {
            if (j == 0 || needle[k] == needle[j])
            {
                ++k;
                next[j + 1] = k;
            }
            else
            {
                k = 0;
            }
            ++j;
        }
        return next;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%d\n", s.strStr("abdabca", "abc"));
    return 0;
}
