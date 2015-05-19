/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int> >& matrix)
    {
        vector<vector<int> > origin = matrix;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix.size(); ++j)
            {
                matrix[i][j] = origin[matrix.size() - j - 1][i];
            }
        }
    }

    // in-place, O(1) space.
    void rotate(vector<vector<int> >& matrix)
    {
        int size = matrix.size();
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size - i; ++j)
            {
                std::swap(matrix[i][j], matrix[size - j - 1][size - i - 1]);
            }
        }
        std::reverse(matrix.begin(), matrix.end());
    }
};
