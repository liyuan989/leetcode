/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution,
try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int result = 0x80000000;
        int sum = 0;
        for (int index = 0; index < nums.size(); ++index)
        {
            sum += nums[index];
            if (sum < nums[index])
            {
                sum = nums[index];
            }
            if (sum > result)
            {
                result = sum;
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> array = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    printf("%d\n", s.maxSubArray(array));
    return 0;
}
