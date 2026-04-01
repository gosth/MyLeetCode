class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (n == 0) {
			return;
		}
		int pos = m + n - 1;
		int p1 = m - 1, p2 = n - 1;  // 两个数组的末尾下标
		while (p2 != -1) {
			int num1 = INT_MIN;
			if (p1 >= 0) {
				num1 = nums1[p1];
			}
			const int num2 = nums2[p2];
			if (num2 >= num1) {
				nums1[pos] = num2;
				--p2;
			}
			else {
				nums1[pos] = num1;
				--p1;
			}
			--pos;
		}
	}
};