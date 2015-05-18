/*
Given a set of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7]
[2, 2, 3]
*/

#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int> > result;
        vector<int> array;
        std::sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, 0, array, result);
        return result;
    }

    void solve(vector<int>& candidates, int target, int sum, int index,
               vector<int>& array, vector<vector<int> >& result)
    {
        for (int i = index; i < candidates.size(); ++i)
        {
            if (sum + candidates[i] > target)
            {
                return;
            }
            array.push_back(candidates[i]);
            if (sum + candidates[i] == target)
            {
                result.push_back(array);
            }
            solve(candidates, target, sum + candidates[i], i, array, result);
            array.pop_back();
        }
    }
};

int main(int argc, char* argv[])
{
    vector<int> v = {1, 2};
    Solution s;
    vector<vector<int> >&& result = s.combinationSum(v, 2);
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
