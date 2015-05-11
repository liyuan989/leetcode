/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int> > ret;
        if (nums.empty())
        {
            return ret;
        }
        sort(nums.begin(), nums.end());
        vector<int> array;
        makeVector(nums, ret, array, 0);
        return ret;
    }

    void makeVector(vector<int>& nums, vector<vector<int> >& ret, vector<int>& array, int begin)
    {
        ret.push_back(array);
        for (int i = begin; i < nums.size(); ++i)
        {
            if (i == begin || nums[i] != nums[i - 1])
            {
                array.push_back(nums[i]);
                makeVector(nums, ret, array, i + 1);
                array.pop_back();
            }
        }
    }
};
