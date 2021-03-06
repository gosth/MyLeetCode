// ConsoleApplication18.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include  <algorithm>
using namespace std;


const int maxn = 1e6 + 10;
typedef  long long ll;
ll a[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, n, m;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    int cnt0 = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      cnt0 += (a[i] == 0);
    }
    if (m >= n) {
      cout << "Richman\n";
    }
    else if (cnt0 > m) {
      cout << "Impossible\n";
    }
    else {
      m -= cnt0;
      ll mn = 0x3f3f3f3f, ans = 0;
      for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) {
          continue;
        }
        if (m) {
          ans += a[i];
          --m;
        }
        else {
          mn = min(mn, a[i]);
        }
      }
      cout << ans + mn - 1 << "\n";
    }
  }
  return 0;
}
