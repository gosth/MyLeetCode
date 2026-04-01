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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int finish = 0;
        std::vector<TreeNode*> path, pathNodeP, pathNodeQ;
        preOrder(root, p, path, pathNodeP, finish);
        finish = 0;
        path.clear();
        preOrder(root, q, path, pathNodeQ, finish);
        size_t shorterLength = pathNodeP.size() < pathNodeQ.size() ? pathNodeP.size() : pathNodeQ.size();
        TreeNode* result = 0;
        for (size_t i = 0; i < shorterLength; ++i) {
            if (pathNodeP[i] == pathNodeQ[i]) {
                result = pathNodeP[i];
            }
        }
        return result;
    }

private:
    void
    preOrder(TreeNode* node,
            TreeNode* search,
            std::vector<TreeNode*>& path,
            std::vector<TreeNode*>& result,
            int& finish) {
        if (!node || finish) {
            return;
        }
        path.emplace_back(node);
        if (node == search) {
            finish = 1;
            result = path;
            return;
        }
        preOrder(node->left, search, path, result, finish);
        preOrder(node->right, search, path, result, finish);
        path.pop_back();
    }
};