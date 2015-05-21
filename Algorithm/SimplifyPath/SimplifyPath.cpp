/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:

Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

#include <stack>
#include <string>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    string simplifyPath(const string& path)
    {
        string result;
        stack<string> stack;
        if (path.empty())
        {
            return result;
        }
        int size = path.size();
        int last = 0;
        while (last < size)
        {
            while (last < size && path[last] == '/')
            {
                ++last;
            }
            int prev = last;
            while (last < size && path[last] != '/')
            {
                ++last;
            }
            if (prev < last)
            {
                string s = path.substr(prev, last - prev);
                if (s == "..")
                {
                    if (!stack.empty())
                    {
                        stack.pop();
                    }
                }
                else if (s == ".")
                {
                }
                else
                {
                    stack.push(s);
                }
            }
        }
        while (!stack.empty())
        {
            result = "/" + stack.top() + result;
            stack.pop();
        }
        if (result.empty())
        {
            result.push_back('/');
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%s\n", s.simplifyPath("/a/./b/../../c/").c_str());
    printf("%s\n", s.simplifyPath("/home/").c_str());
    printf("%s\n", s.simplifyPath("/../").c_str());
    printf("%s\n", s.simplifyPath("/home//foo/").c_str());
    return 0;
}
