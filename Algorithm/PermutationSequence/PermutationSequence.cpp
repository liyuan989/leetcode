/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    // Time Limit Exceeded
    string getPermutation(int n, int k)
    {
        string base;
        base.reserve(n);
        for (int i = 1; i <= n; ++i)
        {
            base.push_back('0' + i);
        }
        string result;
        int count = 0;
        doPermutation(base, k, 0, count, result);
        return result;
    }

    bool doPermutation(string& base, int k, int index, int& count, string& result)
    {
        if (index == base.size())
        {
            ++count;
            if (count == k)
            {
                result = base;
                return true;
            }
            return false;
        }
        for (int i = index; i < base.size(); ++i)
        {
            std::swap(base[index], base[i]);
            std::sort(base.begin() + index + 1, base.end());
            if (doPermutation(base, k, index + 1, count, result))
            {
                return true;
            }
            std::sort(base.begin() + index, base.end());
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    string&& result = s.getPermutation(3, 5);
    printf("%s\n", result.c_str());
    return 0;
}
