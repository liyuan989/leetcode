/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has
(also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011,
so the function should return 3.
*/

#include <stdint.h>
#include <assert.h>

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int number = 0;
        for (uint32_t i = 0; i < 8 * sizeof(uint32_t); ++i)
        {
            uint32_t temp = n & (1 << i);
            if (temp)
            {
                ++number;
            }
        }
        return number;
    }
};

int main(int argc, char* argv[])
{
    Solution solution;
    assert(solution.hammingWeight(8) == 1);
    assert(solution.hammingWeight(0) == 0);
    assert(solution.hammingWeight(7) == 3);
    assert(solution.hammingWeight(0x7fffffff) == 31);
    return 0;
}
