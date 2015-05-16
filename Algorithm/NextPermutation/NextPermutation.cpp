/*
Implement next permutation, which rearranges numbers into the lexicographically next
greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order
(ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are
in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        if (nums.size() <= 1)
        {
            return;
        }
        for (int prev = nums.size() - 2; prev >= 0; --prev)
        {
            int index = prev;
            int val = 0x7fffffff;
            for (int last = prev + 1; last < nums.size(); ++last)
            {
                if (nums[last] > nums[prev] && nums[last] < val)
                {
                    index = last;
                    val = nums[last];
                }
            }
            if (index != prev)
            {
                std::swap(nums[prev], nums[index]);
                std::sort(nums.begin() + prev + 1, nums.end());
                return;
            }
        }
        std::sort(nums.begin(), nums.end());
    }
};

int main(int argc, char* argv[])
{
    vector<int> v = {1, 3, 2};
    Solution().nextPermutation(v);
    for (auto i : v)
    {
        printf("%d\n", i);
    }
    return 0;
}
