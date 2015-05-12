/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer,
then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#include <stdint.h>
#include <stdio.h>
#include <string.h>

class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        int sign = 1;
        if (x < 0)
        {
            sign = -1;
            x = -x;
        }
        int64_t result = 0;
        char str[16];
        snprintf(str, sizeof(str), "%d", x);
        for (int i = strlen(str) - 1; i >= 0; --i)
        {
            result = 10 * result + str[i] - '0';
        }
        if ((sign > 0 && result > 0x7fffffff) ||(sign < 0 && result > 0x80000000))
        {
            return 0;
        }
        return result * sign;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%d\n", s.reverse(-123));
    return 0;
}
