/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements
from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector<int> copy = nums1;
        nums1.clear();
        int index1 = 0;
        int index2 = 0;
        while (index1 < m && index2 < n)
        {
            if (copy[index1] < nums2[index2])
            {
                nums1.push_back(copy[index1]);
                ++index1;
            }
            else
            {
                nums1.push_back(nums2[index2]);
                ++index2;
            }
        }
        if (index1 == m)
        {
            while (index2 < n)
            {
                nums1.push_back(nums2[index2]);
                ++index2;
            }
        }
        if (index2 == n)
        {
            while (index1 < m)
            {
                nums1.push_back(copy[index1]);
                ++index1;
            }
        }
    }
};
