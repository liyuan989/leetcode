/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

#include <vector>
#include <iostream>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        size_t len = gas.size();
        int diff = 0;
        int start = 0;
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            diff += gas[i] - cost[i];
            if (sum < 0) {
                start = i; 
                sum = gas[i] - cost[i];
            } else {
                sum += gas[i] + cost[i];
            }
        }
        return diff < 0 ? -1 : start;
    }
};

