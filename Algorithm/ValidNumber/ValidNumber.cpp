/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous.
You should gather all requirements up front before implementing one.
*/

#include <string>
#include <assert.h>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool isNumber(const string& s)
    {
        if (s.empty())
        {
            return false;
        }
        int size = s.size();
        int index = 0;
        while (index < size && s[index] == ' ')
        {
            ++index;
        }
        if (index == size)
        {
            return false;
        }
        if (s[index] == '+' || s[index] == '-')
        {
            ++index;
        }
        bool has_point = false;
        bool has_e = false;
        for (int head = index; index < size; ++index)
        {
            if (s[index] == '.')
            {
                if (has_point || has_e)
                {
                    return false;
                }
                if (index == head && (index == size - 1 || (s[index + 1] < '0' || s[index + 1] > '9')))
                {
                    return false;
                }
                has_point = true;
                continue;
            }
            if (s[index] == 'e')
            {
                if (has_e || index == head || index == size - 1)
                {
                    return false;
                }
                if (s[index + 1] == '+' || s[index + 1] == '-')
                {
                    ++index;
                }
                if (s[index + 1] < '0' || s[index + 1] > '9')
                {
                    return false;
                }
                has_e = true;
                continue;
            }
            if (s[index] == ' ')
            {
                while (s[index] == ' ')
                {
                    ++index;
                }
                if (index == size)
                {
                    return true;
                }
                return false;
            }
            if (s[index] < '0' || s[index] > '9')
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
    assert(s.isNumber("0"));
    assert(s.isNumber(" 0.1 "));
    assert(!s.isNumber("abc"));
    assert(!s.isNumber("1 a"));
    assert(s.isNumber("2e10"));
    assert(s.isNumber("  +1.23  "));
    assert(s.isNumber("   -3e23 "));
    assert(s.isNumber("1."));
    assert(s.isNumber(".1"));
    assert(!s.isNumber("."));
    printf("all test case passed!\n");
    return 0;
}
