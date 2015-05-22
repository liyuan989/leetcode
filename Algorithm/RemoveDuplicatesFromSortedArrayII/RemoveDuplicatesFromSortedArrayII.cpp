/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3.
It doesn't matter what you leave beyond the new length.
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int prev = 0;
        int last = 0;
        int count = 0;
        int current = 0;
        while (last < nums.size())
        {
            if (current != nums[last])
            {
                current = nums[last];
                count = 1;
            }
            else
            {
                ++count;
            }
            if (count > 2)
            {
                ++last;
            }
            else
            {
                nums[prev] = nums[last];
                ++last;
                ++prev;
            }
        }
        nums.erase(nums.begin() + prev, nums.end());
        return nums.size();
    }
};

int main(int argc, char* argv[])
{
    vector<int> array = {1,1,1,2,2,3};
    Solution s;
    printf("%d\n", s.removeDuplicates(array));
    for (int i = 0; i < array.size(); ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
