class Solution {
 public:
  void dfs(const std::vector<int>& numInteger, int currentIndex, int* result) {
    if (currentIndex == numInteger.size()) {
      *result += 1;
      return;
    }
    // 使用一个字符
    dfs(numInteger, currentIndex + 1, result);
    // 使用两个字符
    if (currentIndex < numInteger.size() - 1 && 0 != numInteger[currentIndex]) {
      auto calcNum = numInteger[currentIndex] * 10 + numInteger[currentIndex + 1];
      if (calcNum <= 25) {
        dfs(numInteger, currentIndex + 2, result);
      }
    }

  }

  int translateNum(int num) {
    std::vector<int> numInteger;
    while (num) {
      numInteger.emplace_back(num % 10);
      num /= 10;
    }
    std::reverse(numInteger.begin(), numInteger.end());
    int result = 0;
    dfs(numInteger, 0, &result);
    return result;
  }
};