class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // 搜索范围为[1, arr.size() - 2]，因为最左、右端点不是目标
        int left = 1, right = arr.size() - 2, result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid + 1]) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};