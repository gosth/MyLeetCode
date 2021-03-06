class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int result = 0;
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		size_t j = 0;
		for (size_t i = 0; i < g.size(); ++i) {
			for (; j < s.size(); ++j) {
				if (g[i] <= s[j]) {
					++result;
					++j;
					break;
				}
			}
		}
		return result;
	}
};