class Solution {
 public:
  vector<vector<int>> findContinuousSequence(int target) {
    std::vector<std::vector<int>> all_results;
    if (target < 3) {
      return all_results;
    }
    for (int start = 1; start <= target / 2; ++start) {
      int current = start;
      std::vector<int> temp_result;
      temp_result.emplace_back(current);
      int sum = current;
      while (sum <= target) {
        if (sum == target) {
          all_results.emplace_back(temp_result);
          break;
        } else {
          current += 1;
          sum += current;
          temp_result.emplace_back(current);
        }
      }
    }
    return all_results;
  }
};