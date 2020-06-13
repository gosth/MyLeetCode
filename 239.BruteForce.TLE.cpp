class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> results;
        for (int i = 0; i < nums.size() - k + 1; ++i) {
            int featureCount = k;
            int value = INT_MIN;
            for (int countIndex = 0; countIndex < featureCount; ++countIndex) {
                value = std::max(value, nums[i + countIndex]);
            }
            results.emplace_back(value);
        }
        return results;
    }
};