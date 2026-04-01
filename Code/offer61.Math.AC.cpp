class Solution {
 public:
  bool isStraight(vector<int>& nums) {
    std::set<int> data_collection;
    int zero_count = 0;
    for (const auto& item : nums) {
      if (0 == item) {
        ++zero_count;
      } else {
        if (data_collection.find(item) != data_collection.end()) { return false; }
        else {
          data_collection.emplace(item);
        }
      }
    }

    if (*data_collection.rbegin() - *data_collection.begin() >= 5) {
      return false;
    }
    return true;
  }
};