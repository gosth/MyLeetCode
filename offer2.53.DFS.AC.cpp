#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) {
            return nullptr;
        }
        TreeNode* left_ret = inorderSuccessor(root->left, p);
        if (left_ret) {
            return left_ret;
        }
        ++traverse_count;
        if (p != root) {
            if (p_index != -1) {
                return root;
            }

        } else {
            p_index = traverse_count - 1;
        }
        TreeNode* right_ret = inorderSuccessor(root->right, p);
        if (right_ret) {
            return right_ret;
        }
        return nullptr;

    }
public:
    int traverse_count = 0;
    int p_index = -1;
};
