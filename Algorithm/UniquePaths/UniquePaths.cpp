/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time.
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    // DP solution, matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1]
    int uniquePaths(int m, int n)
    {
        vector<int> line(m, 0);
        vector<vector<int> > matrix(n, line);
        for (int i = 0; i < m; ++i)
        {
            matrix[0][i] = 1;
        }
        for (int i = 0; i < n; ++i)
        {
            matrix[i][0] = 1;
        }
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
        }
        return matrix[n - 1][m - 1];
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%d\n", s.uniquePaths(20, 20));
    return 0;
}
