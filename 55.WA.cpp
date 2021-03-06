class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.empty() || 1 == nums.size()) {
			return true;
		}
		int nowIndex = 0;
		size_t readMaxIndex = nowIndex + nums[nowIndex];
		int maxIndex = 1;
		for (size_t i = 1; i < nums.size(); ++i) {
			if (readMaxIndex == nowIndex) {
				return false;
			}
			if (readMaxIndex >= nums.size() - 1) {
				return true;
			}
			if (i <= readMaxIndex) {
				if (nums[i] >= nums[maxIndex]) {
					maxIndex = i;
				}
			}
			else {
				if (nums[maxIndex] == 0) {
					return false;
				}
				nowIndex = maxIndex;
				maxIndex = nowIndex + 1;
				readMaxIndex = nowIndex + nums[nowIndex];
				i = nowIndex;
			}
		}
		return true;
	}
};