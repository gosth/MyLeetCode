#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

struct cmp {
    bool operator()(const std::pair<int, int>& item_1, const std::pair<int, int>& item_2) {
        return item_1.second > item_2.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> mapping;
        for (const auto& item : nums) {
            ++mapping[item];
        }
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, cmp> min_heap;
        for (const auto& item : mapping) {
            min_heap.emplace(item);
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        std::vector<int> result;
        while (!min_heap.empty()) {
            result.emplace_back(min_heap.top().first);
            min_heap.pop();
        }
        return result;
    }
};
