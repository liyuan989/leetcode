/*
Determine whether an integer is a palindrome. Do this without extra space.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

#include <stdio.h>
#include <assert.h>

/*
etc: 13425

1) 5    1342
2) 52   134
3) 524  13

if (524 == 13 || 524/10 == 13) return true

*/

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x != 0 && x % 10 == 0))
        {
            return false;
        }
        int sum = 0;
        while (sum < x)
        {
            sum = sum * 10 + x % 10;
            x = x / 10;
        }
        return (sum == x) || (sum / 10 == x);
    }
};

int main(int argc, char* argv[])
{
    Solution solution;
    assert(!solution.isPalindrome(1234));
    assert(solution.isPalindrome(0));
    assert(!solution.isPalindrome(-1));
    assert(solution.isPalindrome(1234321));
    assert(solution.isPalindrome(123321));
    assert(solution.isPalindrome(1));
    assert(solution.isPalindrome(11));
    return 0;
}
