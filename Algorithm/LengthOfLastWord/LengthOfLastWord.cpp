/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/

#include <string>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(const string& s)
    {
        int length = 0;
        int index = s.size() - 1;
        while (index >= 0 && s[index] == ' ')
        {
            --index;
        }
        while (index >= 0 && s[index] != ' ')
        {
            ++length;
            --index;
        }
        return length;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%d\n", s.lengthOfLastWord("a "));
    return 0;
}
