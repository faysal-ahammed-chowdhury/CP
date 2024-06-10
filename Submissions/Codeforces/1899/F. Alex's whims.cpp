#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, q; cin >> n >> q;
  for (int i = 1; i < n; i++) {
    cout << i << ' ' << i + 1 << '\n';
  }
  int before_last = n - 1;
  while (q--) {
    int x; cin >> x;
    if (x == before_last) {
      cout << -1 << ' ' << -1 << ' ' << -1 << '\n';
    }
    else {
      cout << n << ' ' << before_last << ' ' << x << '\n';
      before_last = x;
    }
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