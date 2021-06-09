/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  void DFS(TreeNode* node, TreeNode* global_temp_node) {
    if (!node || (!node->left && !node->right)) {
      return;
    }
    global_temp_node = node->left;
    node->left = node->right;
    node->right = global_temp_node;
    DFS(node->left, global_temp_node);
    DFS(node->right, global_temp_node);
  }

  TreeNode* mirrorTree(TreeNode* root) {
    if (!root) {
      return nullptr;
    }
    global_temp_node = new TreeNode(0);
    DFS(root, global_temp_node);
    return root;
  }

  TreeNode* global_temp_node;
};