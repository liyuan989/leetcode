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
    // mathematics method, http://en.wikipedia.org/wiki/Gray_code
    vector<int> grayCode(int n)
    {
        vector<int> result;
        if (n < 0)
        {
            return result;
        }
        int size = 1 << n;
        result.reserve(size);
        for (int i = 0; i < size; ++i)
        {
            result.push_back((i >> 1) ^ i);
        }
        return result;
    }

    // if n = 3 :
    //
    // 000 - 0
    // 001 - 1
    // 011 - 3
    // 010 - 2
    // 110 - 6
    // 111 - 7
    // 101 - 5
    // 100 - 4
    //
    // what to do is only to make or operation for (1 << (n - 1)) | gray(n - 1).
    // gray(n) means all n bit gray codes.
    vector<int> grayCode_2(int n)
    {
        vector<int> result;
        if (n < 0)
        {
            return result;
        }
        result.push_back(0);
        if (n == 0)
        {
            return result;
        }
        result.push_back(1);
        for (int k = 2; k <= n; ++k)
        {
            int size = result.size();
            for (int i = size - 1; i >= 0; --i)
            {
                result.push_back(result[i] | (1 << (k - 1)));
            }
        }
        return result;
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
    printf("------------\n");
    result = s.grayCode_2(2);
    for (auto i : result)
    {
        printf("%d\n", i);
    }
    return 0;
}
