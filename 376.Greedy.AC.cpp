class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int result = 1;
		int distance = 0, prevDistance = 0;
		size_t prevIndex = 0;
		if (nums.empty()) {
			return 0;
		}
		if (nums.size() < 2) {
			return 1;
		}
		for (size_t i = 1; i < nums.size(); ++i) {
			distance = nums[i] - nums[prevIndex];
			int direction = distance * prevDistance;
			if (direction > 0) {
				// 同向,啥也不干
				prevDistance = distance;

			}
			else if (direction < 0) {
				// 异向，即摇摆
				result += 1;
				prevDistance = distance;
			}
			else {
				if (distance != 0) {
					// 最开始的两点不共线
					result += 1;
					prevDistance = distance;
				}
				else {
					//两点共线或多点共线
					prevDistance = prevDistance;
				}
			}
			prevIndex = i;
		}
		return result;
	}
};