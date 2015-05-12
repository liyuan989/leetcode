/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        double result = 0.0;
        if (nums1.empty() && nums2.empty())
        {
            return result;
        }
        int size = nums1.size() + nums2.size();
        int* array = new int[size];
        int index1 = 0;
        int index2 = 0;
        int i = 0;
        while (index1 < nums1.size() && index2 < nums2.size())
        {
            if (nums1[index1] < nums2[index2])
            {
                array[i] = nums1[index1];
                ++index1;
            }
            else
            {
                array[i] = nums2[index2];
                ++index2;
            }
            ++i;
        }
        if (index1 == nums1.size())
        {
            while (index2 < nums2.size())
            {
                array[i] = nums2[index2];
                ++index2;
                ++i;
            }
        }
        else
        {
            while (index1 < nums1.size())
            {
                array[i] = nums1[index1];
                ++index1;
                ++i;
            }
        }

        if (size & 1)
        {
            result = static_cast<double>(array[size / 2]);
        }
        else
        {
            result = static_cast<double>(array[size / 2] + array[size / 2 - 1]) / 2;
        }
        delete [] array;
        return result;
    }
};
