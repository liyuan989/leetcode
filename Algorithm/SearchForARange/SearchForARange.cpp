/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> result(2, -1);
        result[0] = getFirst(nums, target);
        result[1] = getLast(nums, target);
        return result;
    }

    int getFirst(vector<int>& nums, int target)
    {
        int begin = 0;
        int end = nums.size() - 1;
        while (begin <= end)
        {
            int index = (begin + end + 1) / 2;
            if (target == nums[index])
            {
                if (index == 0 || nums[index - 1] < nums[index])
                {
                    return index;
                }
                else
                {
                    end = index - 1;
                }
            }
            else if (target < nums[index])
            {
                end = index - 1;
            }
            else
            {
                begin = index + 1;
            }
        }
        return -1;
    }

    int getLast(vector<int>& nums, int target)
    {
        int begin = 0;
        int end = nums.size() - 1;
        while (begin <= end)
        {
            int index = (begin + end + 1) / 2;
            if (target == nums[index])
            {
                if (index == nums.size() - 1 || nums[index + 1] > nums[index])
                {
                    return index;
                }
                else
                {
                    begin = index + 1;
                }
            }
            else if (target < nums[index])
            {
                end = index - 1;
            }
            else
            {
                begin = index + 1;
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[])
{
    vector<int> array = {5, 7, 7, 8, 8, 10};
    Solution s;
    vector<int>&& result = s.searchRange(array, 7);
    for (auto i : result)
    {
        printf("%d\n", i);
    }
    return 0;
}
