/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string multiply(const string& num1, const string& num2)
    {
        if (num1.empty() || num2.empty())
        {
            return "";
        }
        int end = num2.size() - 1;
        string result;
        while (end >= 0)
        {
            string tmp = multiplyChar(num1, num2[end]);
            for (int i = 0; i < num2.size() - end - 1; ++i)
            {
                tmp.push_back('0');
            }
            result = stringPlus(result, tmp);
            --end;
        }
        if (result[0] == '0')
        {
            return "0";
        }
        return result;
    }

    string multiplyChar(const string& str, char c)
    {
        int end = str.size() - 1;
        int bit = 0;
        string result;
        while (end >= 0)
        {
            int product = (c - '0') * (str[end] - '0') + bit;
            bit = product / 10;
            result = string(1, product % 10 + '0') + result;
            --end;
        }
        while (bit != 0)
        {
            result = string(1, bit % 10 + '0') + result;
            bit = bit / 10;
        }
        return result;
    }

    string stringPlus(const string& num1, const string& num2)
    {
        int end1 = num1.size() - 1;
        int end2 = num2.size() - 1;
        string result;
        int bit = 0;
        while (end1 >= 0 && end2 >= 0)
        {
            int sum = (num1[end1] - '0') + (num2[end2] - '0') + bit;
            result = string(1, sum % 10 + '0') + result;
            bit = sum / 10;
            --end1;
            --end2;
        }
        if (end1 < 0)
        {
            while (end2 >= 0)
            {
                int sum = (num2[end2] - '0') + bit;
                result = string(1, sum % 10 + '0') + result;
                bit = sum / 10;
                --end2;
            }
        }
        if (end2 < 0)
        {
            while (end1 >= 0)
            {
                int sum = (num1[end1] - '0') + bit;
                result = string(1, sum % 10 + '0') + result;
                bit = sum / 10;
                --end1;
            }
        }
        while (bit != 0)
        {
            result = string(1, bit % 10 + '0') + result;
            bit = bit / 10;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    string s1 = "666";
    string s2 = "989";
    Solution s;
    cout << s.multiply(s1, s2) << endl;
    return 0;
}
