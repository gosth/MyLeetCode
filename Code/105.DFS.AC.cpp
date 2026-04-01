/**
* Definition for a binary tree preorder.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
    void buildTree(const std::vector<int>& preorder,
            const std::vector<int>& inorder,
            TreeNode*& node) {
        if (preorder.empty() || inorder.empty()) {
            return;
        }
        node = new TreeNode(preorder.front());
        std::vector<int> preorder1, preorder2, inorder1, inorder2;
        bool isRightSubtree = false;
        for (const auto& item : inorder) {
            if (item == preorder.front()) {
                isRightSubtree = true;
                continue;
            }
            if (isRightSubtree) {
                inorder2.emplace_back(item);
            } else {
                inorder1.emplace_back(item);
            }
        }
        for (int index = 1; index <= inorder1.size(); ++index) {
            preorder1.emplace_back(preorder[index]);
        }
        for (int index = inorder1.size() + 1; index < preorder.size(); ++index) {
            preorder2.emplace_back(preorder[index]);
        }
        buildTree(preorder1, inorder1, node->left);
        buildTree(preorder2, inorder2, node->right);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(-1);
        buildTree(preorder, inorder, root);
        return root;
    }
};