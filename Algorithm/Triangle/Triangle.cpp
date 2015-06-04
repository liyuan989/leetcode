/*
Given a triangle, find the minimum path sum from top to bottom.
Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11
(i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space,
where n is the total number of rows in the triangle.
*/

#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    // DP solution
    //
    // dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j]
    int minimumTotal(vector<vector<int> >& triangle)
    {
        vector<int> min_len(triangle.back());
        int size = triangle.size();
        for (int i = size - 2; i >= 0; --i)
        {
            for (int j = 0; j <= i; ++j)
            {
                min_len[j] = std::min(min_len[j], min_len[j + 1]) + triangle[i][j];
            }
        }
        return min_len[0];
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int> > vec =
    {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3},
    };
    Solution s;
    printf("%d\n", s.minimumTotal(vec));
    return 0;
}
