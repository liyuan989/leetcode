/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
    [3, 0, 1, 4, 2],
    [5, 6, 3, 2, 1],
    [1, 2, 0, 1, 5],
    [4, 1, 0, 1, 7],
    [1, 0, 3, 0, 5]
]
          
sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12

Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

#include <vector>
#include <iostream>

class NumMatrix {
public:
    NumMatrix(std::vector<std::vector<int>> matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        dp_.resize(m, std::vector<int>(n));
        dp_[0][0] = matrix[0][0];
        for (int i = 1; i < n; ++i) {
            dp_[0][i] += dp_[0][i - 1] + matrix[0][i];
        }
        for (int i = 1; i < m; ++i) {
            int row_sum = 0;
            for (int j = 0; j < n; ++j) {
               row_sum += matrix[i][j];
               dp_[i][j] += dp_[i - 1][j] + row_sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) {
            return dp_[row2][col2];
        } else if (row1 == 0) {
            return dp_[row2][col2] - dp_[row2][col1 - 1];
        } else if (col1 == 0) {
            return dp_[row2][col2] - dp_[row1 - 1][col2];
        } else {
            return dp_[row2][col2] - dp_[row1 - 1][col2] - dp_[row2][col1 - 1] + dp_[row1 - 1][col1 - 1];
        }
    }

private:
    std::vector<std::vector<int>> dp_;
};

int main(int argc, const char* argv[]) {
    std::vector<std::vector<int>> matrix = {
        {3,0,1,4,2},
        {5,6,3,2,1},
        {1,2,0,1,5},
        {4,1,0,1,7},
        {1,0,3,0,5},
    };
    NumMatrix m(matrix);    
    return 0;
}

/*
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

