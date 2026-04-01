#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int left = 0, right = 0, result = 0;
        int multiple_result = 1;
        while (right < nums.size()) {
            while (left <= right && multiple_result * nums[right] >= k) {
                multiple_result /= nums[left];
                ++left;
            }
            multiple_result *= nums[right];
            if (left <= right) {
                result += right - left + 1;
            }
            ++right;
        }
        return result;
    }
};