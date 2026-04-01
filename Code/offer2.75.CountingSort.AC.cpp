class Solution {
 public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    std::vector<int> result;
    int max_element = *std::max_element(arr1.begin(), arr1.end());
    std::vector<int> counting(max_element + 1, 0);
    for (auto& item : arr1) {
      ++counting[item];
    }
    for (const auto& pattern : arr2) {
      while (counting[pattern]) {
        result.emplace_back(pattern);
        --counting[pattern];
      }
    }
    for (int index = 0; index < counting.size(); ++index) {
      while (counting[index]) {
        result.emplace_back(index);
        --counting[index];
      }
    }
    return result;
  }
};