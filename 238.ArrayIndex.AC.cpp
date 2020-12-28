class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> left(nums.size() - 1, nums.front()), right(nums.size() - 1, nums.back());
        std::vector<int> result(nums.size(), 0);
        for (int i = 1; i < left.size(); ++i) {
            left[i] = left[i - 1] * nums[i];
            right[i] = right[i - 1] * nums[nums.size() - 1 - i];
        }
        result.front() = right.back();
        result.back() = left.back();
        for (int j = 1; j < nums.size() - 1; ++j) {
            result[j] = left[j - 1] * right[nums.size() - 1 - 1 - j];
        }
        return result;
    }
};
