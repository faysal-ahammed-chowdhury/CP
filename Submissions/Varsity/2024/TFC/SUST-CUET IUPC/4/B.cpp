#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x, y; cin >> n >> x >> y;

  if ((x & y) != y) {
    cout << "NO\n";
    return;
  }

  if (n == 1) {
    if (x == y) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
    return;
  }

  int z = x ^ y;
  int cnt = __builtin_popcount(z);
  int possible = 1 << cnt;
  if (possible >= n) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}