class Solution {
   public:
    vector<double> dicesProbability(int n) {
      int total_num = std::pow(6, n);
      std::vector<std::vector<int>> store(2);
      int index = 0;
      for (int i = 0; i < 6; ++i) {
        store[index].emplace_back(i + 1);
      }
      while (--n) {
        for (const auto& item : store[index]) {
          for (int current = 1; current <= 6; ++current) {
            store[!index].emplace_back(item + current);
          }
        }
        store[index].clear();
        index = !index;
      }
      std::map<int, int> mapping;
      for (const auto& item : store[index]) {
        ++mapping[item];
      }
      std::vector<double> result;
      for (const auto& item : mapping) {
        result.emplace_back((1.0 * item.second) / total_num);
      }
      return result;
    }
  };