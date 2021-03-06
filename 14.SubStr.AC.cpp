class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string commonPrefix;
		if (strs.empty()) {
			return commonPrefix;
		}
		commonPrefix = strs.front();
		for (size_t i = 1; i < strs.size(); ++i) {
			while (strs[i].substr(0, commonPrefix.size()) != commonPrefix) {
				commonPrefix.pop_back();
			}
			if (commonPrefix.empty()) {
				return commonPrefix;
			}
		}
		return commonPrefix;
	}
};