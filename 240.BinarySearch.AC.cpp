bool binarySearch(const std::vector<int>& nums, int target) {
	if (nums.empty()) {
		return false;
	}
	int leftBound = 0, rightBound = nums.size() - 1;
	while (leftBound <= rightBound) {
		int mid = (leftBound + rightBound) / 2;
		if (mid > nums.size() - 1) {
			std::cout << leftBound << "|" << rightBound << std::endl;
			return false;
		}
		if (target == nums[mid]) {
			return true;
		}
		else if (target > nums[mid]) {
			leftBound = mid + 1;
		}
		else if (target < nums[mid]) {
			rightBound = mid - 1;
		}
	}
	return false;
}

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		for (const auto& line : matrix) {
			if (binarySearch(line, target)) {
				return true;
			};
		}
		return false;
	}
};