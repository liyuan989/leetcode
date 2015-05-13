/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int result = 0;
        if (height.empty())
        {
            return result;
        }
        int begin = 0;
        int end = height.size() - 1;
        while (begin < end)
        {
            int sum = (end - begin) * (height[begin] < height[end] ? height[begin] : height[end]);
            if (sum > result)
            {
                result = sum;
            }
            if (height[begin] < height)
            {
                ++begin;
            }
            else
            {
                --end;
            }
        }
        return result;
    }
};

