class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0, end = nums.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            if (target < nums[mid]) {
                if (nums[begin] < nums[mid]) {
                    if (target >= nums[begin]) {
                        end = mid - 1;
                    } else {
                        begin = mid + 1;
                    }
                } else if (nums[begin] > nums[mid]) {
                    end = mid - 1;
                } else if (nums[begin] == nums[mid]) {
                    begin = mid + 1;
                }
            } else if (target > nums[mid]) {
                if (nums[begin] < nums[mid]) {
                    begin = mid + 1;
                } else if (nums[begin] > nums[mid]) {
                    if (target >= nums[begin]) {
                        end = mid - 1;
                    } else {
                        begin = mid + 1;
                    }
                } else if (nums[begin] == nums[mid]) {
                    begin = mid + 1;
                }
            }
        }
        return -1;
    }
};