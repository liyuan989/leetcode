/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool search(vector<int>& nums, int target)
    {
        if (nums.empty())
        {
            return false;
        }
        int pivot = findPivot(nums);
        if (pivot >= 0 && target < nums[0])
        {
            return search(nums, pivot, nums.size() - 1, target);
        }
        else if (pivot >= 0 && target >= nums[0])
        {
            return search(nums, 0, pivot - 1, target);
        }
        else
        {
            return search(nums, 0, nums.size() - 1, target);
        }
    }

    int findPivot(vector<int>& nums)
    {
        int prev = 0;
        int last = nums.size() - 1;
        while (prev <= last)
        {
            int pivot = prev + (last - prev + 1) / 2;
            if (pivot > 0 && nums[pivot] < nums[pivot - 1])
            {
                return pivot;
            }
            else if (nums[pivot] < nums[0])
            {
                last = pivot - 1;
            }
            else if (nums[pivot] > nums[0])
            {
                prev = pivot + 1;
            }
            else
            {
                if (nums[0] == nums.back())
                {
                    int index1 = pivot;
                    int index2 = pivot;
                    while (index1 > 0 && index2 < nums.size() - 1)
                    {
                        if (nums[index1] == nums[0])
                        {
                            --index1;
                        }
                        if (nums[index2] == nums[0])
                        {
                            ++index2;
                        }
                    }
                    if (index1 == 0)
                    {
                        prev = pivot + 1;
                    }
                    else
                    {
                        last = pivot - 1;
                    }
                }
                else
                {
                    prev = pivot + 1;
                }
            }
        }
        return -1;
    }

    bool search(vector<int>& nums, int start, int end, int target)
    {
        while (start <= end)
        {
            int index = start + (end - start + 1) / 2;
            if (nums[index] == target)
            {
                return true;
            }
            else if (target < nums[index])
            {
                end = index - 1;
            }
            else
            {
                start = index + 1;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    vector<int> array = {0,0,0};
    Solution s;
    printf("%d\n", s.search(array, 1));
    return 0;
}
