/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

#include <stdint.h>
#include <stdio.h>

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int64_t dividend64 = dividend;
        int64_t divisor64 = divisor;
        bool sign = true;
        if (dividend64 < 0 && divisor64 < 0)
        {
            divisor64 = -divisor64;
            dividend64 = -dividend64;
        }
        if (dividend64 < 0 && divisor64 >= 0)
        {
            dividend64 = -dividend64;
            sign = false;
        }
        if (divisor64 < 0 && dividend64 >= 0)
        {
            divisor64 = -divisor64;
            sign = false;
        }
        int64_t result = 0;
        while (dividend64 > divisor64)
        {
            int64_t val = divisor64;
            int64_t result_tmp = 1;
            while (val < dividend64)
            {
                val <<= 1;
                result_tmp <<= 1;
            }
            dividend64 -= val >> 1;
            result += result_tmp >> 1;
        }
        if (dividend64 == divisor64)
        {
            ++result;
        }
        if (!sign)
        {
            result = -result;
        }
        if (result >= 0x80000000)
        {
            result = 0x7fffffff;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%d\n", s.divide(-1010369383, -2147483648));
    return 0;
}
