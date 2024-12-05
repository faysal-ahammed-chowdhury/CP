#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, K = 20; // change here
int a[N];

void solve() {
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (q--) {
    int l, r; cin >> l >> r;
    bool all_same = true;
    for (int i = l + 1; i <= r; i++) {
      all_same &= a[i] == a[i - 1];
    }
    if (all_same) {
      cout << 0 << ' ';
      continue;
    }
    int ans = 1;
    for (int x = 2; x <= 100; x++) {
      bool ok = true;
      for (int i = l; i <= r; i++) {
        ok &= (a[i] % x) == (a[l] % x);
      }
      if (ok) ans = x;
    }
    cout << ans << ' ';
  }
  cout << '\n';
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