class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) {
			return 0;
		}
		size_t pos = haystack.find(needle);
		if (pos != string::npos) {
			return pos;
		}
		else {
			return -1;
		}
	}
};