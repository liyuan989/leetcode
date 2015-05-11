/*
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
*/

#include <assert.h>
#include <string>

using namespace std;

class Solution
{
public:
    int titleToNumber(string s)
    {
        int val = 0;
        for (size_t i = 0; i < s.size(); ++i)
        {
            val *= 26;
            val += s[i] - 'A' + 1;
        }
        return val;
    }
};

int main(int argc, char* argv[])
{
    Solution solution;
    assert(solution.titleToNumber("A") == 1);
    assert(solution.titleToNumber("B") == 2);
    assert(solution.titleToNumber("C") == 3);
    assert(solution.titleToNumber("Z") == 26);
    assert(solution.titleToNumber("AA") == 27);
    assert(solution.titleToNumber("AB") == 28);
    return 0;
}
