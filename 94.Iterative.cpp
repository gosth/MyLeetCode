#include<stack>
#include<vector>
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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> nodeStack;
		TreeNode* currentNode = root;
		while (currentNode || !nodeStack.empty()) {
			if (currentNode) {
				nodeStack.push(currentNode);
				currentNode = currentNode->left;
			}
			else {
				currentNode = nodeStack.top();
				result.push_bq
				nodeStack.pop();
				currentNode = currentNode->right;
			}
		}
		return result;
	}
};