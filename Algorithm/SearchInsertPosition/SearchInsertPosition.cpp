/*
Given a sorted array and a target value, return the index if the target is found.
If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int begin = 0;
        int end = nums.size() - 1;
        while (begin <= end)
        {
            int index = (begin + end + 1) / 2;
            if (target == nums[index])
            {
                return index;
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
        return begin;
    }
};

int main(int argc, char* argv[])
{
    vector<int> array = {1, 3, 5 ,7};
    Solution s;
    printf("%d\n", s.searchInsert(array, 0));
    printf("%d\n", s.searchInsert(array, 2));
    printf("%d\n", s.searchInsert(array, 3));
    printf("%d\n", s.searchInsert(array, 9));
    return 0;
}
