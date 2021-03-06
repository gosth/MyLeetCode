class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string commonPrefix;
		if (strs.empty()) {
			return commonPrefix;
		}
		commonPrefix = strs.front();
		for (size_t i = 1; i < strs.size(); ++i) {
			if (commonPrefix.size() < strs[i].size()) {
				for (size_t j = 0; j < commonPrefix.size(); ++j) {
					if (commonPrefix[j] != strs[i][j]) {
						commonPrefix = commonPrefix.substr(0, j);
						break;
					}
				}
			}
			else {
				commonPrefix = commonPrefix.substr(0, strs[i].size());
				for (size_t j = 0; j < strs[i].size(); ++j) {
					if (commonPrefix[j] != strs[i][j]) {
						commonPrefix = commonPrefix.substr(0, j);
						break;
					}
				}

			}
		}
		return commonPrefix;
	}
};