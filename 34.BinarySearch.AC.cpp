// ConsoleApplication19.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		std::vector<int> result;
		const int leftBound2 = leftBound(nums, target);
		const int rightBound2 = rightBound(nums, target);
		result.emplace_back(leftBound2);
		result.emplace_back(rightBound2);
		return result;
	}

	int leftBound(const std::vector<int>& nums, const int target) {
		int begin = 0;
		int end = nums.size() - 1;
		while (begin <= end) {
			int mid = (begin + end) / 2;
			if (target == nums[mid]) {
				if (mid == 0 || nums[mid - 1] < target) {
					return mid;
				}
				end = mid - 1;
			}
			else if (target > nums[mid]) {
				begin = mid + 1;
			}
			else if (target < nums[mid]) {
				end = mid - 1;
			}
		}
		return -1;
	}

	int rightBound(const std::vector<int>& nums, const int target) {
		int begin = 0;
		int end = nums.size() - 1;
		while (begin <= end) {
			int mid = (begin + end) / 2;
			if (target == nums[mid]) {
				if (mid == nums.size() - 1 || nums[mid + 1] > target) {
					return mid;
				}
				begin = mid + 1;
			}
			else if (target > nums[mid]) {
				begin = mid + 1;
			}
			else if (target < nums[mid]) {
				end = mid - 1;
			}
		}
		return -1;
	}
};

int main() {
	Solution a;
	vector<int> b{ 5,7,7,8,8,10 };
	vector<int> result = a.searchRange(b, 8);
	for (const auto item : result) {
		cout << item << endl;
	}
	getchar();
	return 0;
}

