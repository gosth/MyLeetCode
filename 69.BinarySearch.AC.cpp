class Solution {
public:

	int mySqrt(int x) {
		if (1 == x) {
			return 1;
		}
		long upperBound = x / 2 + 1;
		long lowerBound = 0;
		while (true) {
			long mid = lowerBound + (upperBound - lowerBound) / 2;
			long now = mid * mid;
			if (x == now) {
				return mid;
			}
			else if (x / mid < mid) {
				if ((mid - 1) == x / (mid - 1)) {
					return mid - 1;
				}
				else if (x / (mid - 1) >(mid - 1)) {
					return mid - 1;
				}
				else {
					upperBound = mid - 2;
				}
			}
			else { // x > now
				if ((mid + 1) == x / (mid + 1)) {
					return mid + 1;
				}
				else if (x / (mid + 1) < (mid + 1)) {
					return mid;
				}
				else {
					lowerBound = mid + 2;
				}
			}
		}
	}
};