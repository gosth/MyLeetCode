class Solution {
 public:
  std::vector<int> count;
  std::vector<std::pair<int, int>> temp;
  
  void Merge(vector<pair<int, int>>& num_indexs, int left_bound, int mid, int right_bound) {
    int i = left_bound, j = mid + 1;
    int k = left_bound;
    while (i <= mid && j <= right_bound) {
      if (num_indexs[i].first <= num_indexs[j].first) {
        count[num_indexs[i].second] += j - mid - 1;
        temp[k++] = num_indexs[i++];
      } else {
        temp[k++] = num_indexs[j++];
      }
    }
    while (i <= mid) {  // 如果右边的j走完了，现在的i开始的数，其实都是大于所有右边的数的
      count[num_indexs[i].second] += j - mid - 1;
      temp[k++] = num_indexs[i++];
    }
    while (j <= right_bound) {
      temp[k++] = num_indexs[j++];
    }
    for (i = left_bound; i <= right_bound; i++) {
      num_indexs[i] = temp[i];
    }
  }

  void MergeSort(vector<pair<int, int>>& num_indexs, int left_bound, int right_bound) {
    if (left_bound >= right_bound) {
      return;
    }
    int mid = left_bound + (right_bound - left_bound) / 2;
    MergeSort(num_indexs, left_bound, mid);
    MergeSort(num_indexs, mid + 1, right_bound);
    Merge(num_indexs, left_bound, mid, right_bound);
  }

  vector<int> countSmaller(vector<int>& nums) {
    int nums_size = nums.size();
    std::vector<std::pair<int, int>> num_indexs;
    for (int i = 0; i < nums_size; i++) {
      num_indexs.emplace_back(pair<int, int>(nums[i], i));
    }
    temp = std::vector<std::pair<int, int>>(nums_size);
    count = std::vector<int>(nums_size, 0);
    MergeSort(num_indexs, 0, nums_size - 1);
    return count;
  }
};