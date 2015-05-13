/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/


#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int> > result;
        if (nums.size() < 3)
        {
            return result;
        }
        sort(nums.begin(), nums.end());
        if (nums.front() > 0 || nums.back() < 0)
        {
            return result;
        }
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int pivot = i + 1;
            int end = nums.size() - 1;
            while (pivot < end)
            {
                int sum = nums[i] + nums[pivot] + nums[end];
                if (sum == 0)
                {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[pivot]);
                    v.push_back(nums[end]);
                    result.push_back(v);
                    while (pivot < end && nums[pivot] == v[1])
                    {
                        ++pivot;
                    }
                    while (pivot < end && nums[end - 1] == v[2])
                    {
                        --end;
                    }
                }
                else if (sum < 0)
                {
                    ++pivot;
                }
                else
                {
                    --end;
                }
            }
            while (i < nums.size() - 2 && nums[i] == nums[i + 1])
            {
                ++i;
            }
        }
        return result;
    }
};
