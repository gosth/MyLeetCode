class Solution {
 public:
  std::map<int, int> mem;

  int process(int n) {
    if (n == 0) {
      return 0;
    } else if (n == 1) {
      return 1;
    }
    if (mem[n] != 0) {
      return mem[n];
    }
    int count = 0;
    for (int i = 1; i <= n; ++i) {
      // （n - 1）- (n - i)
      int left_tree_node_count = i - 1;
      int right_tree_node_count = (n - 1) - left_tree_node_count;
      int left_BST_count = 1, right_BST_count = 1;
      if (left_tree_node_count) {
        left_BST_count = numTrees(left_tree_node_count);
      }
      if (right_tree_node_count) {
        right_BST_count = numTrees(right_tree_node_count);
      }
      count += left_BST_count * right_BST_count;
    }
    mem[n] = count;
    return count;
  }
  int numTrees(int n) {
    return process(n);
  }
};