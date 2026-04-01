#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    size_t partition(vector<int>& vi, size_t low, size_t up) {
        int pivot = vi[up];
        int i = low - 1; //如果类型用size_t，当low==0时会下溢
        for (int j = low; j < up; j++) {
            if (vi[j] <= pivot) {
                i++;
                swap(vi[i], vi[j]);
            }
        }
        swap(vi[i + 1], vi[up]);
        return i + 1;
    }

    void findMedian(vector<int>& nums, size_t low, size_t up, size_t targetIndex) {
        if (!nums.empty()) {
            size_t index = partition(nums, low, up);
            if (index == targetIndex) {
                return ;
            } else if (targetIndex < index) {
                findMedian(nums, 0, index - 1, targetIndex);
            } else {
                findMedian(nums, index + 1, nums.size() - 1, targetIndex);
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        int totalNum = nums1.size();
        if (totalNum % 2 == 0) { //偶数个
            size_t midIndex1 = totalNum / 2 - 1, midIndex2 = totalNum / 2;
            findMedian(nums1, 0, nums1.size() - 1, midIndex1);
            double val1 = nums1[midIndex1];
            findMedian(nums1, 0, nums1.size() - 1, midIndex2);
            return (val1 + nums1[midIndex2]) / 2;
        } else { //奇数个
            size_t midIndex = totalNum / 2;
            findMedian(nums1, 0, nums1.size() - 1, midIndex);
            return nums1[midIndex];
        }
    }
};

int main() {
    vector<int> a{3,4};
    vector<int> b;
    Solution c;
    cout << c.findMedianSortedArrays(a, b) << endl;
    return 0;
}
