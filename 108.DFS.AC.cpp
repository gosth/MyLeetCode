class Solution {
public:
    
    void  buildTree(TreeNode*& node, vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        size_t mid = nums.size() / 2;
        node = new TreeNode(nums[mid]);
        std::vector<int> less, more;
        for (const auto& item : nums) {
            if (item != nums[mid]) {
                less.emplace_back(item);
            } else {
                break;
            }
        }
        for (size_t i = mid + 1; i < nums.size(); ++i) {
            more.emplace_back(nums[i]);
        }
        buildTree(node->left, less);
        buildTree(node->right, more);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        buildTree(root, nums);
        return root;
    }
};