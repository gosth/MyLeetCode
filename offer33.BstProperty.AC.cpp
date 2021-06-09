class Solution {
 public:
  bool IsPostorder(const std::vector<int>& postorder, int start_index, int end_index) {
    if (start_index >= end_index) {
      return true;
    }
    const auto base_item = postorder[end_index];
    // mid_index指向BST的后续遍历顺序的右子树的起始位置
    int mid_index = start_index;
    for (int index = start_index; index < end_index; ++index) {
      const auto& current_item = postorder[index];
      if (current_item < base_item) {
        ++mid_index;
        if (index >= mid_index) {
          return false;
        }
      }
    }
    return IsPostorder(postorder, start_index, mid_index - 1) &&
           IsPostorder(postorder, mid_index, end_index - 1);
  }

  bool verifyPostorder(vector<int>& postorder) {
    if (postorder.empty()) {
      return true;
    }
    return IsPostorder(postorder, 0, postorder.size() - 1);
  }
};