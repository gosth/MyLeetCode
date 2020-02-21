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
	int minimumTotal(vector<vector<int>>& triangle) {
		std::vector<std::vector<int>> dp;
		for (size_t line = 0; line < triangle.size(); ++line) {
			std::vector<int> singleLevel(triangle[line].size(), 0);
			if (line == triangle.size() - 1) {
				singleLevel = triangle[line];
			}
			dp.emplace_back(singleLevel);
		}
	}
	for (int i = triangle.size() - 2; i >= 0; --i) {
		for (int j = 0; j < triangle[i].size(); ++j) {
			dp[i][j] = std::min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
		}
	}
	return dp[0][0];
};