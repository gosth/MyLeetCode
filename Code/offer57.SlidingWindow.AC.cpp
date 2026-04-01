class Solution {
 public:
  vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> results;
    if (target < 3) {
      return results;
    }
    int start = 1, end = 2;
    int sum = start + end;
    while (start <= target / 2) {
      if (sum == target) {
        std::vector<int> temp_result;
        for (int num = start; num <= end; ++num) {
          temp_result.emplace_back(num);
        }
        results.emplace_back(temp_result);
        sum -= start;
        ++start;
      } else if (sum < target) {
        ++end;
        sum += end;
      } else {
        // sum > target
        sum -= start;
        ++start;
      }
    }
    return results;
  }
};