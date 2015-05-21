/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int carry = 0;
        ++digits.back();
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        while (carry != 0)
        {
            digits.insert(digits.begin(), carry % 10);
            carry = carry / 10;
        }
        return digits;
    }
};

int main(int argc, char* argv[])
{
    vector<int> digits = {9, 9, 9, 9, 9};
    Solution s;
    vector<int>&& result = s.plusOne(digits);
    for (auto i : result)
    {
        printf("%d", i);
    }
    printf("\n");
    return 0;
}
