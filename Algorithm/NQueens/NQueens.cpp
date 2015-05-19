/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that
 no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement,
where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<string> > solveNQueens(int n)
    {
        int* column = new int[n];
        for (int i = 0; i < n; ++i)
        {
            column[i] = i;
        }
        vector<vector<string> > result;
        permutation(column, n, 0, result);
        delete column;
        return result;
    }

    void permutation(int* column, int size, int index, vector<vector<string> >& result)
    {
        if (index == size)
        {
            string s(size, '.');
            vector<string> one(size, s);
            for (int i = 0; i < size; ++i)
            {
                one[i][column[i]] = 'Q';
            }
            result.push_back(one);
            return;
        }
        for (int i = index; i < size; ++i)
        {
            std::swap(column[index], column[i]);
            if (check(column, index))
            {
                permutation(column, size, index + 1, result);
            }
            std::swap(column[index], column[i]);
        }
    }

    bool check(int* column, int index)
    {
        for (int i = 0; i < index; ++i)
        {
            if (index - i == column[index] - column[i] || i + column[i] == index + column[index])
            {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<vector<string> >&& result = s.solveNQueens(8);
    printf("%d\n", result.size());
    for (int i = 0; i < result.size(); ++i)
    {
        printf("The %d solution:\n", i + 1);
        for (int j = 0; j < result[i].size(); ++j)
        {
            printf("%s\n", result[i][j].c_str());
        }
        printf("----------------\n");
    }
    return 0;
}
