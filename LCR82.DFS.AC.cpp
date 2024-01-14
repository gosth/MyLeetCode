class Solution {
 public:
  void DFS(int index,
           const std::vector<int>& candidates,
           int* target,
           std::vector<std::vector<int>>* results,
           std::vector<int>* temp_result,
           std::vector<std::set<int>>* level_uniq_collection) {
    if (*target == 0) {
      results->emplace_back(*temp_result);
      return;
    }
    for (int i = index; i < candidates.size(); ++i) {
      if (i > index && candidates[i] == candidates[i - 1]) {
        continue;
      }
      if (*target - candidates[i] >= 0) {
        temp_result->emplace_back(candidates[i]);
        *target -= candidates[i];
        DFS(i + 1, candidates, target, results, temp_result, level_uniq_collection);
        temp_result->pop_back();
        *target += candidates[i];
      }
    }
  }
  
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    std::vector<std::set<int>> level_uniq_collection(candidates.size());
    std::vector<std::vector<int>> results;
    std::vector<int> temp_result;
    std::sort(candidates.begin(), candidates.end());
    auto& sorted_candidates = candidates;
    for (int i = 0; i < candidates.size(); ++i) {
      if (i > 0 && candidates[i] == candidates[i - 1]) {
        continue;
      }
      if (target - candidates[i] >= 0) {
        temp_result.emplace_back(candidates[i]);
        target -= candidates[i];
        DFS(i + 1, candidates, &target, &results, &temp_result, &level_uniq_collection);
        temp_result.pop_back();
        target += candidates[i];
      }
    }
    return results;
  }
};