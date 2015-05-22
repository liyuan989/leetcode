/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<vector<int> > subsets(vector<int>& nums)
    {
        vector<vector<int> > result;
        result.push_back(vector<int>());
        if (nums.empty())
        {
            return result;
        }
        std::sort(nums.begin(), nums.end());
        vector<int> group;
        for (int i = 1; i <= nums.size(); ++i)
        {
            solve(nums, 0, i, group, result);
        }
        return result;
    }

    void solve(vector<int>& nums, int index, int k, vector<int>& group, vector<vector<int> >& result)
    {
        if (k == 0)
        {
            result.push_back(group);
            return;
        }
        for (int i = index; i < nums.size(); ++i)
        {
            group.push_back(nums[i]);
            solve(nums, i + 1, k - 1, group, result);
            group.pop_back();
        }
    }
};

int main(int argc, char* argv[])
{
    vector<int> array = {1, 2, 3};
    Solution s;
    vector<vector<int> >&& result = s.subsets(array);
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
