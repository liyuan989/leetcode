/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

#include <algorithm>
#include <stdio.h>

class Solution
{
public:
    int totalNQueens(int n)
    {
        int* column = new int[n];
        for (int i = 0; i < n; ++i)
        {
            column[i] = i;
        }
        int count = 0;
        permutation(column, n, 0, count);
        delete column;
        return count;
    }

    void permutation(int* column, int size, int index, int& count)
    {
        if (index == size)
        {
            ++count;
            return;
        }
        for (int i = index; i < size; ++i)
        {
            std::swap(column[index], column[i]);
            if (check(column, index))
            {
                permutation(column, size, index + 1, count);
            }
            std::swap(column[index], column[i]);
        }
    }

    bool check(int* column, int index)
    {
        for (int i = 0; i < index; ++i)
        {
            if (i - index == column[i] - column[index] || i + column[i] == index + column[index])
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
    printf("%d\n", s.totalNQueens(8));
    return 0;
}
