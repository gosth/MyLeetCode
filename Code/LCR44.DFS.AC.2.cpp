#include <vector>
#include <iostream>
#include <deque>

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

    void DFS(TreeNode *node, int *depth, std::vector<int> *results) {
        if (!node) {
            return;
        }
        if (*depth >= results->size()) {
            results->emplace_back(node->val);
        }
        results->operator[](*depth) = std::max(results->operator[](*depth), node->val);
        *depth += 1;
        DFS(node->left, depth, results);
        DFS(node->right, depth, results);
        *depth -= 1;
    }

    vector<int> largestValues(TreeNode *root) {
        if (!root) {
            return {};
        }
        std::vector<int> results;
        int depth = 0;
        DFS(root, &depth, &results);
        return results;
    }
};