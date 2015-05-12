/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string convert(const string& s, int num_rows)
    {
        if (s.empty())
        {
            return "";
        }
        if (num_rows <= 1)
        {
            return s;
        }
        string result;
        result.reserve(s.size());
        int step = 2 * num_rows - 2;
        for (int i = 0; i < num_rows; ++i)
        {
            for (int j = i; j < s.size(); j += step)
            {
                result.push_back(s[j]);
                if (0 < step - 2 * i && step - 2 * i < step && j + step - 2 * i < s.size())
                {
                    result.push_back(s[j + step - 2 * i]);
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    return 0;
}
