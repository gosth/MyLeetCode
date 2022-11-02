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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        std::deque<TreeNode*> store;
        int result = 0;
        store.emplace_back(root);
        while(!store.empty()) {
            int level_size = store.size();
            for (int i = 0; i < level_size; ++i) {
                if (i == 0) {
                    result = store.front()->val;
                }
                auto current = store.front();
                if (current->left) {
                    store.emplace_back(current->left);
                }
                if (current->right) {
                    store.emplace_back(current->right);
                }
                store.pop_front();
            }
        }
        return result;

    }
};
