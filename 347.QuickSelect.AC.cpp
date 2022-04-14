class Solution {
 public:
  
  void QuickSelect(int k,
                   int start_index,
                   int end_index,
                   std::vector<std::pair<int, int>>* datas,
                   std::vector<int>* result) {
    if (k == result->size()) {
      return;
    }
    int random_index = rand() % (end_index - start_index + 1) + start_index;
    std::swap((*datas)[random_index], (*datas)[start_index]);
    int swap_index = start_index + 1;
    int point_index = start_index + 1;
    while (point_index <= end_index) {
      if ((*datas)[point_index].second > (*datas)[start_index].second) {
        swap((*datas)[point_index], (*datas)[swap_index]);
        ++swap_index;
      }
      ++point_index;
    }
    std::swap((*datas)[swap_index - 1], (*datas)[start_index]);
    if (swap_index - 1 - start_index + 1 <= k - result->size()) {
      for (int iter_index = start_index; iter_index <= swap_index - 1; ++iter_index) {
        result->emplace_back((*datas)[iter_index].first);
      }
      QuickSelect(k, swap_index, end_index, datas, result);
    } else {
      QuickSelect(k, start_index, swap_index - 2, datas, result);
    }
  }

  vector<int> topKFrequent(vector<int>& nums, int k) {
    std::map<int, int> frequency_mapping;
    for (const auto& item : nums) {
      ++frequency_mapping[item];
    }
    std::vector<std::pair<int, int>> datas;
    for (const auto& item : frequency_mapping) {
      datas.emplace_back(item);
    }
    std::vector<int> result;
    srand((unsigned)time(NULL));
    QuickSelect(k,
                0,
                datas.size() - 1,
                &datas,
                &result);
    return result;            
  }
};