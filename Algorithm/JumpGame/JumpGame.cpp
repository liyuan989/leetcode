/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        if (nums.size() < 2)
        {
            return !nums.empty();
        }
        int index = 0;
        while (index < nums.size() - 1 && index + nums[index] < nums.size() - 1)
        {
            int max = index;
            for (int i = index + 1; i <= index + nums[index] ; ++i)
            {
                max = (max + nums[max] > i + nums[i]) ? max : i;
            }
            index = max;
            if (nums[index] == 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    vector<int> array = {1, 0, 2};
    Solution s;
    s.canJump(array);
    return 0;
}
