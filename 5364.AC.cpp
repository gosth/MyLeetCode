class Solution {
public:
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
		std::vector<int> result;
		size_t i = 0;
		for (const auto inx : index) {
			const auto iter = result.begin() + inx;
			result.insert(iter, nums[i]);
			++i;
		}
		return result;
	}
};