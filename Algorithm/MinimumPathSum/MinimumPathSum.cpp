/*
Given a m x n grid filled with non-negative numbers,
find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    // DP solution, matrix[i][j] = gird[i][j] + min(matrix[i - 1][j], matrix[i][j - 1])
    int minPathSum(vector<vector<int> >& grid)
    {
        if (grid.empty())
        {
            return 0;
        }
        int row = grid.size();
        int column = grid[0].size();
        vector<int> line(column, 0);
        vector<vector<int> > matrix(row, line);
        matrix[0][0] = grid[0][0];
        for (int i = 1; i < column; ++i)
        {
            matrix[0][i] = matrix[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < row; ++i)
        {
            matrix[i][0] = matrix[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < column; ++j)
            {
                int min = matrix[i - 1][j] < matrix[i][j - 1] ? matrix[i - 1][j] : matrix[i][j - 1];
                matrix[i][j] = grid[i][j] + min;
            }
        }
        return matrix[row - 1][column - 1];
    }
};
