/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2.
(Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    // greedy algorithm, efficient.
    // All we have to do is to iterate though all positions we can jump from where we standing,
    // find the largest i + nums[i] (greedy) and jump to that index. O(n) in time and constant space.
    int jump(vector<int>& nums)
    {
        if (nums.size() < 2)
        {
            return 0;
        }
        int i = 0;
        int count = 0;
        while (i < nums.size() - 1 && i + nums[i] < nums.size() - 1)
        {
            int max =  i + 1;
            for (int j = i + 1; j <= i + nums[i]; ++j)
            {
                max = (max + nums[max] > j + nums[j]) ? max : j;
            }
            i = max;
            ++count;
        }
        return ++count;
    }

    // backtracking, slowly.
    int jump(vector<int>& nums)
    {
        vector<int> array;
        doJump(nums, 0, 0, array);
        int min = 0x7fffffff;
        for (int i = 0; i < array.size(); ++i)
        {
            if (array[i] < min)
            {
                min = array[i];
            }
        }
        return min;
    }

    void doJump(vector<int>& nums, int index, int count, vector<int>& array)
    {
        if (index == nums.size() - 1)
        {
            array.push_back(count);
            return;
        }
        if (index > nums.size() - 1)
        {
            return;
        }
        for (int i = 1; i <= nums[index]; ++i)
        {
            doJump(nums, index + i, count + 1, array);
        }
    }
};
