/*
Given an array with n objects colored red, white or blue,
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's,
then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int index = partition(nums, 0, nums.size() - 1,  1);
        if (0 < index && index < nums.size())
        {
            partition(nums, 0, index, 0);
        }
    }

    int partition(vector<int>& nums, int start, int end, int val)
    {
        int prev = start;
        int last = end;
        while (true)
        {
            while (prev <= end && nums[prev] < val)
            {
                ++prev;
            }
            while (last >= start && nums[last] > val)
            {
                --last;
            }
            if (prev >= last)
            {
                break;
            }
            std::swap(nums[prev], nums[last]);
            ++prev;
        }
        return prev;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> v = {0,0};
    s.sortColors(v);
    for (auto i : v)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
