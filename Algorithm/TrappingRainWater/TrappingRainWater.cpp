/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

     |
   3 |                       +--+
     |                       |  |
   2 |          +--+xxxxxxxxx|  +--+xx+--+
     |          |  |xxxxxxxxx|  |  |xx|  |
   1 |   +--+xxx|  +--+xxx+--+  |  +--+  +--+
     |   |  |xxx|  |  |xxx|  |  |  |  |  |  |
   0 +---+--+---+--+--+---+--+--+--+--+--+--+----->
       0  1   0  2  1   0  1  3  2  1  2  1
*/

#include <utility>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    int trap(vector<int>& height)
    {
        if (height.size() < 3)
        {
            return 0;
        }
        int result = 0;
        int left = 0;
        int right = height.size() - 1;
        int left_max = 0;
        int right_max = 0;
        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] > left_max)
                {
                    left_max = height[left];
                }
                else if (height[left] < left_max)
                {
                    result += left_max - height[left];
                }
                ++left;
            }
            else
            {
                if (height[right] > right_max)
                {
                    right_max = height[right];
                }
                else if (height[right] < right_max)
                {
                    result += right_max - height[right];
                }
                --right;
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<int> array = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    printf("%d\n", s.trap(array));
    return 0;
}
