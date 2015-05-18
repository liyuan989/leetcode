/*
Given a collection of candidate numbers (C) and a target number (T),
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
        vector<int> array;
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
            if (i > index && candidates[i - 1] == candidates[i])
            {
                continue;
            }
            array.push_back(candidates[i]);
            if (sum + candidates[i] == target)
            {
                result.push_back(array);
            }
            solve(candidates, target, sum + candidates[i], i + 1, array, result);
            array.pop_back();
        }
    }
};

int main(int argc, char* argv[])
{
    vector<int> array = {1, 1};
    Solution s;
    vector<vector<int> >&& result = s.combinationSum2(array, 2);
    for (auto v : result)
    {
        for (auto i : v)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
