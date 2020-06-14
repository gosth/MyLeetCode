class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        std::vector<int> result;
        int sum = 0;
        for (auto& item : nums) {
            sum += item;
            result.emplace_back(sum);
        }
        return result;
    }
};