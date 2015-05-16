/*
Given a string containing just the characters '(' and ')',
find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(const string& s)
    {
        if (s.size() < 2)
        {
            return 0;
        }
        stack<int> stack;
        int result = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                stack.push(i);
            }
            else
            {
                if (!stack.empty() && s[stack.top()] == '(')
                {
                    stack.pop();
                    int index = -1;
                    if (!stack.empty())
                    {
                        index = stack.top();
                    }
                    int current = i - index;
                    if (current > result)
                    {
                        result = current;
                    }
                }
                else
                {
                    stack.push(i);
                }
            }
        }
        return result;
    }
};
