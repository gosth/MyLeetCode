class Solution {
            public:
                int minNum(std::vector<int>& nums, int startIndex, int endIndex) {
                    if (startIndex == endIndex) {
                        return nums[startIndex];
                    }
                    int mid = startIndex + (endIndex - startIndex) / 2;
                    if (nums[mid] > nums[endIndex]) {
                        return minNum(nums, mid + 1, endIndex);
                    } else if (nums[mid] < nums[endIndex]) {
                        return minNum(nums, startIndex, mid);
                    }
                    // 走不到
                    return -1;
                }

                int findMin(vector<int>& nums) {
                    if (nums.back() >= nums.front()) {
                        return nums.front();
                    }
                    return minNum(nums, 0, nums.size() - 1);
                }
            };