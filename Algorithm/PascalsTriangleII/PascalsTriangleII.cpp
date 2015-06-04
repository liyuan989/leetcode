/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<int> getRow(int row_index)
    {
        vector<int> array(row_index + 1, 0);
        if (row_index < 0)
        {
            return vector<int>();
        }
        if (row_index == 0)
        {
            return vector<int>(1, 1);
        }
        array[0] = 1;
        for (int i = 1; i <= row_index; ++i)
        {
            int tmp = array[0];
            for (int j = 1; j < row_index; ++j)
            {
                int val = tmp;
                tmp = array[j];
                array[j] = val + array[j];
            }
            array[row_index] = 1;
        }
        return vector<int>(array.begin(), array.begin() + row_index + 1);
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int>&& result = s.getRow(4);
    for (auto i : result)
    {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
