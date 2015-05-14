/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        std::sort(nums.begin(), nums.end());
        int result = 0;
        int interval = 0x7fffffff;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int pivot = i + 1;
            int end = nums.size() - 1;
            while (pivot < end)
            {
                int sum = nums[i] + nums[pivot] + nums[end];
                int diff = target - sum > 0 ? target - sum : sum - target;
                if (diff < interval)
                {
                    interval = diff;
                    result = sum;
                }
                if (sum == target)
                {
                    return target;
                }
                else if (sum < target)
                {
                    while (pivot < end && nums[pivot] == nums[pivot + 1])
                    {
                        ++pivot;
                    }
                    ++pivot;
                }
                else
                {
                    while (pivot < end && nums[end] == nums[end - 1])
                    {
                        --end;
                    }
                    --end;
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> v = {1,1,-1};
    printf("%d\n", s.threeSumClosest(v, 0));
    return 0;
}
