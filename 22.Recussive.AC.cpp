// ConsoleApplication7.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		std::vector<std::string> result;
		generate("", n, n, result);
		return result;
	}

private:
	void generate(std::string item, int left, int right, std::vector<std::string>& result) {
		if (left == 0 && right == 0) {
			result.emplace_back(item);
			return;
		}
		if (left > 0) {
			generate(item + '(', left - 1, right, result);
		}
		if (left < right) {
			generate(item + ')', left, right - 1, result);
		}
	}
};

int main() {
	char a[10];
	char* b;
	cout << sizeof(a) << endl;
	cout << "line" << endl;
	cout << sizeof(b) << endl;
	sdshdr c;
	cout << sizeof(c) << endl;
	getchar();
}

