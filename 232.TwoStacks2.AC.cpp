#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <cmath>
#include <numeric>


using namespace std;

int main() {
	multiset<int> a;
	a.insert(5);
	a.insert(1);
	a.insert(2);
	a.insert(2);
	a.insert(-1);
	for (multiset<int>::iterator i = a.begin();
		i != a.end();
		++i) {
		cout << *a << endl;
	}
	return 0;
}