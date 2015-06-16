/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.
You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).
*/

#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty())
        {
            return 0;
        }
        int size = prices.size();
        int lowest = prices[0];
        vector<int> dp_forward(size, 0);
        for (int i = 1; i < size; ++i)
        {
            dp_forward[i] = std::max(dp_forward[i - 1], prices[i] - lowest);
            lowest = std::min(lowest, prices[i]);
        }
        int highest = prices.back();
        vector<int> dp_backward(size, 0);
        for (int i = size - 2; i >= 0; --i)
        {
            dp_backward[i] = std::max(dp_backward[i + 1], highest - prices[i]);
            highest = std::max(highest, prices[i]);
        }
        int result = 0;
        for (int i = 0; i < size; ++i)
        {
            result = std::max(result, dp_forward[i] + dp_backward[i]);
        }
        return result;
    }

    // Time limit exceeded
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty())
        {
            return 0;
        }
        int size = prices.size();
        vector<int> dp_end(size, 0);
        vector<int> dp_begin(size, 0);
        for (int i = 1; i < size; ++i)
        {
            if (prices[i] > prices[i - 1])
            {
                dp_end[i] = dp_end[i - 1] + prices[i] - prices[i - 1];
            }
            else
            {
                dp_end[i] = std::max(dp_end[i - 1] - (prices[i - 1] - prices[i]), 0);
            }
            if (prices[size - i - 1] < prices[size - i])
            {
                dp_begin[size - i - 1] = dp_begin[size - i] + prices[size - i] - prices[size - i - 1];
            }
            else
            {
                dp_begin[size - i - 1] = std::max(dp_begin[size - i] - (prices[size - i - 1] - prices[size - i]), 0);
            }
        }
        int result = 0;
        for (int i = 0; i < size; ++i)
        {
            for (int j = i; j < size; ++j)
            {
                result = std::max(dp_end[i] + dp_begin[j], result);
            }
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<int> vec = {2,1,2,0,1};
    Solution s;
    printf("%d\n", s.maxProfit(vec));
    return 0;
}
