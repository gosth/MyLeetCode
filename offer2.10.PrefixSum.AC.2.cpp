#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        std::map<int, int> prefix_sum_count;
        prefix_sum_count[0] = 1;
        int prefix_sum = 0;
        int result = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            prefix_sum += nums[i - 1];
            if (prefix_sum_count.find(prefix_sum - k) != prefix_sum_count.end()) {
                result += prefix_sum_count[prefix_sum - k];
            }
            prefix_sum_count[prefix_sum] += 1;
        }
        return result;
    }
};