class Solution {
 public:
  void ReverseString(int start_index, int end_index, std::string* target) {
    int offset = 0;
    for (int index = start_index; index <= start_index + (end_index - start_index) / 2; ++index) {
      int change_index = end_index - offset;
      char temp = (*target)[index];
      (*target)[index] = (*target)[change_index];
      (*target)[change_index] = temp;
      ++offset;
    }
  }

  string reverseLeftWords(string s, int n) {
    if (s.empty() || !n || n == s.size()) {
      return s;
    }
    ReverseString(0, s.size() - 1, &s);
    ReverseString(0, s.size() - n - 1, &s);
    ReverseString(s.size() - n, s.size() - 1, &s);
    return s;
  }
};