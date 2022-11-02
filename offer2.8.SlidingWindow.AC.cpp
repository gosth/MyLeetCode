#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int left_index = 0, right_index = 0;
        int sum = 0;
        int result = INT_MAX;
        while (right_index < nums.size()) {
            sum += nums[right_index];
            while (sum >= target) {
                result = std::min(result, right_index - left_index + 1);
                sum -= nums[left_index];
                ++left_index;
            }
            ++right_index;
        }
        return result == INT_MAX ? 0 : result;
    }
};