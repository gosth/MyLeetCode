class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_set<int> num_set;
    for (const auto& item : nums) {
      num_set.emplace(item);
    }
    for (const auto& item : num_set) {
      const auto find_item = target - item;
      if (find_item == item) {
        continue;
      } else {
        if (auto iter = num_set.find(find_item); iter != num_set.end()) {
          return {item, find_item};
        }
      }
    }
    return {};
  }
};