class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left_index = 0, right_index = nums.size() - 1;
        while (left_index < right_index) {
            int mid = left_index + (right_index - left_index) / 2;
            if (mid % 2) {
                if (nums[mid - 1] == nums[mid]) {
                    left_index = mid + 1;
                } else {
                    right_index = mid - 1;
                }
            } else {
                if (nums[mid + 1] == nums[mid]) {
                    left_index = mid + 2;
                } else {
                    right_index = mid;
                }
            }
        }
        return nums[left_index];
    }
};