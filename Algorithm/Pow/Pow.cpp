/*
Implement pow(x, n).
*/

#include <stdio.h>

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
        {
            return 1.0;
        }
        else if (n > 0)
        {
            return doPowWithUnsignedExponent(x, static_cast<size_t>(n));
        }
        else
        {
            double result = doPowWithUnsignedExponent(x, static_cast<size_t>(-n));
            return 1 / result;
        }
    }

    double doPowWithUnsignedExponent(double x, size_t n)
    {
        if (n == 1)
        {
            return x;
        }
        double val = doPowWithUnsignedExponent(x, n >> 1);
        double result = val * val;
        if (n & 1)
        {
            result *= x;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%f\n", s.myPow(8.88023, 3));
    return 0;
}
