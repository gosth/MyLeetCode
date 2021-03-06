class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		if (strs.empty()) {
			return result;
		}
		map<string, vector<size_t>> hashMap;
		size_t index = 0;
		for (auto str : strs) {
			sort(str.begin(), str.end());
			auto iter = hashMap.find(str);
			if (iter != hashMap.end()) {
				iter->second.push_back(index);
			}
			else {
				vector<size_t> temp{ index };
				hashMap[str] = temp;
			}
			++index;
		}
		for (map<string, vector<size_t> >::const_iterator it = hashMap.begin();
			it != hashMap.end();
			++it) {
			vector<string> temp;
			for (vector<size_t>::const_iterator inner = it->second.begin();
				inner != it->second.end();
				++inner) {
				temp.push_back(strs[*inner]);
			}
			result.push_back(temp);
		}
		return result;
	}
};