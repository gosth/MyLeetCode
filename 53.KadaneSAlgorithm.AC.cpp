class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxSumEndHere = nums.front(), maxSumResult = maxSumEndHere;
		for (size_t i = 1; i < nums.size(); ++i) {
			maxSumEndHere = max(nums[i], maxSumEndHere + nums[i]);
			maxSumResult = max(maxSumResult, maxSumEndHere);
		}
		return maxSumResult;
	}
};