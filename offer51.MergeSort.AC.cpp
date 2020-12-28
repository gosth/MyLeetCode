class Solution {
public:
    int merge(std::vector<int>& nums, int leftIndex, int mid, int rightIndex, std::vector<int>& temp) {
        for (int i = leftIndex; i <= rightIndex; ++i) {
            temp[i] = nums[i];
        }
        int i = leftIndex;
        int j = mid + 1;
        int count = 0;
        for (int k = leftIndex; k <= rightIndex; ++k) {
            if (i == mid + 1) {
                nums[k] = temp[j];
                ++j;
            } else if (j == rightIndex + 1) {
                nums[k] = temp[i];
                ++i;
            } else if (temp[i] <= temp[j]) {
                nums[k] = temp[i];
                ++i;
            } else {
                nums[k] = temp[j];
                ++j;
                count += mid - i + 1;
            }
        }

        return count;

    }

    int reversePairs(std::vector<int>& nums, int leftIndex, int rightIndex, std::vector<int>& temp) {
        if (leftIndex == rightIndex) {
            return 0;
        }
        int mid = leftIndex + (rightIndex - leftIndex) / 2;
        int leftResult = reversePairs(nums, leftIndex, mid, temp);
        int rightResult = reversePairs(nums, mid + 1, rightIndex, temp);
        if (nums[mid] <= nums[mid + 1]) {
            return leftResult + rightResult;
        }
        return leftResult + rightResult + merge(nums, leftIndex, mid, rightIndex, temp);

    }

    int reversePairs(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        std::vector<int> temp(nums.size(), 0);
        return reversePairs(nums, 0, nums.size() - 1, temp);
    }
};