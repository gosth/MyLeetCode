class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		std::vector<std::string> result;
		if (s.size() <= 10) {
			return std::vector<std::string>();
		}
		std::map<std::string, int> dict;
		for (size_t i = 0; i <= s.size() - 10; ++i) {
			const auto& currentString = s.substr(i, 10);
			dict[currentString] += 1;
		}
		for (const auto& item : dict) {
			if (item.second > 1) {
				result.emplace_back(item.first);
			}
		}
		return result;
	}
};