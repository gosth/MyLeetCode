/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:

	 void split(const std::string& str,
		 std::vector<std::string>& tokens,
		 const std::string delim = " ") {
		 tokens.clear();
		 auto start = str.find_first_not_of(delim, 0); //  分割到的字符串的第一个字符
		 auto position = str.find_first_of(delim, start); //  分隔符的位置
		 while (position != std::string::npos || start != std::string::npos) {
			 // [start, position) 为分割下来的字符串
			 tokens.emplace_back(std::move(str.substr(start, position - start)));
			 start = str.find_first_not_of(delim, position);
			 position = str.find_first_of(delim, start);
		 }
	 }

	 // Encodes a tree to a single string.
	 std::string serialize(TreeNode* root) {
		 std::string serializition;
		 if (!root) {
			 return serializition;
		 }
		 std::deque < TreeNode * > node_store;
		 node_store.emplace_back(root);
		 while (!node_store.empty()) {
			 const auto& current = node_store.front();
			 if (current) {
				 serializition.append("," + std::to_string(current->val));
				 node_store.emplace_back(current->left);
				 node_store.emplace_back(current->right);
			 }
			 else {
				 // #标识该节点不存在
				 serializition.append(",#");
			 }
			 node_store.pop_front();
		 }
		 serializition.substr(1);
		 while (1) {
			 std::size_t pos = serializition.find_last_of(",#");
			 if (pos == serializition.size() - 2) {
				 serializition.erase(pos);
			 }
			 else {
				 break;
			 }
		 }
		 return serializition;
	 }

	 // Decodes your encoded data to tree.
	 TreeNode* deserialize(const std::string& serializition) {
		 if (serializition.empty()) {
			 return nullptr;
		 }
		 std::vector<std::string> tokens;
		 split(serializition, tokens, ",");
		 TreeNode* root = new TreeNode(std::stoi(tokens.front()));
		 std::deque < TreeNode ** > queue;
		 queue.emplace_back(&(root->left));
		 queue.emplace_back(&(root->right));
		 int index = 1;
		 for (; index < tokens.size(); ++index) {
			 auto& current = queue.front();
			 if (tokens[index] != "#") {
				 *current = new TreeNode(std::stoi(tokens[index]));
				 queue.emplace_back(&((*current)->left));
				 queue.emplace_back(&((*current)->right));
			 }
			 queue.pop_front();
		 }
		 return root;
	 }
 };

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));