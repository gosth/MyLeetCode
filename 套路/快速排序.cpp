#include <iostream>
#include <vector>

using namespace std;

// ============================================================
// 快速排序（Quick Sort）
// ============================================================
//
// 核心思想：
//   1. 从数组中选一个元素作为 "基准"（pivot）
//   2. 把数组分成两部分：<= pivot 的放左边，>= pivot 的放右边（这一步叫 Partition）
//   3. Partition 结束后，pivot 到达了它最终正确的位置——左边全 <= 它，右边全 >= 它
//   4. 对左右两部分递归执行同样操作，直到只剩一个元素（天然有序）
//
// 为什么能排好：
//   每次 Partition 让一个元素（pivot）到达最终位置，递归让所有元素都到达最终位置
//
// 时间复杂度：平均 O(n log n)，最坏 O(n²)（随机选 pivot 可避免最坏情况）
// 空间复杂度：O(log n)（递归栈深度）
//
// ============================================================
// 如何从零写对 Partition（每一步都是被迫的，不需要记忆）：
//
//   1. pivot 放最左边
//      让它不参与交换，最后再归位
//
//   2. 定义已处理区间：[left+1, le) 全部 <= pivot，(ge, right] 全部 >= pivot
//      初始时两个区间都为空，所以 le = left+1，ge = right
//      le 是下一个待处理的左侧位置，ge 是下一个待处理的右侧位置
//
//   3. 待处理区间是 [le, ge]，le 和 ge 本身都是未处理的
//      所有 while 和 if 的条件都是 le <= ge（还有元素没处理就继续）
//      不能写 le < ge：le == ge 时那个元素还没看过，漏掉它会分区出错或死循环
//      例：[3,5] pivot=3, le=ge=1。用 < 则跳过，ge 仍指向 5 > pivot，swap 后分区错误
//
//   4. nums[le] 与 pivot 比较用严格 <，nums[ge] 与 pivot 比较用严格 >
//      等于 pivot 的元素不急着归类，留给 swap 均匀分散到两侧
//      若用 <= 和 >=，全相同数组一侧为空，退化 O(n²)
//      例：[3,3,3] 用 <=，le 一路冲到底，每次 Partition 只分出一个元素（pivot），
//      剩余 n-1 个元素全留在同一侧 → 递归深度 n 层，每层 O(n) → 总复杂度 O(n²)
//
//   5. 循环结束后 swap(nums[left], nums[ge])
//      循环结束时 ge < le，ge 属于 [left, le) 故 nums[ge] <= pivot，交换不会破坏分区
//      不能换 nums[le]：nums[le] >= pivot，无法保证交换后左边全 <= pivot
//      例：[3,1,5] 结束时 ge=1(值1), le=2(值5)。换 ge 得 [1,3,5]✓ 换 le 得 [5,1,3]✗
// ============================================================

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
        srand(time(nullptr));
        QuickSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }

    // Partition：把 nums[left..right] 重排为 [<= pivot | pivot | >= pivot]
    // 返回 pivot 最终所在的下标
    int Partition(std::vector<int> &nums, int left, int right) {
        // 随机选 pivot 放到最左边，避免最坏 O(n²)，且让它不参与中间的交换
        std::swap(nums[left], nums[left + rand() % (right - left + 1)]);
        int pivot = nums[left];

        // le：下一个待处理的左侧位置（[left+1, le) 已确认 <= pivot）
        // ge：下一个待处理的右侧位置（(ge, right] 已确认 >= pivot）
        int le = left + 1;
        int ge = right;

        // le 和 ge 本身未处理，所以条件用 le <= ge（还有未处理元素就继续）
        // 例：[3,5] le=ge=1。用 < 则跳过循环，ge 仍指向 5 > pivot，swap 后 [5,3] 分区错误
        while (le <= ge) {
            // 比较用严格 < 和 >：等于 pivot 的不跳过，留给 swap 均匀分散到两侧
            // 例：[3,3,3] 若用 <=，le 一路冲到底，每次 Partition 只分出一个元素（pivot），
            // 剩余 n-1 个元素全留在同一侧 → 递归 n 层，每层 O(n) → 退化 O(n²)
            while (le <= ge && nums[le] < pivot) ++le;
            while (le <= ge && nums[ge] > pivot) --ge;
            // 内层 while 可能让 le 越过 ge，必须再确认，否则交换已分好的元素
            // 例：[3,2,5] 内层后 le=2,ge=1 已交错，不检查就 swap(5,2) 搞乱
            if (le <= ge) {
                std::swap(nums[le], nums[ge]);
                ++le;
                --ge;
            }
        }
        // ge < le，nums[ge] <= pivot，交换安全
        // 例：[3,1,5] 结束时 ge=1(值1), le=2(值5)。换 ge 得 [1,3,5]✓
        std::swap(nums[left], nums[ge]);
        return ge;
    }

    void QuickSort(std::vector<int> &nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int pivot_index = Partition(nums, left, right);
        QuickSort(nums, left, pivot_index - 1);   // pivot 已就位，不参与后续
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
