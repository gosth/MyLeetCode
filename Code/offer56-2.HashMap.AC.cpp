class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::map<int, int> mapping;
        for (const auto& item : nums) {
            mapping[item] += 1;
        }
        for (const auto& item : mapping) {
            if (item.second == 1) {
                return item.first;
            }
        }
        return 0;
    }
};