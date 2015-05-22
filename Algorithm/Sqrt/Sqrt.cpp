/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

#include <stdint.h>
#include <stdio.h>

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 1)
        {
            return 1;
        }
        int64_t low = 0;
        int64_t high = x;
        while (low <= high)
        {
            int64_t pivot = low + (high - low) / 2;
            if (pivot * pivot == x)
            {
                return pivot;
            }
            else if (pivot * pivot < x)
            {
                low = pivot + 1;
            }
            else
            {
                high = pivot - 1;
            }
        }
        return high;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%d\n",s.mySqrt(2147395599));
    return 0;
}
