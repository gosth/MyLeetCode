class Solution {
public:
	string removeKdigits(string num, int k) {
		vector<int> S;
		string result;
		for (int i = 0; i < num.size(); ++i) {
			int number = num[i] - '0';
			while (!S.empty() && S.back() > number && k > 0) {
				S.pop_back();
				--k;
			}
			if (number != 0 || !S.empty()) {
				S.push_back(number);
			}
		}
		while (!S.empty() && k > 0) {
			S.pop_back();
			--k;
		}
		for (int i = 0; i < S.size(); ++i) {
			result.append(1, '0' + S[i]);
		}
		if (result.empty()) {
			result = "0";
		}
		return result;
	}
};