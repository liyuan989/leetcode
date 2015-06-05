/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    // DP solution
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty())
        {
            return 0;
        }
        vector<int> dp(prices.size(), 0);
        int max = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
            {
                dp[i] = dp[i - 1] + prices[i] - prices[i - 1];
            }
            else
            {
                dp[i] = std::max(dp[i - 1] - (prices[i - 1] - prices[i]), 0);
            }
            max = std::max(max, dp[i]);
        }
        return max;
    }
};

int main(int argc, char* argv[])
{
    vector<int> array = {2,1,2,0,1};
    Solution s;
    printf("%d\n", s.maxProfit(array));
    return 0;
}
