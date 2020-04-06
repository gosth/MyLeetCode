class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), greater<int>());
        int totalSum = 0;
        for (const auto& item : nums) {
            totalSum += item;
        }
        int tempSum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            tempSum += nums[i];
            if (tempSum > totalSum - tempSum) {
                return std::vector<int>(nums.begin(), nums.begin() + i +1);
            }
        }
        return std::vector<int>();
    }
};