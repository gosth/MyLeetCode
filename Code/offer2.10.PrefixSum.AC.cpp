#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        std::map<int, std::vector<int>> prefix_sum_index;
        prefix_sum_index[0].emplace_back(0);
        int prefix_sum = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            prefix_sum += nums[i - 1];
            prefix_sum_index[prefix_sum].emplace_back(i);
        }
        int result = 0;
        for (const auto &item : prefix_sum_index) {
            auto iter = prefix_sum_index.find(k + item.first);
            if (iter != prefix_sum_index.end()) {
                for (const auto &i : item.second) {
                    for (const auto &j : iter->second) {
                        if (j > i) {
                            ++result;
                        }
                    }
                }
            }
        }
        return result;
    }
};