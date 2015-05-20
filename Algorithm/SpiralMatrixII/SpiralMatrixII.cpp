/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<vector<int> > generateMatrix(int n)
    {
        vector<int> v(n);
        vector<vector<int> > result(n, v);
        int val = 1;
        int row = 0;
        int column = 0;
        while (row <= (n - 1) / 2 && column <= (n - 1) / 2)
        {
            for (int i = column; i < n - column; ++i)
            {
                result[row][i] = val;
                ++val;
            }
            for (int i = row + 1; i < n - row; ++i)
            {
                result[i][n - column - 1] = val;
                ++val;
            }
            for (int i = n - column - 2; i >= column && n - row - 1 > row ; --i)
            {
                result[n - row - 1][i] = val;
                ++val;
            }
            for (int i = n - row - 2; i > row && n - column - 1 > column ; --i)
            {
                result[i][column] = val;
                ++val;
            }
            ++row;
            ++column;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<vector<int> >&& result = s.generateMatrix(5);
    for (auto vec : result)
    {
        for (auto i : vec)
        {
            printf("%-3d ", i);
        }
        printf("\n");
    }
    return 0;
}
