// ConsoleApplication18.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include  <algorithm>
using namespace std;


int a(int* b) {
	cout << &(*b) << std::endl;
}
int main() {
	cout << 10 << endl;
	int b = 10;
	cout << &b << endl;
	a(b);
	cout << &b << endl;
	return 0;
}
