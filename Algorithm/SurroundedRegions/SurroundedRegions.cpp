/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

#include <vector>
#include <queue>
#include <iostream>

struct Node {
    int i;
    int j;

    Node(int x, int y) : i(x), j(y) {}
};

class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        size_t m = board.size();
        size_t n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (board[i][j] == 'O') {
                        bfs(board, i, j, m, n);
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '*') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    void bfs(std::vector<std::vector<char>>& board, int i, int j, int m, int n) {
        std::queue<Node> queue;
        queue.push(Node(i, j));
        board[i][j] = '*';
        while(!queue.empty()) {
            Node node = queue.front();
            queue.pop();
            if (node.i > 0 && board[node.i - 1][node.j] == 'O') {
                board[node.i - 1][node.j] = '*';
                queue.push(Node(node.i - 1, node.j));
            }
            if (node.i < m - 1 && board[node.i + 1][node.j] == 'O') {
                board[node.i + 1][node.j] = '*';
                queue.push(Node(node.i + 1, node.j));
            }
            if (node.j > 0 && board[node.i][node.j - 1] == 'O') {
                board[node.i][node.j - 1] = '*';
                queue.push(Node(node.i, node.j - 1));
            }
            if (node.j < n - 1 && board[node.i][node.j + 1] == 'O') {
                board[node.i][node.j + 1] = '*';
                queue.push(Node(node.i, node.j + 1));
            }
        }
    }
};

