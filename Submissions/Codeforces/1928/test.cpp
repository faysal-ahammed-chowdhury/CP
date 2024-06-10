#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int cnt = 0;
  for (int k = 1; k <= 100; k++) {
    int n = 76, i = 1, last;
    while (i <= n) {
      for (int j = 1; j <= k and i <= n; j++, i++) {
        // cout << j << ' ';
        last = j;
      }
      for (int j = k  - 1; j >= 2 and i <= n; j--, i++) {
        // cout << j << ' ';
        last = j;
      }
    }
    if (last == 4) {
      cout << k << ' ';
      cnt++;
    }
  }
  cout << cnt << '\n';

  return 0;
}