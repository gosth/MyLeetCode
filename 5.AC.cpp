class Solution {
public:
	bool isPalindromeString(size_t b, size_t longestLength, const string& s) {
		size_t mid = b + ((longestLength - 1) / 2);
		if (longestLength % 2 == 0) {
			int j = 1;
			for (size_t i = b; i <= mid; ++i) {
				if (s[i] != s[b + longestLength - j]) {
					return false;
				}
				++j;
			}
		}
		else {
			int j = 1;
			for (size_t i = b; i < mid; ++i) {
				if (s[i] != s[b + longestLength - j]) {
					return false;
				}
				++j;
			}
		}
		return true;
	}
	string longestPalindrome(string s) {
		size_t longestLength = s.size();
		size_t begin = 0;
		if (s.empty()) {
			return s;
		}
		while (longestLength != 1) {
			if (isPalindromeString(begin, longestLength, s)) {

				return s.substr(begin, longestLength);
			}
			else {
				if (begin + longestLength == s.size()) {
					begin = 0;
					--longestLength;
				}
				else {
					++begin;
				}
			}
		}
		return s.substr(0, 1);
	}
};