#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        srand(time(nullptr)); // seed for the random number generator
        QuickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    int Partition(std::vector<int> &nums, int left, int right) {
        // [left, right]
        std::swap(nums[left], nums[left + rand() % (right - left + 1)]);
        int pivot = nums[left];
        int le = left + 1; // le : less equals，初始化为left + 1是为了让[left + 1, le)区间为空
        int ge = right; // ge : greater equals，初始化为right是为了让(ge, right]区间为空
        // all in nums[left + 1, le) <= pivot
        // all in nums(ge, right] >= pivot
        while (true) {
            while (le <= ge && nums[le] < pivot) {
                ++le;
            }
            while (le <= ge && nums[ge] > pivot) {
                --ge;
            }
            // le来到了第一个大于等于pivot的位置
            // ge来到了第一个小于等于pivot的位置
            if (le >= ge) {
                break;
            } else {
                std::swap(nums[le], nums[ge]);
                ++le;
                --ge;
            }
        }
        std::swap(nums[left], nums[ge]);
        return ge;
    }

    void QuickSort(std::vector<int> &nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int pivot_index = Partition(nums, left, right);
        QuickSort(nums, left, pivot_index - 1);
        QuickSort(nums, pivot_index + 1, right);
    }
};

int main() {
    std::vector<int> a{3, 1, 1, 1, 2, 3, 5, 23, 213, 21, 3, 1, 23, 53, 15, 7, 124, 4, 2};
    Solution s;
    const auto &sorted = s.sortArray(a);
    for (const auto &item: sorted) {
        cout << item << ", ";
    }
    return 0;
}