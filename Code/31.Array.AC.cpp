class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            if (nums.size() == 1 || nums.empty()) {
                return;
            }
            int smallerIndex = -1;
            for (int i = nums.size() - 1; i >= 1; --i) {
                if (nums[i] <= nums[i - 1]) {
                    continue;
                } else {
                    smallerIndex = i - 1;
                    break;
                }
            }
            if (smallerIndex == -1) {
                std::reverse(nums.begin(), nums.end());
                return;
            }
            int biggerIndex = -1;
            for (int i = nums.size() - 1; i > smallerIndex; --i) {
                if (nums[i] > nums[smallerIndex]) {
                    biggerIndex = i;
                    break;
                }
            }
            std::swap(nums[smallerIndex], nums[biggerIndex]);
            std::reverse(nums.begin() + smallerIndex + 1, nums.end());
            return;
        }
    };