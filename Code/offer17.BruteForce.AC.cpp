class Solution {
 public:
  vector<int> printNumbers(int n) {
    std::vector<int> result;
    for (int num = 1; num < std::pow(10, n); ++num) {
      result.emplace_back(num);
    }
    return result;
  }
};