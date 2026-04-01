class Solution {
 public:
  vector<int> constructArr(vector<int>& a) {
    if (a.empty() || 1 == a.size()) {
      return {};
    }
    const int data_size = a.size();
    std::vector<int> left_factor(data_size, 1), right_factor(data_size, 1), result(data_size, 1);
    left_factor.front() = a.front();
    right_factor.back() = a.back();
    for (int index = 1; index < data_size; ++index) {
      left_factor[index] =
          left_factor[index - 1] * a[index];
      right_factor[data_size - index - 1] =
          right_factor[data_size - index] * a[data_size - index - 1];
    }
    result.front() = right_factor[1];
    result.back() = left_factor[data_size - 2];
    for (int index = 1; index < data_size - 1; ++index) {
      result[index] = left_factor[index - 1] * right_factor[index + 1];
    }
    return result;
  }
};