/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target,
where index1 must be less than index2.
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result;
        if (nums.size() < 2)
        {
            return result;
        }
        vector<int> array = nums;
        sort(array.begin(), array.end());
        result.reserve(2);
        int begin = 0;
        int end = array.size() - 1;
        while (begin < end)
        {
            int sum = array[begin] + array[end];
            if (sum == target)
            {
                break;
            }
            else if (sum < target)
            {
                ++begin;
            }
            else
            {
                --end;
            }
        }
        if (begin > end)
        {
            return result;
        }
        for (int i = 0; static_cast<size_t>(i) < nums.size(); ++i)
        {
            if (result.size() == 2)
            {
                break;
            }
            if (array[begin] == array[end])
            {
                if (array[begin] == nums[i])
                {
                    result.push_back(i + 1);
                }
            }
            else
            {
                if (array[begin] == nums[i] && (result.empty() || nums[i] != nums[result.back() - 1]))
                {
                    result.push_back(i + 1);
                }
                if (array[end] == nums[i] && (result.empty() || nums[i] != nums[result.back() - 1]))
                {
                    result.push_back(i + 1);
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<int> a = {5,75,25};
    Solution s;
    vector<int> r = s.twoSum(a, 100);
    for (size_t i = 0; i < r.size(); ++i)
    {
        printf("%d ", r[i]);
    }
    return 0;
}
