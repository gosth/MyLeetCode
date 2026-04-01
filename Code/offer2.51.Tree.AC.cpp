#include <iostream>
#include <set>
#include <vector>

using namespace std;


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
    int max_weight = INT_MIN;

    int GetMaxWeight(TreeNode *node) {
        if (!node) {
            return 0;
        }
        int left_subtree_weight = std::max(GetMaxWeight(node->left), 0);
        int right_subtree_weight = std::max(GetMaxWeight(node->right), 0);
        int current_max_path_weight = left_subtree_weight + right_subtree_weight + node->val;
        max_weight = std::max(max_weight, current_max_path_weight);
        return node->val + std::max(left_subtree_weight, right_subtree_weight);
    }

    int maxPathSum(TreeNode *root) {
        GetMaxWeight(root);
        return max_weight;
    }
};