/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell,
where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char> >& board, const string& word)
    {
        if (board.empty() || word.empty())
        {
            return false;
        }
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                    if (word.size() == 1)
                    {
                        return true;
                    }
                    if (search(board, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char> >& board, const string& word, int row, int column, int index)
    {
        if (index == word.size())
        {
            return true;
        }
        if (board[row][column] != word[index])
        {
            return false;
        }
        char tmp = board[row][column];
        board[row][column] = 0;
        bool match = false;
        if (row > 0)
        {
            match = search(board, word, row - 1, column, index + 1);
        }
        if (!match && row < board.size() - 1)
        {
            match = search(board, word, row + 1, column, index + 1);
        }
        if (!match && column > 0)
        {
            match = search(board, word, row, column - 1, index + 1);
        }
        if (!match && column < board[0].size() - 1)
        {
            match = search(board, word, row, column + 1, index + 1);
        }
        board[row][column] = tmp;
        return match;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<char> > board =
    {
      {'A','B','C','E'},
      {'S','F','C','S'},
      {'A','D','E','E'},
    };
    Solution s;
    printf("%d\n", s.exist(board, "ABCCED"));
    printf("%d\n", s.exist(board, "SEE"));
    printf("%d\n", s.exist(board, "ABCB"));
    return 0;
}
