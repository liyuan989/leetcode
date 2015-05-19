/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int> > permute(vector<int>& nums)
    {
        vector<vector<int> > result;
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
            std::swap(nums[index], nums[i]);
            doPermutation(nums, index + 1, result);
            std::swap(nums[index], nums[i]);
        }
    }
};

int main(int argc, char* argv[])
{
    vector<int> array = {1, 2, 3};
    Solution s;
    vector<vector<int> >&& result = s.permute(array);
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
