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
        // [le, ge]是待处理未知区域
        // 在每次循环前，循环不变量都是满足定义的
        // 循环体中，循环不变量可能暂时被打破。循环体中会有操作，保证下次循环前，循环不变量再次满足定义
        while (true) {
            while (le <= ge && nums[le] < pivot) {
                ++le;
            }
            while (le <= ge && nums[ge] > pivot) {
                --ge;
            }
            // le来到了第一个大于等于pivot的位置
            // ge来到了第一个小于等于pivot的位置
            // 这里break的条件，le >= ge 和 le > ge 都可以，但是le == ge 会错误
            // le == ge 错误的原因：具体pivot是数组最大值或者最小值时，到这里直接le > ge
            // le >= ge 和 le > ge 相同：
            //      （1）两种方式break前，数组元素内容和顺序一致
            //      （2）两种方式break后，循环不变量都是满足的
            //      （3）两种方式break后，最后swap后都能找到正确的pivot的位置（虽然正确的位置可能不唯一，参加下面的不同（2））
            // le >= ge 和 le > ge 不同：
            //      （1）le > ge 比 le >= ge 在le和ge指向同个元素时（这个元素一定等于pivot）,多了一次交换（实际是原地交换）
            //      （2）break后，le、ge的位置可能不同（当le和ge指向同个元素时，>=会直接break，le和ge指向同个元素；使用>情况下，需要多交换一次，下轮循环中break后，ge指向同个元素左边位置，le指向同个元素右边位置）。但最终两者break后，都是nums[left]交换nums[ge]即可。
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