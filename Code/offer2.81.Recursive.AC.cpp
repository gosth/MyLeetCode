class Solution {
 public:
  void DFS(int index,
           const std::vector<int>& candidates,
           int target,
           std::vector<std::vector<int>>* results,
           std::vector<int>* candidate_result) {
    candidate_result->emplace_back(candidates[index]);
    target -= candidates[index];
    if (!target) {
      results->emplace_back(*candidate_result);
      candidate_result->pop_back();
      return;
    }
    for (; index < candidates.size(); ++index) {
      if (target - candidates[index] >= 0) {
        DFS(index, candidates, target, results, candidate_result);
      }
    }
    candidate_result->pop_back();
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if (candidates.empty()) {
      return {};
    }
    std::vector<std::vector<int>> results;
    int index = 0;
    for (; index < candidates.size(); ++index) {
      std::vector<int> candidate_result;
      if (target - candidates[index] >= 0) {
        DFS(index, candidates, target, &results, &candidate_result);
      }
    }
    return results;
  }
};