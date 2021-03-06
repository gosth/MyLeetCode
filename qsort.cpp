// ConsoleApplication5.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

// 有效数据下标从begin到end，即[begin, end]
int partition(vector<int>& data, int begin, int end) {
	int target = data[end];
	int greaterIndex = -1;
	for (size_t i = begin; i < end; ++i) {
		int& item = data[i];
		if (greaterIndex == -1) {
			if (item <= target) {
				continue;
			}
			else {
				greaterIndex = i;
			}
		}
		else {
			if (item <= target) {
				int temp = item;
				item = data[greaterIndex];
				data[greaterIndex] = temp;
				++greaterIndex;
			}
			else {
				continue;
			}
		}
	}
	if (greaterIndex == -1) {
		return end;
	}
	else {
		int temp = data[end];
		data[end] = data[greaterIndex];
		data[greaterIndex] = temp;
		return greaterIndex;
	}
}

void qsort(vector<int>& data, int begin, int end) {
	if (begin >= end) {
		return;
	}
	int now = partition(data, begin, end);
	qsort(data, begin, now - 1);
	qsort(data, now + 1, end);
}

int main()
{
	vector<int> a{3,2,1};

	qsort(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i) {
		cout << a[i] << endl;
	}
	getchar();
	return 0;
}

