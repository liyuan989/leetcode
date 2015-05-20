/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix)
    {
        vector<int> result;
        if (matrix.empty())
        {
            return result;
        }
        int row_size = matrix.size();
        int column_size = matrix[0].size();
        result.reserve(row_size * column_size);
        int row = 0;
        int column = 0;
        while (row <= (row_size - 1) / 2 && column <= (column_size - 1) / 2)
        {
            for (int i = column; i < column_size - column ; ++i)
            {
                result.push_back(matrix[row][i]);
            }
            for (int i = row + 1; i < row_size - row ; ++i)
            {
                result.push_back(matrix[i][column_size - column - 1]);
            }
            for (int i = column_size - column - 2; i >= column && row_size - row - 1 > row; --i)
            {
                result.push_back(matrix[row_size - row - 1][i]);
            }
            for (int i = row_size - row - 2; i > row && column_size - column - 1 > column; --i)
            {
                result.push_back(matrix[i][column]);
            }
            ++row;
            ++column;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int> > vec =
    {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
    };
    Solution s;
    vector<int>&& array = s.spiralOrder(vec);
    for (int i = 0; i < array.size(); ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
