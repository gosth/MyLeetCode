#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int BinarySearch(const std::vector<int> &numbers, int target) {
        int left_index = 0, right_index = numbers.size() - 1;
        while (left_index <= right_index) {
            int mid_index = left_index + (right_index - left_index) / 2;
            if (numbers[mid_index] == target) {
                return mid_index;
            } else if (numbers[mid_index] < target) {
                left_index = mid_index + 1;
            } else {
                right_index = mid_index - 1;
            }
        }
        return -1;
    }

    std::vector<int> twoSum(const std::vector<int> &numbers,
                            int target) {
        if (numbers.empty() || 1 == numbers.size()) {
            return {};
        }
        for (int index = 0; index < numbers.size();
             ++index) {
            int find_index = BinarySearch(
                    numbers, target - numbers[index]);
            if (find_index != -1) {
                if (index == find_index) {
                    if (index > 0) {
                        if (numbers[index - 1] == numbers[index]) {
                            return {index - 1, index};
                        }
                    }
                    if (index + 1 < numbers.size()) {
                        if (numbers[index + 1] == numbers[index]) {
                            return {index, index + 1};
                        }
                    }
                    return {};
                }
                return {index, find_index};
            }
        }
        return {};
    }
};