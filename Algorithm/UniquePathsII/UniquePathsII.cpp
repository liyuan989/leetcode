/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    // DP solution, matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1]
    int uniquePathsWithObstacles(vector<vector<int> >& obstacle_grid)
    {
        if (obstacle_grid.empty())
        {
            return 0;
        }
        int row = obstacle_grid.size();
        int column = obstacle_grid[0].size();
        vector<int> line(column, 0);
        vector<vector<int> > matrix(row, line);
        for (int i = 0; i < column && obstacle_grid[0][i] != 1; ++i)
        {
            matrix[0][i] = 1;
        }
        for (int i = 0; i < row && obstacle_grid[i][0] != 1; ++i)
        {
            matrix[i][0] = 1;
        }
        for (int i = 1; i < row; ++i)
        {
            for (int j = 1; j < column; ++j)
            {
                if (obstacle_grid[i][j] == 1)
                {
                    continue;
                }
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
        }
        return matrix[row - 1][column - 1];
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<vector<int> > grid =
    {
      {0,0,0},
      {0,1,0},
      {0,0,0},
    };
    printf("%d\n", s.uniquePathsWithObstacles(grid));
    return 0;
}
