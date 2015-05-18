/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

#include <string>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string result = "1";
        if (n == 1)
        {
            return result;
        }
        for (int i = 2; i <= n; ++i)
        {
            const char* p = result.c_str();
            string s;
            while (*p != '\0')
            {
                int count = 0;
                char val = *p;
                while (*p != '\0' && *p == val)
                {
                    ++count;
                    ++p;
                }
                char str[16];
                snprintf(str, sizeof(str), "%d", count);
                s += str;
                s.push_back(val);
            }
            result.swap(s);
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%s\n", s.countAndSay(2).c_str());
    return 0;
}
