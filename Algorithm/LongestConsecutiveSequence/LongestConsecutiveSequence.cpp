/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
 */

#include <vector>
#include <iostream>
#include <unordered_set>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        std::unordered_set<int> dict;
        for (int n : nums) {
            dict.insert(n);
        }
        int length = 1; 
        for (size_t i = 0; i < nums.size(); ++i) {
            dict.erase(nums[i]);
            int count = 1;
            int left = nums[i];
            while (dict.find(--left) != dict.end()) {
                ++count;
                dict.erase(left);
            }
            int right = nums[i];
            while (dict.find(++right) != dict.end()) {
                ++count;
                dict.erase(right);
            }
            length = count > length ? count : length;
        }
        return length;
    }
};

int main(int argc, const char *argv[]) {
    std::vector<int> vec = {100, 4, 200, 1, 3, 2};
    Solution solution;
    int result = solution.longestConsecutive(vec);
    std::cout << result << std::endl;
    return 0;
}

