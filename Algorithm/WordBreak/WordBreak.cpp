/*
Given a string s and a dictionary of words dict,
determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

#include <unordered_set>
#include <string>
#include <vector>
#include <assert.h>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, unordered_set<string>& wordDict)
    {
        if (s.size() == 0 || wordDict.size() == 0)
        {
            return false;
        }
        int size = static_cast<int>(s.size());
        // dp_array的每个元素代表着下标0~当前元素的子序列是否成功匹配, 1表示成功匹配, 0表示无匹配
        vector<int> dp_array(size, 0);
        for (int i = 0; i < size; ++i)
        {
            for (int j = i; j >= 0; --j)
            {
                if (dp_array[j - 1] || j == 0)
                {
                    if (wordDict.find(s.substr(j, i - j + 1)) != wordDict.end())
                    {
                        dp_array[i] = 1;
                        break;
                    }
                }
            }
        }
        if (dp_array[size - 1])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main(int argc, char* argv[])
{
    Solution obj;
    unordered_set<string> s;
    s.insert("aaaa");
    s.insert("aaa");
    assert(obj.wordBreak("aaaaaaa", s));
}
