class Solution {
 public:
  bool isMatch(const std::string& s, const std::string& p) {
    if (p.empty()) {
      if (s.empty()) {
        return true;
      } else {
        return false;
      }
    }
    if (".*" == p) {
      return true;
    }
    int pattern_index = 0, source_index = 0;
    for (; pattern_index < p.size(); ++pattern_index) {
      if (pattern_index + 1 < p.size() && p[pattern_index + 1] == '*') {
        const std::string& pattern_infos_2 = p.substr(pattern_index + 2);
        if (s.empty() || source_index == s.size()) {
          return isMatch("", pattern_infos_2);
        }
        if (isMatch(s.substr(source_index), pattern_infos_2)) {
          return true;
        }
        for (int match_index = source_index;
            match_index < s.size() &&
                (s[match_index] == p[pattern_index] ||
                    p[pattern_index] == '.');
            ++match_index) {
          if (isMatch(s.substr(match_index + 1), pattern_infos_2)) {
            return true;
          }
        }
        return false;
      } else {
        if (s.empty() || source_index == s.size()) {
          return false;
        }
        if (p[pattern_index] == '.') {
          ++source_index;
          continue;
        }
        if (p[pattern_index] != s[source_index]) {
          return false;
        }
        ++source_index;
      }
    }
    if (source_index < s.size()) {
      return false;
    }
    return true;
  }
};