/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

1       2(abc)  3(def)
4(ghi)  5(jkl)  6(mno)
7(pqrs) 8(tuv)  9(wxyz)
*       0       #

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(const string& digits)
    {
        vector<string> result;
        if (digits.empty())
        {
            return result;
        }
        const char* letter[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s;
        doCombinations(digits, letter, 0, result, s);
        return result;
    }

    void doCombinations(const string& digits, const char* letter[], int index, vector<string>& result, string& s)
    {
        if (index >= digits.size())
        {
            result.push_back(s);
            return;
        }
        for (const char* p = letter[digits[index] - '0']; *p != '\0'; ++p)
        {
            s.push_back(*p);
            doCombinations(digits, letter, index + 1, result, s);
            s.pop_back();
        }
    }
};
