#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        int result = 0;
        int mask = 0;
        for (int i = 30; i >= 0; --i) {
            mask |= 1 << i;
            std::unordered_set<int> prefix;
            for (const auto &num : nums) {
                prefix.emplace(num & mask);
            }
            int temp = result | 1 << i;
            for (const auto &item : prefix) {
                if (prefix.find(temp ^ item) != prefix.end()) {
                    result = temp;
                    break;
                }
            }
        }
        return result;
    }
};
