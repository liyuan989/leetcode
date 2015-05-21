/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    string addBinary(const string& a, const string& b)
    {
        if (a.empty() && b.empty())
        {
            return "";
        }
        if (a.empty())
        {
            return b;
        }
        if (b.empty())
        {
            return a;
        }
        string result;
        result.reserve(a.size() + b.size());
        int carry = 0;
        int index_a = a.size() - 1;
        int index_b = b.size() - 1;
        while (index_a >= 0 && index_b >= 0)
        {
            int sum = a[index_a] - '0' + b[index_b] - '0' + carry;
            result.push_back(sum % 2 + '0');
            carry = sum / 2;
            --index_a;
            --index_b;
        }
        if (index_a < 0)
        {
            while (index_b >= 0 && carry != 0)
            {
                int sum = b[index_b] - '0' + carry;
                result.push_back(sum % 2 + '0');
                carry = sum / 2;
                --index_b;
            }
            while (index_b >= 0)
            {
                result.push_back(b[index_b]);
                --index_b;
            }
        }
        if (index_b < 0)
        {
            while (index_a >= 0 && carry != 0)
            {
                int sum = a[index_a] - '0' + carry;
                result.push_back(sum % 2 + '0');
                carry = sum / 2;
                --index_a;
            }
            while (index_a >= 0)
            {
                result.push_back(a[index_a]);
                --index_a;
            }
        }
        while (carry != 0)
        {
            result.push_back(carry % 2 + '0');
            carry = carry / 2;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    printf("%s\n", s.addBinary("101", "110").c_str());
    return 0;
}
