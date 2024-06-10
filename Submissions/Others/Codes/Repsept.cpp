#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int k; cin >> k;

  int x = 0;
  for (int i = 1; i <= k; i++) {
    x = (x * 10) + 7;
    x %= k;
    if (x == 0) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';

  return 0;
}