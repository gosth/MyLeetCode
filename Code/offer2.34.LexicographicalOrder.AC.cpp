class Solution {
 public:
  bool Matching(const std::string& before_data,
                const std::string& after_data,
                const std::string& order) {
    std::string::size_type before_data_size = before_data.size();
    std::string::size_type after_data_size = after_data.size();
    int min_data_size = std::min(before_data_size, after_data_size);
    bool is_matched = true;
    int index = 0;
    for (; index < min_data_size; ++index) {
      auto before_data_item = before_data.substr(index, 1);
      auto after_data_item = after_data.substr(index, 1);
      std::string::size_type position_1 = order.find(before_data_item);
      std::string::size_type position_2 = order.find(after_data_item);
      if (position_2 < position_1) {
        return false;
      } else if (position_2 > position_1) {
        return true;
      } else {
        // position_1 == position_2
        continue;
      }
    }
    if (before_data.size() <= after_data.size()) {
      return true;
    } else {
      return false;
    }
  }

  bool isAlienSorted(vector<string>& words, string order) {
    for (int index = 0; index < words.size() - 1; ++index) {
      if (!Matching(
          words[index], words[index + 1], order)) {
        return false;
      }
    }
    return true;
  }
};