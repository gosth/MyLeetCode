class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    std::map<int, int> mapping;
    for (const auto& item : nums) {
      ++mapping[item];
    }
    int half_threshold = nums.size() / 2;
    for (const auto& item : mapping) {
      if (item.second > half_threshold) {
        return item.first;
      }
    }
    return 0;
  }
};