class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    std::vector<std::pair<int, int>> datas;
    for (const auto& data : buildings) {
      datas.emplace_back(std::make_pair(data[0], -data[2]));
      datas.emplace_back(std::make_pair(data[1], data[2]));
    }
    std::sort(datas.begin(), datas.end());
    std::multiset<int> heap;
    heap.emplace(0);
    std::vector<std::vector<int>> result;
    int prev_max_height = 0, current_max_height = 0;
    for (const auto& data : datas) {
      if (data.second < 0) {
        heap.emplace(-data.second);
      } else {
        heap.erase(heap.find(data.second));
      }
      current_max_height = *heap.rbegin();
      if (current_max_height != prev_max_height) {
        prev_max_height = current_max_height;
        result.emplace_back(std::vector<int>{data.first, current_max_height});
      }
    }
    return result;
  }
};