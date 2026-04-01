
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
            if (item->left) {
                store.emplace(item->left);
            }
            if (item->right) {
                store.emplace(item->right);
            }
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};