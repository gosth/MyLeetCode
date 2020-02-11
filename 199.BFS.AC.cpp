#include<iostream>
#include<vector>
#include<pair>
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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        // <node, depth>
        std::queue<std::pair<TreeNode*, int>> Q;
        if (root) {
            Q.push(std::make_pair(root, 0));
        }
        while (!Q.empty()) {
            const auto& currentNode = Q.front();
            const auto& nodeDepth = currentNode.second;
            if (result.size() == nodeDepth) {
                result.emplace_back(currentNode.first->val);
            } else {
                result[nodeDepth] = currentNode.first->val;
            }
            if (currentNode.first->left) {
                Q.push(std::make_pair(currentNode.first->left, nodeDepth + 1));
            }
            if (currentNode.first->right) {
                Q.push(std::make_pair(currentNode.first->right, nodeDepth + 1));
            }
            Q.pop();
        }
        return result;
    }
};