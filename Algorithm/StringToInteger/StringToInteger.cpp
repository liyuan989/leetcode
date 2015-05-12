/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases.
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
You are responsible to gather all the input requirements up front.
*/

#include <string>
#include <stdint.h>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    int myAtoi(const string& str)
    {
        if (str.empty())
        {
            return 0;
        }
        const char* s = str.data();
        int sign = 1;
        while (*s == ' ')
        {
            ++s;
        }
        if (*s == '\0')
        {
            return 0;
        }
        if (*s == '+')
        {
            ++s;
        }
        else if (*s == '-')
        {
            sign = -1;
            ++s;
        }
        int64_t result = 0;
        while ('0' <= *s && *s <= '9')
        {
            if (result > 0x7fffffff)
            {
                break;
            }
            result = 10 * result + *s - '0';
            ++s;
        }
        if (sign > 0 && result > 0x7fffffff)
        {
            return 0x7fffffff;
        }
        else if (sign < 0 && result > 0x80000000)
        {
            return 0x80000000;
        }
        return result * sign;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%d\n", s.myAtoi("5324234241432423"));
    return 0;
}
