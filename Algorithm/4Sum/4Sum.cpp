/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/

#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target)
    {
        vector<vector<int> > result;
        if (nums.size() < 4)
        {
            return result;
        }
        std::sort(nums.begin(), nums.end());
        int last = nums.size() - 1;
        for (int i = 0; i < last - 2; ++i)
        {
            for (int j = i + 1; j < last - 1; ++j)
            {
                int pivot = j + 1;
                int end = nums.size() - 1;
                while (pivot < end)
                {
                    int sum = nums[i] + nums[j] + nums[pivot] + nums[end];
                    if (sum == target)
                    {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[pivot]);
                        v.push_back(nums[end]);
                        result.push_back(v);
                        while (pivot < end && nums[pivot] == v[2])
                        {
                            ++pivot;
                        }
                        while (pivot < end && nums[end] == v[3])
                        {
                            --end;
                        }
                    }
                    else if (sum < target)
                    {
                        ++pivot;
                    }
                    else
                    {
                        --end;
                    }
                }
                while (j < last - 1 && nums[j] == nums[j + 1])
                {
                    ++j;
                }
            }
            while (i < last - 2 && nums[i] == nums[i + 1])
            {
                ++i;
            }
        }
        return result;
    }
};
