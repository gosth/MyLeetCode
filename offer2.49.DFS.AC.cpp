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

    void DFS(TreeNode *current, int *status, std::vector<int> *result) {
        *status = *status * 10 + current->val;
        if (!(current->left) && !(current->right)) {
            result->emplace_back(*status);
            *status = *status / 10;
            return;
        }
        if (current->left) {
            DFS(current->left, status, result);
        }
        if (current->right) {
            DFS(current->right, status, result);
        }
        *status = *status / 10;
    }

    int sumNumbers(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int status = 0;
        std::vector<int> result;
        DFS(root, &status, &result);
        int sum = 0;
        for (const auto &item : result) {
            sum += item;
        }
        return sum;
    }
};