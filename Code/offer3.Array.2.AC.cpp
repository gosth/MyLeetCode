class Solution {
public:
    void swap(int* a, int* b) {
        int c = *a;
        *a = *b;
        *b = c;
    }

    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) {
                if (nums[nums[i]] == nums[i]) {
                    return nums[i];
                } else {
                    swap(&nums[nums[i]], &nums[i]);
                    --i;
                }
            }
        }
        return 0;
    }
};