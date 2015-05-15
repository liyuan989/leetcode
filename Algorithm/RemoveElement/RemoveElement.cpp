/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        nums.erase(std::remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }

    // no using STL.
    int removeElement(vector<int>& nums, int val)
    {
        int prev = -1;
        int back = 0;
        while (back < nums.size())
        {
            if (nums[back] != val)
            {
                ++prev;
                nums[prev] = nums[back];
            }
            ++back;
        }
        return ++prev;
    }
};
