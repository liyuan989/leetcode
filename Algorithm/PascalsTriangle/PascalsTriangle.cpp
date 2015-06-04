/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<vector<int> > generate(int num_rows)
    {
        vector<vector<int> > result;
        if (num_rows <= 0)
        {
            return result;
        }
        result.push_back(vector<int>(1, 1));
        if (num_rows == 1)
        {
            return result;
        }
        result.push_back(vector<int>(2, 1));
        if (num_rows == 2)
        {
            return result;
        }
        for (int i = 2; i < num_rows; ++i)
        {
            vector<int> array;
            array.push_back(1);
            for (int j = 1; j < i; ++j)
            {
                array.push_back(result.back()[j - 1] + result.back()[j]);
            }
            array.push_back(1);
            result.push_back(array);
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<vector<int> >&& result = s.generate(5);
    for (auto vec : result)
    {
        for (auto i : vec)
        {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
