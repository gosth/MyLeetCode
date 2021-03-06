class Solution {
public:
	string addBinary(string a, string b) {
		int aSize = a.size() - 1, bSize = b.size() - 1;
		int carry = 0;
		std::string sum;
		while (aSize >= 0 || bSize >= 0 || carry) {
			if (aSize >= 0) {
				carry += a[aSize] - '0';
				--aSize;
			}
			if (bSize >= 0) {
				carry += b[bSize] - '0';
				--bSize;
			}
			sum += carry % 2 + '0';
			carry /= 2;
		}
		reverse(sum.begin(), sum.end());
		return sum;
	}
};