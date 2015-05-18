/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/

#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    void solveSudoku(vector<vector<char> >& board)
    {
        doSolve(board, 0, 0);
    }

    bool doSolve(vector<vector<char> >& board, int row, int column)
    {
        if (row >= 9)
        {
            return true;
        }
        if (board[row][column] != '.')
        {
            if (column == board.size() - 1)
            {
                return doSolve(board, row + 1, 0);
            }
            else
            {
                return doSolve(board, row, column + 1);
            }
        }
        for (int i = 0; i < 9; ++i)
        {
            if (check(board, row, column, '1' + i))
            {
                board[row][column] = '1' + i;
                if (column == board.size() - 1 && doSolve(board, row + 1, 0))
                {
                    return true;
                }
                else if(column < board.size() - 1 && doSolve(board, row, column + 1))
                {
                    return true;
                }
                board[row][column] = '.';
            }
        }
        return false;

    }

    bool check(vector<vector<char> >& board, int row, int column, char val)
    {
        for (int i = 0; i < 9; ++i)
        {
            if (board[row][i] == val)
            {
                return false;
            }
        }
        for (int i = 0; i < 9; ++i)
        {
            if (board[i][column] == val)
            {
                return false;
            }
        }
        for (int i = 0; i < 9 ; ++i)
        {
            int r = (row / 3) * 3 + i / 3;
            int c = (column / 3) * 3 + i % 3;
            if (board[r][c] == val)
            {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<char> > board(9);
    board[0] = {'.', '.', '9', '7', '4', '8', '.', '.', '.'};
    board[1] = {'7', '.', '.', '.', '.', '.', '.', '.', '.'};
    board[2] = {'.', '2', '.', '1', '.', '9', '.', '.', '.'};
    board[3] = {'.', '.', '7', '.', '.', '.', '2', '4', '.'};
    board[4] = {'.', '6', '4', '.', '1', '.', '5', '9', '.'};
    board[5] = {'.', '9', '8', '.', '.', '.', '3', '.', '.'};
    board[6] = {'.', '.', '.', '8', '.', '3', '.', '2', '.'};
    board[7] = {'.', '.', '.', '.', '.', '.', '.', '.', '6'};
    board[8] = {'.', '.', '.', '2', '7', '5', '9', '.', '.'};
    Solution s;
    s.solveSudoku(board);
    for (auto v : board)
    {
        for (auto i : v)
        {
            printf("%c ", i);
        }
        printf("\n");
    }
    return 0;
}
