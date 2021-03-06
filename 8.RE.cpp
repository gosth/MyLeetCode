class Solution {
public:
	int myAtoi(string str) {
		long val = 0;
		bool isPositive = true;
		for (size_t i = 0; i < str.size(); ++i) {
			if (str[i] == ' ') {
				continue;
			}
			if (str[i] != '+' && str[i] != '-' && (str[i] < '0' || str[i] > '9')) {
				val = isPositive ? val : -1 * val;
				if (val < INT_MIN) {
					return INT_MIN;
				}
				else if (val > INT_MAX) {
					return INT_MAX;
				}
				else {
					return val;
				}
			}
			if (str[i] == '-') {
				isPositive = false;
			}
			if (str[i] >= '0' && str[i] <= '9') {
				val = val * 10 + str[i] - '0';
			}
		}
		val = isPositive ? val : -1 * val;
		if (val < INT_MIN) {
			return INT_MIN;
		}
		else if (val > INT_MAX) {
			return INT_MAX;
		}
		else {
			return val;
		}
	}
};