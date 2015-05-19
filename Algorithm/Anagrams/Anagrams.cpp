/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> anagrams(vector<string>& strs)
    {
        vector<string> result;
        unordered_map<string, int> hash;
        for (int i = 0; i < strs.size(); ++i)
        {
            string s = strs[i];
            std::sort(s.begin(), s.end());
            if (hash.find(s) == hash.end())
            {
                hash[s] = i;
            }
            else
            {
                if (hash[s] >= 0)
                {
                    result.push_back(strs[hash[s]]);
                    hash[s] = -1;
                }
                result.push_back(strs[i]);
            }
        }
        return result;
    }
};
