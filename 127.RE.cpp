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
	int climbStairs(int n) {
		std::vector<int> dp(n + 1, 0);
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= n; ++i) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
};

int main() {
	
	Solution a;
	cout << a.climbStairs(1) << std::endl;
	cout << endl;

	getchar();
	return 0;
}
