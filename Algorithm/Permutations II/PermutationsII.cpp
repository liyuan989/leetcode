/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<vector<int> > permuteUnique(vector<int>& nums)
    {
        vector<vector<int> > result;
        std::sort(nums.begin(), nums.end());
        doPermutation(nums, 0, result);
        return result;
    }

    void doPermutation(vector<int>& nums, int index, vector<vector<int> >& result)
    {
        if (index == nums.size())
        {
            result.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); ++i)
        {
            if (i != index && nums[i - 1] == nums[i])
            {
                continue;
            }
            std::swap(nums[index], nums[i]);
            std::sort(nums.begin() + index + 1, nums.end());
            doPermutation(nums, index + 1, result);
            std::sort(nums.begin() + index, nums.end());
        }
    }
};

int main(int argc, char* argv[])
{
    vector<int> array = {0,1,0,0,9};
    Solution s;
    vector<vector<int> >&& result = s.permuteUnique(array);
    for (auto vec : result)
    {
        for (auto i : vec)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
