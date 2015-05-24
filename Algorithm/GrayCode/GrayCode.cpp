/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code,
print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> result;
        if (n < 0)
        {
            return result;
        }
        vector<int> number;
        number.reserve(n);
        solve(number, n, result);
        return result;
    }

    void solve(vector<int>& number, int index, vector<int>& result)
    {
        if (index == 0)
        {
            int sum = 0;
            for (int i = number.size() - 1; i >= 0; --i)
            {
                sum = sum * 2 + number[i];
            }
            result.push_back(sum);
            return;
        }
        for (int i = 0; i < 2; ++i)
        {
            number.push_back(i);
            solve(number, index - 1, result);
            number.pop_back();
        }
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int>&& result = s.grayCode(2);
    for (auto i : result)
    {
        printf("%d\n", i);
    }
    return 0;
}
