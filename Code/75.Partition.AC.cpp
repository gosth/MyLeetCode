class Solution {
    public:
        void sortColors(vector<int>& nums) {
            if (nums.size() < 2) {
                return;
            }
            // [0, leftIndex) == 0
            // [leftIndex, i) == 1
            // [rightIndex, len - 1] == 2
            int leftIndex = 0, rightIndex = nums.size(), currentIndex = 0;
            while (currentIndex < rightIndex) {
                auto& currentItem = nums[currentIndex];
                if (currentItem < 1) {
                    std::swap(currentItem, nums[leftIndex]);
                    ++leftIndex;
                    ++currentIndex;
                } else if (currentItem > 1) {
                    --rightIndex;
                    std::swap(currentItem, nums[rightIndex]);
                } else {
                    // == 1
                    ++currentIndex;
                }
            }
        }
    };