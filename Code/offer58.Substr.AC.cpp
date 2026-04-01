class Solution {
 public:
  string reverseLeftWords(string s, int n) {
    if (s.empty() || !n || n == s.size()) {
      return s;
    }
    return s.substr(n) + s.substr(0, n);
  }
};