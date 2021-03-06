class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		std::vector<std::vector<int>> result;
		if (nums.empty()) {
			return result;
		}
		result.push_back(std::vector<int>());
		for (size_t i = 0; i < nums.size(); ++i) {
			const int item = nums[i];
			size_t resultSize = result.size();
			// 下面的循环不能直接用result.size()，否则会死循环，需要临时变量
			for (size_t j = 0; j < resultSize; ++j) {
				std::vector<int> newSubset = result[j];
				newSubset.push_back(item);
				result.push_back(newSubset);
			}
		}
		return result;
	}
};