class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s2.size() < s1.size()) {
      return false;
    }
    std::vector<int> pattern_counter(26, 0), target_counter(26, 0);
    for (const auto& item : s1) {
      pattern_counter[item - 'a'] += 1;
    }
    for (int i = 0; i < s1.size() - 1; ++i) {
      target_counter[s2[i] - 'a'] += 1;
    }
    for (int i = s1.size() - 1; i < s2.size(); ++i) {
      target_counter[s2[i] - 'a'] += 1;
      if (pattern_counter == target_counter) {
        return true;
      }
      target_counter[s2[i - s1.size() + 1] - 'a'] -= 1;
    }
    return false;
  }
};