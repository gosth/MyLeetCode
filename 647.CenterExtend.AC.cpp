class Solution {
 public:
  int countSubstrings(string s) {
    int result = 0;
    for (int index = 0; index < s.size(); ++index) {
      result += 1;
      int left_index = index, right_index = index;
      while (1) {
        left_index -= 1;
        right_index += 1;
        if (left_index >= 0 && right_index < s.size()) {
          if (s[left_index] == s[right_index]) {
            ++result;
          } else {
            break;
          }
        } else {
          break;
        }
      }
      left_index = index, right_index = index - 1;
      while (1) {
        left_index -= 1;
        right_index += 1;
        if (left_index >= 0 && right_index < s.size()) {
          if (s[left_index] == s[right_index]) {
            ++result;
          } else {
            break;
          }
        } else {
          break;
        }
      }
    }
    return result;
  }
};