/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

#include <vector>
#include <string>
#include <assert.h>
#include <string.h>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char> >& board)
    {
        return checkRow(board) && checkColomn(board) && checkBox(board);
    }

    bool checkRow(vector<vector<char> >& board)
    {
        for (int i = 0; i < 9; ++i)
        {
            int hash[256];
            memset(hash, 0, sizeof(hash));
            for (int j = 0; j < 9; ++j)
            {
                ++hash[board[i][j]];
                if (board[i][j] != '.' && hash[board[i][j]] > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkColomn(vector<vector<char> >& board)
    {
        for (int j = 0; j < 9; ++j)
        {
            int hash[256];
            memset(hash, 0, sizeof(hash));
            for (int i = 0; i < 9; ++i)
            {
                ++hash[board[i][j]];
                if (board[i][j] != '.' && hash[board[i][j]] > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkBox(vector<vector<char> >& board)
    {
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                if (!checkOneBox(board, i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool checkOneBox(vector<vector<char> >& board, int row, int colomn)
    {
        int hash[256];
        memset(hash, 0, sizeof(hash));
        for (int i = row; i < row + 3; ++i)
        {
            for (int j = colomn; j < colomn + 3; ++j)
            {
                ++hash[board[i][j]];
                if (board[i][j] != '.' && hash[board[i][j]] > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<char> > board(9);
    board[0] = {'.', '8', '7', '6', '5', '4', '3', '2', '1'};
    board[1] = {'2', '.', '.', '.', '.', '.', '.', '.', '.'};
    board[2] = {'3', '.', '.', '.', '.', '.', '.', '.', '.'};
    board[3] = {'4', '.', '.', '.', '.', '.', '.', '.', '.'};
    board[4] = {'5', '.', '.', '.', '.', '.', '.', '.', '.'};
    board[5] = {'6', '.', '.', '.', '.', '.', '.', '.', '.'};
    board[6] = {'7', '.', '.', '.', '.', '.', '.', '.', '.'};
    board[7] = {'8', '.', '.', '.', '.', '.', '.', '.', '.'};
    board[8] = {'9', '.', '.', '.', '.', '.', '.', '.', '.'};
    Solution s;
    assert(s.isValidSudoku(board));
    return 0;
}
