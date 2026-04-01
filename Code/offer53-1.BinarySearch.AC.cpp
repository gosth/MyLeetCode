class Solution {
public:
    int BinarySearch(const std::vector<int>& nums, int start_index, int end_index, int target) {
        if (start_index > end_index) {
            return -1;
        }
        int mid = start_index + (end_index - start_index) / 2;
        if (target == nums[mid]) {
            return mid;
        }
        if (target > nums[mid]) {
            return BinarySearch(nums, mid + 1, end_index, target);
        }
        return BinarySearch(nums, start_index, mid - 1, target);
    }

    int search(vector<int>& nums, int target) {
        int search_index = BinarySearch(
                nums, 0, nums.size() - 1, target);
        int result = 0;
        if (-1 == search_index) {
            return 0;
        }
        for (int index = search_index - 1; index >= 0; --index) {
            if (nums[index] == target) {
                ++result;
            } else {
                break;
            }
        }
        for (int index = search_index + 1; index < nums.size(); ++index) {
            if (nums[index] == target) {
                ++result;
            } else {
                break;
            }
        }
        return result + 1;

    }
};