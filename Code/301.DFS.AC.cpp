class Solution {
 public:
  std::set<string> unique;

  void dfs(std::string& s,
           std::string& t,
           int index,
           int left,
           int right,
           int used_left,
           int used_right) {
    if (index == s.size()) {
      if (left == 0 && right == 0) {
        unique.emplace(t);
      }
      return;
    }
    // 跳过左右括号，但剩下需要删除的括号不能小于0
    if (s[index] == '(' && left > 0) {
      dfs(s, t, index + 1, left - 1, right, used_left, used_right);
    }
    if (s[index] == ')' && right > 0) {
      dfs(s, t, index + 1, left, right - 1, used_left, used_right);
    }
    t.push_back(s[index]);
    if (s[index] != '(' && s[index] != ')') {
      // 如果是字母，不用处理
      dfs(s, t, index + 1, left, right, used_left, used_right);
    } else if (s[index] == '(') {
      // 如果是左括号，我们更新左括号的数量
      dfs(s, t, index + 1, left, right, used_left + 1, used_right);
    } else if (used_right < used_left) {
      // 这一步实际上是把右括号多余的分支剪除； 只有 used_left < used_right 我们才有必要继续递归
      // 避免出现 `)(` 这样的情况
      dfs(s, t, index + 1, left, right, used_left, used_right + 1);
    }
    t.pop_back();
  }

  vector<string> removeInvalidParentheses(string s) {
    int left = 0, right = 0;
    for (const auto& item : s) {
      if (item == '(') {
        ++left;
      } else if (item == ')') {
        if (left > 0) {
          --left;
        } else {
          ++right;
        }
      }
    }
    std::string t;
    int used_left = 0, used_right = 0;
    dfs(s, t, 0, left, right, used_left, used_right);
    std::vector<string> result;
    for (const auto& item : unique) {
      result.emplace_back(item);
    }
    return result;
  }
};