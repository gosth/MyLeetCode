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
	vector<int> inorderTraversal(TreeNode* root) {
		// morris traversal
		/*
		步骤：

			1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。

			2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。

			a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。

			b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。

			3. 重复以上1、2直到当前节点为空。
		*/
		vector<int> result;
		TreeNode *currentNode = root, *prev = NULL;
		while (currentNode) {
			if (!currentNode->left) {
				result.push_back(currentNode->val);
				currentNode = currentNode->right;
			}
			else {
				prev = findPrevNode(currentNode);
				if (!prev->right) {
					prev->right = currentNode;
					currentNode = currentNode->left;
				}
				else {
					if (prev->right == currentNode) {
						prev->right = NULL;
						result.push_back(currentNode->val);
						currentNode = currentNode->right;
					}
				}
			}
		}
		return result;
	}
private:
	TreeNode* findPrevNode(TreeNode* current) {
		TreeNode* prev = current->left;
		while (prev->right && prev->right != current) {
			prev = prev->right;
		}
		return prev;
	}
};