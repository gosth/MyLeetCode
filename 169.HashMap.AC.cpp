class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int, int> dict;
        for (const auto& num : nums) {
            dict[num] += 1;
        }
        for (const auto& item : dict) {
            if (item.second > nums.size() / 2) {
                return item.first;
            }
        }
        return 0;
    }
};