/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            while (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i])
            {
                std::swap(nums[nums[i] - 1], nums[i]);
            }
        }
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] !=  i + 1)
            {
                return i + 1;
            }
            ++i;
        }
        return i + 1;
    }
};

int main(int argc, char* argv[])
{
    vector<int> array = {1, 2, 3};
    Solution s;
    printf("%d\n", s.firstMissingPositive(array));
    return 0;
}
