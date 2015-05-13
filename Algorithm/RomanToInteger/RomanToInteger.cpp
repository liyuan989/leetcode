/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    int romanToInt(const string& s)
    {
        char r[] = "MDCLXVI";
        int hash[256];
        int val[] = {1000, 500, 100, 50, 10, 5, 1};
        for (int i = 0; i < sizeof(r); ++i)
        {
            hash[r[i]] = val[i];
        }
        int index = 0;
        int result = 0;
        while (index < s.size())
        {
            if (index + 1 < s.size() && hash[s[index + 1]] > hash[s[index]])
            {
                result += hash[s[index + 1]] - hash[s[index]];
                index += 2;
            }
            else
            {
                result += hash[s[index]];
                ++index;
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%d\n", s.romanToInt("MMMCMXCIX"));
    return 0;
}
