#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <vector>


using namespace std;

// 下面两种方法都是正确的
class Solution {
public:
    // TreeNode*&必须是引用，TreeNode*是错误的，因为进行了指针拷贝，操作的不是原有的唯一指针了
    void DFS(TreeNode *root, TreeNode*& pre_node) {
        if (root->left) {
            DFS(root->left, pre_node);
        }
        root->left = nullptr;
        pre_node->right = root;
        pre_node = pre_node->right;
        if (root->right) {
            DFS(root->right, pre_node);
        }
    }

    TreeNode *increasingBST(TreeNode *root) {
        if (!root) {
            return nullptr;
        }
        TreeNode *dummy_node = new TreeNode();
        TreeNode *pre_node = dummy_node;
        DFS(root, pre_node);
        return dummy_node->right;
    }
};


class Solution {
public:

    TreeNode *pre_node;
    void DFS(TreeNode *root) {
        if (root->left) {
            DFS(root->left);
        }
        root->left = nullptr;
        pre_node->right = root;
        pre_node = pre_node->right;
        if (root->right) {
            DFS(root->right);
        }
    }

    TreeNode *increasingBST(TreeNode *root) {
        if (!root) {
            return nullptr;
        }
        TreeNode *dummy_node = new TreeNode();
        pre_node = dummy_node;
        DFS(root);
        return dummy_node->right;
    }
};