/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(const string& s)
    {
        vector<string> result;
        if (s.empty())
        {
            return result;
        }
        string ip;
        generateIp(s, 0, 4, ip, result);
        return result;
    }

    void generateIp(const string& s, int index, int k, string ip, vector<string>& result)
    {
        if (k == 0)
        {
            if (index == s.size())
            {
                result.push_back(ip);
            }
            return;
        }
        for (int i = 1; i <= 3 && index + i <= s.size(); ++i)
        {
            string current = s.substr(index, i);
            int val = atoi(current.c_str());
            if (0 <= val && val <= 255 && (current == "0" || current[0] != '0'))
            {
                string next = ip + current;
                if (k != 1)
                {
                    next = next + ".";
                }
                generateIp(s, index + i, k - 1, next, result);
            }
        }
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<string>&& result = s.restoreIpAddresses("25525511135");
    for (auto str : result)
    {
        printf("%s\n", str.c_str());
    }
    return 0;
}
