/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.
You may complete as many transactions as you like
(ie, buy one and sell one share of the stock multiple times).
However, you may not engage in multiple transactions at the same time
(ie, you must sell the stock before you buy again).
*/

#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:
    // Gready solution
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty())
        {
            return 0;
        }
        int size = prices.size();
        int sum = 0;
        int index = 0;
        while (index < size - 1)
        {
            int prev = index;
            while (index < size - 1 && prices[index] < prices[index + 1])
            {
                ++index;
            }
            sum += prices[index] - prices[prev];
            ++index;
        }
        return sum;
    }
};

int main(int argc, char* argv[])
{
    vector<int> array = {2,1,2,0,1};
    Solution s;
    printf("%d\n", s.maxProfit(array));
    return 0;
}
