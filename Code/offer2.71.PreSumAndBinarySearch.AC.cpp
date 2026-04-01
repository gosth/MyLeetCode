class Solution {
 public:
  Solution(vector<int>& w) : pre_sum(std::move(w)) {
    std::partial_sum(pre_sum.begin(), pre_sum.end(), pre_sum.begin());
  }

  int pickIndex() {
    int random_value = std::rand() % pre_sum.back() + 1;
    return std::lower_bound(pre_sum.begin(), pre_sum.end(), random_value) - pre_sum.begin();
  }
  std::vector<int> pre_sum;
};