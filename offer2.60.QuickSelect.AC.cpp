#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int partion(std::vector<std::pair<int, int>> &nums, int left, int right) {
        int random_index = left + rand() % (right - left + 1);
        std::swap(nums[left], nums[random_index]);
        // <=target
        int left_index = left + 1;
        // >target
        int right_index = right;
        int target_value = nums[left].second;
        while (left_index <= right_index) {
            while (left_index <= right_index && nums[left_index].second <= target_value) {
                ++left_index;
            }
            while (left_index <= right_index && nums[right_index].second > target_value) {
                --right_index;
            }
            if (left_index < right_index) {
                std::swap(nums[left_index], nums[right_index]);
                ++left_index;
                --right_index;
            }
        }
        std::swap(nums[left], nums[left_index - 1]);
        return left_index - 1;
    }

    vector<int> topKFrequent(vector<int> &nums, int k) {
        std::unordered_map<int, int> mapping;
        for (const auto &item : nums) {
            ++mapping[item];
        }
        std::vector<std::pair<int, int>> counting;
        for (const auto &item : mapping) {
            counting.emplace_back(item);
        }
        int index = partion(counting, 0, counting.size() - 1);
        int target_index = counting.size() - k;
        int left_index = 0, right_index = counting.size() - 1;
        while (index != target_index) {
            if (index < target_index) {
                left_index = index + 1;
                index = partion(counting, left_index, right_index);
            }
            if (index > target_index) {
                right_index = index - 1;
                index = partion(counting, left_index, right_index);
            }
        }
        std::vector<int> result;
        for (; index < counting.size(); ++index) {
            result.emplace_back(counting[index].first);
        }
        return result;
    }
};

int main() {
    Solution s;
    std::vector<int> a{1, 1, 1, 2, 2, 3333};
    auto result = s.topKFrequent(a, 2);
    cout << "result=" << endl;
    for (const auto &item : result) {
        cout << item << endl;
    }
}
