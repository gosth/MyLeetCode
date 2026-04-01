
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        if (root) {
            store.emplace(root);
        }
    }

    /** @return the next smallest number */
    int next() {
        int nextValue = 0;
        while (!store.empty()) {
            // 这里不能加引用
            auto item = store.top();
            store.pop();
            if (item) {
                if (item->right) {
                    store.emplace(item->right);
                }
                store.emplace(item);
                store.emplace(nullptr);
                if (item->left) {
                    store.emplace(item->left);
                }
            } else {
                nextValue = store.top()->val;
                store.pop();
                break;
            }
        }
        return nextValue;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return store.empty() ? false : true;
    }

private:
    std::stack<TreeNode*> store;
};