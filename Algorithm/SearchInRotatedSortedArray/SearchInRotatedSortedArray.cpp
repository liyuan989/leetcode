/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    // nlog(n)
    int search(vector<int>& nums, int target)
    {
        if (nums.empty())
        {
            return -1;
        }
        int begin = 0;
        int end = nums.size() - 1;
        while (begin <= end)
        {
            int index = (begin + end + 1) /2;
            if (target == nums[index])
            {
                return index;
            }
            if (nums[index] < nums[begin])
            {
                if (target > nums[index] && target < nums[begin])
                {
                    begin = index + 1;
                }
                else
                {
                    end = index -1;
                }
            }
            else
            {
                if (target < nums[index] && target >= nums[begin])
                {
                    end = index - 1;
                }
                else
                {
                    begin = index + 1;
                }
            }
        }
        return -1;
    }

    // little slower, nlog(n) too.
    int search(vector<int>& nums, int target)
    {
        if (nums.empty())
        {
            return -1;
        }
        if (nums.size() == 1)
        {
            return nums[0] == target ? 0 : -1;
        }
        int pivot = findPivot(nums);
        if (pivot != -1)
        {
            if (target < nums[0])
            {
                return binarySearch(nums, pivot, nums.size() - 1, target);
            }
            else
            {
                return binarySearch(nums, 0, pivot - 1, target);
            }
        }
        else
        {
            return binarySearch(nums, 0, nums.size() - 1, target);
        }
    }

    int findPivot(vector<int>& nums)
    {
        for (int begin = 0, end = nums.size() - 1; begin < end;)
        {
            int index = (begin + end + 1) / 2;
            if (nums[index - 1] > nums[index ])
            {
                return index;
            }
            else
            {
                if (nums[index] > nums[0])
                {
                    begin = index;
                }
                else
                {
                    end = index;
                }
            }
        }
        return -1;
    }

    int binarySearch(vector<int>& num, int begin, int end, int target)
    {
        while (begin <= end)
        {
            int index = (begin + end + 1) / 2;
            if (target == num[index])
            {
                return index;
            }
            else if (target < num[index])
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
    vector<int> v = {3, 1};
    Solution s;
    printf("%d\n", s.search(v, 3));
    return 0;
}
