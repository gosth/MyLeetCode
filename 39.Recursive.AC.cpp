class Solution {
 public:
  void Recursive(const std::vector<int>& candidates,
                 std::vector<int>* current_path,
                 std::vector<std::vector<int>>* result_set,
                 int* target,
                 int begin_index) {
    if (*target == 0) {
      result_set->emplace_back(*current_path);
      return;
    }
    for (int index = begin_index; index < candidates.size(); ++index) {
      const auto& item = candidates[index];
      if (*target >= item) {
        *target -= item;
        current_path->emplace_back(item);
        Recursive(candidates, current_path, result_set, target, index);
        current_path->pop_back();
        *target += item;
      }
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    std::vector<std::vector<int>> result;
    std::vector<int> current_path;
    int begin_index = 0;
    Recursive(candidates, &current_path, &result, &target, begin_index);
    return result;
  }
};