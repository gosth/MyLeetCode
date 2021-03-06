// ConsoleApplication19.cpp: 定义控制台应用程序的入口点。
//
#include"stdafx.h"
#include <iostream>
#include <vector>
#include<map>
#include<string>
#include<queue>
#include<set>

using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int result = 0;
		if (nums.empty()) {
			return result;
		}
		if (1 == nums.size()) {
			return nums.front();
		}
		std::vector<int> dp(nums.size(), 0);  // 前i(从0开始)个房间能取到的最大值
		dp[0] = nums.front();
		dp[1] = std::max(nums.front(), nums[1]);
		for (size_t i = 2; i < nums.size(); ++i) {
			dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
		}
		return dp[nums.size() - 1];
	}
};
