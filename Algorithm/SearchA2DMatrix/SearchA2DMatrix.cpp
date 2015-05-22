/*
Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target)
    {
        int prev_row = 0;
        if (target >= matrix.back()[0])
        {
            prev_row = matrix.size() - 1;
        }
        else
        {
            int last_row = matrix.size() - 1;
            while (prev_row + 1 < last_row)
            {
                int pivot = (prev_row + last_row + 1) / 2;
                if (target == matrix[pivot][0])
                {
                    return true;
                }
                else if (target < matrix[pivot][0])
                {
                    last_row = pivot;
                }
                else
                {
                    prev_row = pivot;
                }
            }
        }
        int prev_column = 0;
        int last_column = matrix[prev_row].size() - 1;
        while (prev_column <= last_column)
        {
            int pivot = (prev_column + last_column + 1) / 2;
            if (target == matrix[prev_row][pivot])
            {
                return true;
            }
            else if (target < matrix[prev_row][pivot])
            {
                last_column = pivot - 1;
            }
            else
            {
                prev_column = pivot + 1;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<int> > matrix =
    {
      {1,   3,  5,  7},
      {10, 11, 16, 20},
      {23, 30, 34, 50},
    };
    Solution s;
    printf("%d\n", s.searchMatrix(matrix, 49));
    return 0;
}
