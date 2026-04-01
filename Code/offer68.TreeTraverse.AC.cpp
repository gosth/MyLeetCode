class Solution {
 public:
  TreeNode* findNearestFatherNode(const std::vector<TreeNode*>& sequence1,
                                  const std::vector<TreeNode*>& sequence2) {
    int size1 = sequence1.size();
    int size2 = sequence2.size();
    int commonSize = std::min(size1, size2);
    int index = 0;
    for (; index < commonSize; ++index) {
      if (sequence1[index] != sequence2[index]) {
        break;
      }
    }
    return sequence1[index - 1];
  }

  void TraverseTree(TreeNode* now, TreeNode* p, TreeNode* q, std::vector<TreeNode*>* traverse1,
                    std::vector<TreeNode*>* traverse2) {
    if (!now) {
      return;
    }
    if (!traverse1->empty() && (traverse1->back() == p) && !traverse2->empty() &&
        (traverse2->back() == q)) {
      return;
    }
    if (!traverse1->empty() && (traverse1->back() != p)) {
      traverse1->emplace_back(now);
    }
    if (!traverse2->empty() && (traverse2->back() != q)) {
      traverse2->emplace_back(now);
    }
    TraverseTree(now->left, p, q, traverse1, traverse2);
    TraverseTree(now->right, p, q, traverse1, traverse2);
    if (!traverse1->empty() && (traverse1->back() != p)) {
      traverse1->pop_back();
    }
    if (!traverse2->empty() && (traverse2->back() != q)) {
      traverse2->pop_back();
    }
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!p || !q || !root) {
      return nullptr;
    }
    std::vector<TreeNode*> traverse1, traverse2;
    TreeNode* sentinel = new TreeNode(0);
    traverse1.emplace_back(sentinel);
    traverse2.emplace_back(sentinel);
    TraverseTree(root, p, q, &traverse1, &traverse2);
    return findNearestFatherNode(traverse1, traverse2);
  }
};