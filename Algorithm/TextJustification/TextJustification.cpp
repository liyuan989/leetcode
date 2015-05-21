/*
Given an array of words and a length L, format the text such that each line
has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible.
If the number of spaces on a line do not divide evenly between words,
the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.

Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/

#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string>& words, int max_width)
    {
        vector<string> result;
        if (max_width <= 0)
        {
            result.push_back("");
            return result;
        }
        int size = words.size();
        int last = 0;
        while (last < size)
        {
            int prev = last;
            int sum = 0;
            while (last < size)
            {
                sum += words[last].size();
                if (sum + last - prev > max_width)
                {
                    break;
                }
                ++last;
            }
            if (last < size)
            {
                sum -= words[last].size();
            }
            int n_words = last - prev;
            int n_space;
            if (last != size)
            {
                n_space = n_words == 1 ? 0 : (max_width - sum) / (n_words - 1);
            }
            else
            {
                n_space = 1;
            }
            string line;
            line.reserve(max_width);
            int left_space = max_width - sum - (n_words - 1) * n_space;
            for (int i = 0; i < n_words - 1 && prev < last; ++i)
            {
                line += words[prev];
                if (last != size)
                {
                    int len = n_space;
                    if (left_space > 0)
                    {
                        ++len;
                        --left_space;
                    }
                    string space(len, ' ');
                    line += space;
                }
                else
                {
                    string space(n_space, ' ');
                    line += space;
                }
                ++prev;
            }
            if (prev < last)
            {
                line += words[prev];
            }
            if (last == size || n_words == 1)
            {
                line += string(max_width - line.size(), ' ');
            }
            result.push_back(line);
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<string> array = {"Don't","go","around","saying","the","world","owes","you","a","living;",
                            "the","world","owes","you","nothing;","it","was","here","first."};
    Solution s;
    vector<string>&& result = s.fullJustify(array, 30);
    for (auto str : result)
    {
        printf("%s\n", str.c_str());
    }
    return 0;
}
