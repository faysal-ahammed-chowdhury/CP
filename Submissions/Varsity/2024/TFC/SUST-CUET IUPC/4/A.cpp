#include <bits/stdc++.h>
using namespace std;

bool is_set(int n, int k) {
  return n & (1 << k);
}

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  bool all_zero = true;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    all_zero &= a[i] == 0;
  }
  if (all_zero) {
    cout << 0 << '\n';
    return;
  }
  if (k == 1) {
    for (int i = 1; i <= n; i++) {
      if (a[i] & 1) {
        cout << -1 << '\n';
        return;
      }
    }
  }

  int x = __lg(k);
  for (int K = x; K >= 0; K--) {
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if (is_set(a[i], K)) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << 1 << '\n';
      return;
    }
  }
  
  cout << 2 << '\n';
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