class Solution {
public:
	int reverse(int x) {
		long ret = 0;
		while (x) {
			ret = ret * 10 + x % 10;
			x = x / 10;
		}
		return (int(ret) == ret) * ret;
	}
};