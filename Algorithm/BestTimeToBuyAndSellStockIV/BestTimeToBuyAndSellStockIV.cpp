/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

#include <iostream>

class Solution {
public:
    int maxProfit(int k, std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        if (k >= prices.size()) {
            return directMaxProfit(k, prices);
        }
        std::vector<int> local(k + 1);
        std::vector<int> global(k + 1);
        for (int i = 1; i < prices.size(); ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = k; j >= 1; --j) {
                local[j] = std::max(global[j - 1] + std::max(0, diff), local[j] + diff);
                global[j] = std::max(local[j], global[j]);
            }
        }
        return global[k];
    }

    int directMaxProfit(int k, std::vector<int>& prices) {
        int result = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                result += prices[i] - prices[i - 1];
            }
        }
        return result;
    }
};

