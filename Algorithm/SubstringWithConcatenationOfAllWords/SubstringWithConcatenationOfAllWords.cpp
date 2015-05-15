/*
You are given a string, s, and a list of words, words, that are all of the same length.
Find all starting indices of substring(s) in s that is a concatenation of each word in words
exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

#include <unordered_map>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        vector<int> result;
        if (s.empty() || words.empty())
        {
            return result;
        }
        unordered_map<string, int> expect;
        unordered_map<string, int> hash;
        for (int i = 0; i < words.size(); ++i)
        {
            ++expect[words[i]];
            hash[words[i]] = 0;
        }
        int length = words.front().size();
        int s_size = s.size();
        int prev = 0;
        int last = 0;
        while (last < s_size - length + 1)
        {
            for (unordered_map<string, int>::iterator it = hash.begin(); it != hash.end(); ++it)
            {
                it->second = 0;
            }
            while (last < s_size - length + 1 && hash.find(s.substr(last, length)) == hash.end())
            {
                ++last;
            }
            prev = last;
            int count = 0;
            while (last < s_size - length + 1 && count < length && hash.find(s.substr(last, length)) != hash.end())
            {
                ++hash[s.substr(last, length)];
                last += length;
                ++count;
            }
            if (count == words.size())
            {
                int val = prev;
                bool flag = true;
                while (prev < last)
                {
                    string sub = s.substr(prev, length);
                    if (hash[sub] != expect[sub])
                    {
                        flag = false;
                    }
                    prev += length;
                }
                if (flag)
                {
                    result.push_back(val);
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<string> v;
    v.push_back("mississippis");
    vector<int>&& r = s.findSubstring("mississippi", v);
    for (auto i : r)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
