/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty())
        {
            return "";
        }
        if (strs.size() == 1)
        {
            return strs.front();
        }
        int length = 0;
        int index = 0;
        bool flag = true;
        while (flag)
        {
            for (int i = 1; i < strs.size(); ++i)
            {
                if (strs[i].empty())
                {
                    return "";
                }
                if (index >= strs[i].size() || strs[0][index] != strs[i][index])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ++length;
                ++index;
            }
        }
        return strs.front().substr(0, length);
    }
};
