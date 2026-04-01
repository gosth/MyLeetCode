
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
  void buildTree(std::vector<int>::iterator preorder_start,
                 std::vector<int>::iterator inorder_start, std::vector<int>::iterator inorder_end,
                 TreeNode* node) {
    auto iter = std::find(inorder_start, inorder_end + 1, *preorder_start);
    if (iter != (inorder_end + 1)) {
      auto left_subtree_first_index = inorder_start;
      auto right_subtree_last_index = inorder_end;
      node->val = *preorder_start;
      int left_subtree_node_count = 0;
      if (left_subtree_first_index != iter) {
        auto left_subtree_last_index = (iter - 1);
        left_subtree_node_count = left_subtree_last_index - left_subtree_first_index + 1;
        node->left = new TreeNode(0);
        buildTree(preorder_start + 1,
                  left_subtree_first_index,
                  left_subtree_last_index,
                  node->left);
      }
      if (right_subtree_last_index != iter) {
        auto right_subtree_first_index = (iter + 1);
        node->right = new TreeNode(0);
        buildTree(preorder_start + left_subtree_node_count + 1,
                  right_subtree_first_index,
                  right_subtree_last_index,
                  node->right);
      }
    }
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(0);
    buildTree(preorder.begin(), inorder.begin(), inorder.end() - 1, root);
    return root;
  }
};