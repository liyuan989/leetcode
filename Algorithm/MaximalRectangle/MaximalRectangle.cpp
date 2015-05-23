/*
Given a 2D binary matrix filled with 0's and 1's,
find the largest rectangle containing all ones and return its area
*/

#include <algorithm>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char> >& matrix)
    {
        srand(time(NULL));
        if (rand() & 1)
        {
            return maximalRectangle_dp(matrix);
        }
        else
        {
            return maximalRectangle_histogram(matrix);
        }
    }

    // DP solution, which learned from https://leetcode.com/discuss/20240/share-my-dp-solution
    //
    // All the 3 variables left, right, and height can be determined by the information from previous row,
    // and also information from the current row. So it can be regarded as a DP solution. The transition
    // equations are:
    // left(i,j) = max(left(i-1,j), curleft), curleft can be determined from the current row
    // right(i,j) = min(right(i-1,j), curright), curright can be determined from the current row
    // height(i,j) = height(i-1,j) + 1, if matrix[i][j]=='1'
    // height(i,j) = 0, if matrix[i][j]=='0'
    //
    // example:
    // 0 0 0 1 0 0 0
    // 0 0 1 1 1 0 0
    // 0 1 1 1 1 1 0
    //
    // The vector "left" and "right" from row 0 to row 2 are as follows
    //
    // row 0:
    //
    // left:   0 0 0 3 0 0 0
    // right:  7 7 7 4 7 7 7
    // height: 0 0 0 1 0 0 0
    //
    // row 1:
    //
    // left:   0 0 2 3 2 0 0
    // right:  7 7 5 4 5 7 7
    // height: 0 0 1 2 1 0 0
    //
    // row 2:
    //
    // left:   0 1 2 3 2 1 0
    // right:  7 6 5 4 5 6 7
    // height: 0 1 2 3 2 1 0
    //
    // The array "left" is computing the left boundary. Take (i,j)=(1,3) for example. On current row 1,
    // the left boundary is at j=2. However, because matrix[1][3] is 1, you need to consider the left
    // boundary on previous row as well, which is 3. So the real left boundary at (1,3) is 3.
    int maximalRectangle_dp(vector<vector<char> >& matrix)
    {
        if (matrix.empty())
        {
            return 0;
        }
        int row_size = matrix.size();
        int column_size = matrix[0].size();
        vector<int> left(column_size, 0);
        vector<int> right(column_size, column_size);
        vector<int> height(column_size, 0);
        int result = 0;
        for (int i = 0; i < row_size; ++i)
        {
            int current_left = 0;
            int current_right = column_size;
            for (int j = 0; j < column_size; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    ++height[j];
                }
                else
                {
                    height[j] = 0;
                }
            }
            for (int j = 0; j < column_size; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    left[j] = std::max(current_left, left[j]);
                }
                else
                {
                    left[j] = 0;
                    current_left = j + 1;
                }
            }
            for (int j = column_size - 1; j >= 0; --j)
            {
                if (matrix[i][j] == '1')
                {
                    right[j] = std::min(current_right, right[j]);
                }
                else
                {
                    right[j] = column_size;
                    current_right = j;
                }
            }
            for (int j = 0; j < column_size; ++j)
            {
                result = std::max((right[j] - left[j]) * height[j], result);
            }
        }
        return result;
    }

    // This solution is based on preblem "Largest Rectangle in Histogram".
    // We can construct a "Histogram height vector" to convert this problem.
    //
    // example:
    // 1 1 0 1      1 1 0 1
    // 1 1 0 1  =>  2 2 0 2
    // 1 1 1 1      3 3 1 3
    //
    // The every new height matrix row means current row and previous rows constitute a Histogram.
    // So the problem is converted to solve "Largest Rectangle in Histogram" to every row in new height matrix,
    // maxmimal of which is the result.
    int maximalRectangle_histogram(vector<vector<char> >& matrix)
    {
        if (matrix.empty())
        {
            return 0;
        }
        int row_size = matrix.size();
        int column_size = matrix[0].size();
        vector<vector<int> > height(row_size, vector<int>(column_size, 0));
        int result = 0;
        for (int j = 0; j < column_size; ++j)
        {
            if (matrix[0][j] == '1')
            {
                height[0][j] = 1;
            }
        }
        for (int i = 1; i < row_size; ++i)
        {
            for (int j = 0; j < column_size; ++j)
            {
                if (matrix[i][j] == '1')
                {
                      height[i][j] = height[i - 1][j] + 1;
                }
                else
                {
                    height[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < row_size; ++i)
        {
            result = std::max(getLargestRectangleInHistograms(height[i]), result);
        }
        return result;
    }

    int getLargestRectangleInHistograms(vector<int>& height)
    {
        if (height.empty())
        {
            return 0;
        }
        int size = height.size();
        stack<int> stack;
        int result = 0;
        for (int i = 0; i < size;)
        {
            if (stack.empty() || height[i] >= height[stack.top()])
            {
                stack.push(i);
                ++i;
            }
            else
            {
                int index = stack.top();
                stack.pop();
                int area = stack.empty() ? height[index] * i : height[index] * (i - stack.top() - 1);
                result = std::max(area, result);
            }
        }
        while (!stack.empty())
        {
            int index = stack.top();
            stack.pop();
            int area = stack.empty() ? height[index] * size : height[index] * (size - stack.top() - 1);
            result = std::max(area, result);
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<vector<char> > matrix =
    {
        {'1', '1', '0', '1'},
        {'1', '1', '0', '1'},
        {'1', '1', '1', '1'},
    };
    Solution s;
    for (int i = 0; i < 10; ++i)
    {
        printf("%d\n", s.maximalRectangle(matrix));
    }
    return 0;
}
