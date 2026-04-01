class Solution {
   public:
    vector<double> dicesProbability(int n) {
      int sum_set = 6 * n + 1;
      std::vector<std::vector<int>> feature_slots(n + 1, std::vector<int>(sum_set));
      for (int count = 1; count <= 6; ++count) {
        ++feature_slots[1][count];
      }
      for (int index = 1; index <= n - 1; ++index) {
        for (int sum = index; sum <= index * 6; ++sum) {
          for (int add = 1; add <= 6; ++add) {
            feature_slots[index + 1][sum + add] += feature_slots[index][sum];
          }
        }
      }
      std::vector<double> result;
      int total = std::pow(6, n);
      for (int sum = n; sum <= n * 6; ++sum) {
        result.emplace_back(feature_slots[n][sum] * 1.0 / total);
      }
      return result;
    }
  };