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
    vector<int> findSubstring(const string& s, vector<string>& words)
    {
        vector<int> result;
        if (s.empty() || words.empty())
        {
            return result;
        }
        unordered_map<string, int> expect;
        for (int i = 0; i < words.size(); ++i)
        {
            ++expect[words[i]];
        }
        int length = words[0].size();
        int s_size = s.size();
        for (int i = 0; i < length; ++i)
        {
            unordered_map<string, int> hash;
            int count = 0;
            for (int prev = i, last = i; last + length <= s_size; last += length)
            {
                string sub = s.substr(last, length);
                if (expect.find(sub) == expect.end())
                {
                    hash.clear();
                    count = 0;
                    prev = last + length;
                    continue;
                }
                ++count;
                ++hash[sub];
                if (hash[sub] > expect[sub])
                {
                    while (s.substr(prev, length) != sub)
                    {
                        --hash[s.substr(prev, length)];
                        --count;
                        prev += length;
                    }
                    --hash[s.substr(prev, length)];
                    --count;
                    prev += length;
                }
                if (count == words.size())
                {
                    result.push_back(prev);
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
    v.push_back("foo");
    v.push_back("bar");
    vector<int>&& result = s.findSubstring("barfoothefoobarman", v);
    for (auto i : result)
    {
        printf("%d ", i);
    }
    return 0;
}
