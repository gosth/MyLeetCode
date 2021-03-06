class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		if (nums.size() < 4) {
			return result;
		}
		sort(nums.begin(), nums.end());
		std::unordered_multimap<int, pair<size_t, size_t>>  mapping;
		for (size_t i = 0; i < nums.size(); ++i) {
			for (size_t j = i + 1; j < nums.size(); ++j) {
				mapping.insert(make_pair(nums[i] + nums[j], make_pair(i, j)));
			}
		}

		for (size_t i = 0; i < nums.size(); ++i) {
			if (i > 0 && nums[i] == nums[i - 1]) { continue; }
			for (size_t j = i + 1; j < nums.size(); ++j) {
				if (j > i + 1 && nums[j] == nums[j - 1]) { continue; }
				int toFind = target - nums[i] - nums[j];
				if (mapping.count(toFind)) {
					auto range = mapping.equal_range(toFind);
					for (auto it = range.first; it != range.second; ++it) {
						pair<size_t, size_t>& indexPair = it->second;
						if (indexPair.first > j) {
							if (!result.empty() && result.back()[0] == nums[i] &&
								result.back()[1] == nums[j] &&
								result.back()[2] == nums[indexPair.first] &&
								result.back()[3] == nums[indexPair.second]) {
								continue;
							}
							vector<int> temp{ nums[i], nums[j], nums[indexPair.first], nums[indexPair.second] };
							result.push_back(temp);
						}
					}
				}
			}
		}
		return result;
	}
};