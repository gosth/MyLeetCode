class Solution {
 public:
  char firstUniqChar(string s) {
    if (s.empty()) {
      return ' ';
    }
    std::map<char, bool> mapping;
    for (size_t i = 0; i < s.size(); ++i) {
      if (mapping.find(s[i]) == mapping.end()) {
        mapping[s[i]] = true;
      } else {
        mapping[s[i]] = false;
      }
    }
    for (const auto& item : s) {
      if (mapping[item] == true) {
        return item;
      }
    }
    return ' ';
  }
};