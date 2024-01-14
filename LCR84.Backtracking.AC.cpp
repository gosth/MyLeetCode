class Solution {
 public:

  void DFS(int nums_size,
           std::map<int, int>* integer_counting,
           std::vector<int>* temp_result,
           std::vector<std::vector<int>>* results) {
    if (temp_result->size() == nums_size) {
      results->emplace_back(*temp_result);
      return;
    }
    for (auto iter = integer_counting->begin(); iter != integer_counting->end(); ++iter) {
      if (iter->second) {
        temp_result->emplace_back(iter->first);
        iter->second -= 1;
        DFS(nums_size, integer_counting, temp_result, results);
        temp_result->pop_back();
        iter->second += 1;
      }
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    for (const auto& num: nums) {
      integer_counting_[num] += 1;
    }
    std::vector<std::vector<int>> results;
    std::vector<int> temp_result;
    size_t nums_size = nums.size();
    DFS(nums_size, &integer_counting_, &temp_result, &results);
    return results;
  }

  std::map<int, int> integer_counting_;
};