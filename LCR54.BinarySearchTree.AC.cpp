/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void Calc(TreeNode* root, int* pre_value) {
      if (!root) {
        return;
      }
      Calc(root->right, pre_value);
      root->val += *pre_value;
      *pre_value = root->val;
      Calc(root->left, pre_value);
    }
    TreeNode* convertBST(TreeNode* root) {
      if (!root) {
        return nullptr;
      }
      int pre_value = 0;
      Calc(root, &pre_value);
      return root;
    }
};