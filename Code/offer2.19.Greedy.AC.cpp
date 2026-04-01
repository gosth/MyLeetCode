class Solution {
 public:
  bool validPalindrome(string s) {
    if (s.empty()) {
      return true;
    }
    int left = 0, right = s.size() - 1;
    while (left < right) {
      if (s[left] != s[right]) {
        break;
      }
      ++left;
      --right;
    }
    if (left >= right) {
      return true;
    }
    int left_2 = left + 1, right_2 = right;
    while (left_2 < right_2) {
      if (s[left_2] != s[right_2]) {
        break;
      }
      ++left_2;
      --right_2;
    }
    if (left_2 >= right_2) {
      return true;
    }
    left_2 = left;
    right_2 = right - 1;
    while (left_2 < right_2) {
      if (s[left_2] != s[right_2]) {
        break;
      }
      ++left_2;
      --right_2;
    }
    if (left_2 >= right_2) {
      return true;
    }
    return false;
  }
};