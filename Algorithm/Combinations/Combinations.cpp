/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<vector<int> > combine(int n, int k)
    {
        vector<vector<int> > result;
        if (n <= 0 || k <= 0 || k > n)
        {
            return result;
        }
        vector<int> base;
        base.reserve(n);
        for (int i = 0; i < n; ++i)
        {
            base.push_back(i + 1);
        }
        vector<int> group;
        group.reserve(k);
        solve(base, 0, k, group, result);
        return result;
    }

    void solve(vector<int>& base, int index, int k, vector<int>& group, vector<vector<int> >& result)
    {
        if (k == 0)
        {
            result.push_back(group);
            return;
        }
        for (int i = index; i < base.size(); ++i)
        {
            group.push_back(base[i]);
            solve(base, i + 1, k - 1, group, result);
            group.pop_back();
        }
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<vector<int> >&& result = s.combine(4, 2);
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
