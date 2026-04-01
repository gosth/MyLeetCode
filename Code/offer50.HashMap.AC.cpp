class Solution {
 public:
  char firstUniqChar(string s) {
    if (s.empty()) {
      return ' ';
    }
    std::map<char, std::vector<int>> mapping;
    for (size_t i = 0; i < s.size(); ++i) {
      mapping[s[i]].emplace_back(i);
    }
    int min_feature_index = INT_MAX;
    for (const auto& item : mapping) {
      if (1 == item.second.size()) {
        if (item.second.front() < min_feature_index) {
          min_feature_index = item.second.front();
        }
      }
    }
    if (INT_MAX == min_feature_index) {
      return ' ';
    } else {
      return s[min_feature_index];
    }
  }
};