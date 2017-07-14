/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        std::vector<int> dp_max(nums.size(), 0);
        std::vector<int> dp_min(nums.size(), 0);
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp_max[i] = std::max(nums[i] * dp_max[i - 1], std::max(nums[i] * dp_min[i - 1], nums[i]));
            dp_min[i] = std::min(nums[i] * dp_max[i - 1], std::min(nums[i] * dp_min[i - 1], nums[i]));
            result = std::max(result, dp_max[i]);
        }
        return result;
    }
};

