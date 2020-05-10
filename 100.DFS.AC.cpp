
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
    bool isSame(TreeNode* p,
            TreeNode* q) {
        if (p && q) {
            if (p->val == q->val) {
                return (isSame(p->left, q->left) &&
                        isSame(p->right, q->right));
            } else {
                return false;
            }
        }
        if (p && !q) {
            return false;
        } else if (!p && q) {
            return false;
        } else {
            // !p && !q
            return true;
        }
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSame(p, q);
    }
};