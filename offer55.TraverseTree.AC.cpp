class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    std::queue<TreeNode*> q;
    int level = 0, currentLevelNodeNum = 1;
    q.emplace(root);
    while (!q.empty()) {
      for (int i = 0; i < currentLevelNodeNum; ++i) {
        const TreeNode* node = q.front();
        if (node->left) {
          q.emplace(node->left);
        }
        if (node->right) {
          q.emplace(node->right);
        }
        q.pop();
      }
      currentLevelNodeNum = q.size();
      ++level;
    }
    return level;
  }
};