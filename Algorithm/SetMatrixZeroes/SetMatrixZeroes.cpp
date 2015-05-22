/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

#include <vector>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int> >& matrix)
    {
        if (matrix.empty())
        {
            return;
        }
        int row_size = matrix.size();
        int column_size = matrix[0].size();
        vector<int> row(row_size, 0);
        vector<int> column(column_size, 0);
        for (int i = 0; i < row_size; ++i)
        {
            for (int j = 0; j < column_size; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 1;
                    column[j] = 1;
                }
            }
        }
        for (int i = 0; i < row_size; ++i)
        {
            if (row[i] == 1)
            {
                for (int j = 0; j < column_size; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
            else
            {
                for (int j = 0; j < column_size; ++j)
                {
                    if (column[j] == 1)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
    }
};
