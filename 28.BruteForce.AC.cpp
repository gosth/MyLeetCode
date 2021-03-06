// ConsoleApplication5.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) {
			return 0;
		}
		size_t m = haystack.size(), n = needle.size();
		if (m < n) {
			return -1;
		}
		for (size_t i = 0; i <= m - n; ++i) {
			size_t j = 0;
			for (; j < n; ++j) {
				if (haystack[i + j] != needle[j]) {
					break;
				}
			}
			if (j == n) {
				return i;
			}
		}
		return -1;
	}
};

int main()
{
	Solution a;
	cout << a.strStr("aaa", "aaaa") << endl;
    return 0;
}

