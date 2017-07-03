/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

#include <vector>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        if (ratings.empty()) {
            return 0;
        }
        int len = ratings.size();
        std::vector<int> vec(len);
        vec[0] = 1;
        for (int i = 1; i < len; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                vec[i] = vec[i - 1] + 1; 
            } else {
                vec[i] = 1;
            }
        }
        for (int i = len - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && vec[i] <= vec[i + 1]) {
                vec[i] = vec[i + 1] + 1;
            }
        }
        int result = 0;
        for (int i = 0; i < len; ++i) {
            result += vec[i];
        }
        return result;
    }
};

