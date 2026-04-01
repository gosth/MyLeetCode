class Solution {
 public:
  int longestValidParentheses(string s) {
    int result = 0;
    if (s.empty()) {
      return 0;
    }
    int start = 0;
    std::stack<int> store;
    for (int index = 0; index < s.size(); ++index) {
      if (s[index] == '(') {
        store.emplace(index);
      } else {
        if (!store.empty()) {
          store.pop();
          if (!store.empty()) {
            result = std::max(result, index - (store.top() + 1) + 1);
          } else {
            result = std::max(result, index - start + 1);
          }
        } else {
          start = index + 1;
        }
      }
    }
    return result;
  }
};