class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() < 2) {
			return 0;
		}
		int jumpCount = 1;
		int curentMaxIndex = nums[0];
		int prevMaxIndex = nums[0];
		for (size_t i = 1; i < nums.size(); ++i) {
			if (i > curentMaxIndex) {
				curentMaxIndex = prevMaxIndex;
				++jumpCount;
			}
			if (prevMaxIndex < nums[i] + i) {
				prevMaxIndex = nums[i] + i;
			}
		}
		return jumpCount;
	}
};