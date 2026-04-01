class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) {
      return {};
    }
    std::vector<int> results;
    std::unordered_map<char, int> pattern_coutings, sliding_window_countings;
    for (const auto& item : p) {
      ++pattern_coutings[item];
    }
    const int pattern_size = p.size();
    for (int index = 0; index < pattern_size - 1; ++index) {
      ++sliding_window_countings[s[index]];
    }
    for (int index = pattern_size - 1; index < s.size(); ++index) {
      ++sliding_window_countings[s[index]];
      if (sliding_window_countings == pattern_coutings) {
        results.emplace_back(index + 1 - pattern_size);
      }
      --sliding_window_countings[s[index + 1 - pattern_size]];
      if (sliding_window_countings[s[index + 1 - pattern_size]] == 0) {
        sliding_window_countings.erase(s[index + 1 - pattern_size]);
      }
    }
    return results;
  }
};