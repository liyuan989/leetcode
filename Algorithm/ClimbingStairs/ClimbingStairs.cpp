/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include <stdio.h>

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        int prev = 1;
        int last = 2;
        int sum = 0;
        for (int i = 3; i <= n; ++i)
        {
            sum = prev + last;
            prev = last;
            last = sum;
        }
        return sum;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%d\n", s.climbStairs(10));
    return 0;
}
