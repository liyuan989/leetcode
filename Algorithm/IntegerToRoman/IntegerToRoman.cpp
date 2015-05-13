/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string result;
        while (num > 0)
        {
            int flag = 1;
            for (int i = num; i >= 10; i = i / 10)
            {
                flag = flag * 10;
            }
            int n = num / flag;
            switch (flag)
            {
                case 1000:
                    for (int i = 0; i < n; ++i)
                    {
                        result.push_back('M');
                    }
                    break;
                case 100:
                    makeRoman(n, result, "CDM");
                    break;
                case 10:
                    makeRoman(n, result, "XLC");
                    break;
                case 1:
                    makeRoman(n, result, "IVX");
                    break;
                default:
                    break;
            }
            num = num - n * flag;
        }
        return result;
    }

    void makeRoman(int n, string& result, const char* s)
    {
        if (0 < n && n <= 3)
        {
            for (int i = 0; i < n; ++i)
            {
                result.push_back(s[0]);
            }
        }
        else if (3 < n && n <= 5)
        {
            for (int i = 0; i < 5 - n; ++i)
            {
                result.push_back(s[0]);
            }
            result.push_back(s[1]);
        }
        else if (5 < n && n <= 8)
        {
            result.push_back(s[1]);
            for (int i = 0; i < n - 5; ++i)
            {
                result.push_back(s[0]);
            }
        }
        else
        {
            result.push_back(s[0]);
            result.push_back(s[2]);
        }
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    cout << s.intToRoman(101) << endl;
    return 0;
}
