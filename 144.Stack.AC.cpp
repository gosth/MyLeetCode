
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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (!root) {
            return result;
        }
        std::stack<TreeNode*> store;
        store.emplace(root);
        while (!store.empty()) {
            auto item = store.top();
            result.emplace_back(item->val);
            store.pop();
            if (item->right) {
                store.emplace(item->right);
            }
            if (item->left) {
                store.emplace(item->left);
            }
        }
        return result;
    }
};