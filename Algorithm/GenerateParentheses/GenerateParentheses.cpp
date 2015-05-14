/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string s;
        doGenerate(result, s, n, n);
        return result;
    }

    void doGenerate(vector<string>& result, string& s, int left, int right)
    {
        if (left == 0 && right == 0)
        {
            result.push_back(s);
            return;
        }
        if (left > 0)
        {
            s.push_back('(');
            doGenerate(result, s, left - 1, right);
            s.pop_back();
        }
        if (left < right)
        {
            s.push_back(')');
            doGenerate(result, s, left, right - 1);
            s.pop_back();
        }
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<string> v = s.generateParenthesis(3);
    for (auto& str : v)
    {
        cout << str << endl;
    }
    return 0;
}
