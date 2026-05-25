#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ============================================================
// 快速排序 Partition：从循环不变量推所有条件
// ============================================================
//
// 循环不变量（每次外层 while 判条件前都成立）：
//   nums[left] = pivot                    ← 不动
//   [left+1, le)  全部 ≤ pivot            ← 已处理（左）
//   [le, ge]      未处理（双闭！le 和 ge 自己也没看过）
//   (ge, right]   全部 ≥ pivot            ← 已处理（右）
//
// 时间 O(n log n) 平均，O(n²) 最坏（随机 pivot 规避）
// 空间 O(log n)（递归栈）
//
// ────────────────────────────────────────────────────────────
// [1] 初始化（由不变量推出）
// ────────────────────────────────────────────────────────────
// 写法：
//   le = left + 1;  ge = right;
// 推导：
//   已处理区为空 → [left+1, le) 空 → le = left+1
//                → (ge, right]  空 → ge = right
//
// ────────────────────────────────────────────────────────────
// [2] 外层循环（由不变量推出）
// ────────────────────────────────────────────────────────────
// 写法：
//   while (le <= ge)
// 推导：
//   未处理区 [le, ge] 双闭，le==ge 时仍剩一个元素未看
//   → 条件用 <=，不能用 <
// 反例：
//   [3,5] pivot=3, le=ge=1。用 < 直接跳过循环，
//   nums[1]=5 没看过却被默认已处理 → 结尾 swap 后 [5,3] ✗
//
// ────────────────────────────────────────────────────────────
// [3] 内层 le 右移（双闭来自不变量；严格 < 是性能优化）
// ────────────────────────────────────────────────────────────
// 写法：
//   while (le <= ge && nums[le] < pivot) ++le;
// 推导：
//   le<=ge：双闭，少了会让 le==ge 的元素逃过比较（同 [2]）
//   严格 <：不属于不变量，但是性能优化。等于 pivot 的元素停
//          下等 swap，让等值元素均匀分两侧，避免退化
// 反例：
//   [3,3,3,...] 用 <= → le 一路冲到底，每次 Partition 只剥
//   一个元素 → 递归 n 层，每层 O(n) → 退化 O(n²)
//
// ────────────────────────────────────────────────────────────
// [4] 内层 ge 左移（与 [3] 对称）
// ────────────────────────────────────────────────────────────
// 写法：
//   while (le <= ge && nums[ge] > pivot) --ge;
// 推导：
//   与 [3] 对称：双闭 + 严格 >
//
// ────────────────────────────────────────────────────────────
// [5] swap 前再判（由不变量推出）
// ────────────────────────────────────────────────────────────
// 写法：
//   if (le <= ge) { swap(nums[le], nums[ge]); ++le; --ge; }
// 推导：
//   内层 while 可能让 le 越过 ge，此时未处理区已空，
//   再 swap 会动到已处理元素 → 必须再判 le<=ge
//   swap 后两位置已分类，光标必须前进，否则死循环
// 反例：
//   [3,2,5] 内层后 le=2,ge=1 已交错，
//   不判直接 swap → [3,5,2] ✗
//
// ────────────────────────────────────────────────────────────
// [6] 结尾归位 pivot（由不变量 + 退出条件推出）
// ────────────────────────────────────────────────────────────
// 写法：
//   swap(nums[left], nums[ge]);  return ge;
// 推导：
//   外层退出 → 条件 le<=ge 为假 → le > ge
//   故 ge ∈ [left+1, le) → nums[ge] ≤ pivot ✓ 安全
//   若换 nums[le]：le ∈ (ge, right] → nums[le] ≥ pivot
//                  会破坏左侧不变量 ✗
// 反例：
//   [3,1,5] 结束 ge=1(值1), le=2(值5)
//   换 ge → [1,3,5] ✓ ；换 le → [5,1,3] ✗
//
// ────────────────────────────────────────────────────────────
// 口诀：双闭、严格、再判、换 ge
//   双闭 → 4 处 le<=ge（外层 + 2 个内层 + if）
//   严格 → 比较用 < 和 >（性能优化，不属于不变量）
//   再判 → swap 前 if (le<=ge) 再判一次
//   换 ge → 结尾 swap(nums[left], nums[ge])，不换 le
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
            return;                                  // 长度 ≤ 1 天然有序
        }
        int pivot_index = Partition(nums, left, right);
        QuickSort(nums, left, pivot_index - 1);      // pivot 已就位，不参与 → p-1
        QuickSort(nums, pivot_index + 1, right);     //                      → p+1
    }
};

// ============================================================
// 自验证测试：让错误大声报警，永远不靠肉眼"觉得对"下判断
// ============================================================
int main() {
    auto check = [](std::vector<int> a, const std::string &name) {
        auto expected = a;
        std::sort(expected.begin(), expected.end());
        Solution{}.sortArray(a);
        bool ok = (a == expected);
        std::cout << (ok ? "[PASS] " : "[FAIL] ") << name << "\n";
        assert(ok);
    };

    // —— 4 个口袋测试用例：覆盖 4 个核心易错点 ——
    check({3, 1},          "[3,1]      le==ge 时元素必须被看");
    check({3, 3, 3, 3},    "[3,3,3,3]  全相同不退化");
    check({3, 1, 5},       "[3,1,5]    结尾换 ge 不换 le");
    check({3, 2, 5},       "[3,2,5]    swap 前 if 必须再判");

    // —— 边界 ——
    check({},              "[]         空数组");
    check({1},              "[1]        单元素");
    check({2, 1},           "[2,1]      两元素逆序");
    check({1, 2},           "[1,2]      两元素已序");

    // —— 已序 / 逆序（容易触发最坏情况，验证随机 pivot 保护）——
    std::vector<int> asc(100);
    for (int i = 0; i < 100; ++i) asc[i] = i;
    check(asc, "升序 100");
    std::vector<int> desc(100);
    for (int i = 0; i < 100; ++i) desc[i] = 99 - i;
    check(desc, "降序 100");

    // —— 原始用例 ——
    check({3, 1, 1, 1, 2, 3, 5, 23, 213, 21, 3, 1, 23, 53, 15, 7, 124, 4, 2},
          "原始用例");

    // —— 随机大数组 ——
    std::vector<int> r(1000);
    for (auto &x : r) x = rand();
    check(r, "随机 1000");

    std::cout << "\n全部通过 ✓\n";
    return 0;
}
