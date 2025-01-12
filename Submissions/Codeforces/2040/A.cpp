#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    bool ok = true;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      int x = abs(a[i] - a[j]);
      if (x % k == 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "YES\n";
      cout << i << '\n';
      return;
    }
  }
  cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}