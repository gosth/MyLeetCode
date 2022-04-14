class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mapping;
        for (int index = 0; index < nums.size(); ++index) {
            int diff = target - nums[index];
            auto iter = mapping.find(diff);
            if (iter != mapping.end()) {
                return { iter->second, index };
            } else {
                mapping.emplace(nums[index], index);
            }
        }
        return {};
    }
};