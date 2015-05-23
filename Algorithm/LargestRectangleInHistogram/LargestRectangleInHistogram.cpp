/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

#include <stack>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int>& height)
    {
        int size = height.size();
        stack<int> stack;
        int result = 0;
        for (int i = 0; i < size;)
        {
            if (stack.empty() || height[i] >= height[stack.top()])
            {
                stack.push(i);
                ++i;
            }
            else
            {
                int index = stack.top();
                stack.pop();
                int area = stack.empty() ? height[index] * i : height[index] * (i - stack.top() - 1);
                if (area > result)
                {
                    result = area;
                }
            }
        }
        while (!stack.empty())
        {
            int index = stack.top();
            stack.pop();
            int area = stack.empty() ? height[index] * size : height[index] * (size - stack.top() - 1);
            if (area > result)
            {
                result = area;
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<int> height = {2, 0, 2};
    Solution s;
    printf("%d\n", s.largestRectangleArea(height));
    return 0;
}
