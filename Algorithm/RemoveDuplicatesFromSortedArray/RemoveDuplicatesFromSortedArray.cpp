/*
Given a sorted array, remove the duplicates in place such that each element appear only once and
return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
*/

#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.size() < 2)
        {
            return nums.size();
        }
        int prev = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[prev] != nums[i])
            {
                ++prev;
                nums[prev] = nums[i];
            }
        }
        return ++prev;
    }

    // This solution is slower
    int removeDuplicates(vector<int>& nums)
    {
        int length = nums.size();
        for (int i = 0; i < nums.size(); ++i)
        {
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
            {
                nums.erase(nums.begin() + i);
                --length;
            }
        }
        return length;
    }
};
