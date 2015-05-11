/*
Given a string S and a string T,
find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows,
you are guaranteed that there will always be only one unique minimum window in S.
*/

#include <string>
#include <string.h>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        string ret;
        if (s.empty() || t.empty() || s.size() < t.size())
        {
            return ret;
        }
        int map[256];
        int window[256];
        memset(map, 0, sizeof(map));
        memset(window, 0, sizeof(window));
        for (size_t i = 0; i < t.size(); ++i)
        {
            ++map[t[i]];
        }
        size_t count = 0;
        size_t min_length = 0xffffffff;
        int start = -1;
        for (size_t low = 0, high = 0; high < s.size(); ++high)
        {
            char c = s[high];
            if (map[c] != 0)
            {
                ++window[c];
                if (window[c] <= map[c])
                {
                    ++count;
                }
            }
            if (count >= t.size())
            {
                while (map[s[low]] == 0 || window[s[low]] > map[s[low]])
                {
                    if (window[s[low]] > map[s[low]])
                    {
                        --window[s[low]];
                    }
                    ++low;
                }
                if (high - low + 1 <min_length)
                {
                    min_length = high - low + 1;
                    start = low;
                }
            }
        }
        if (start >= 0 && min_length > 0)
        {
            ret = s.substr(start, min_length);
        }
        return ret;
    }
};
