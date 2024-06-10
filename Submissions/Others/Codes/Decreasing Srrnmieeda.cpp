#include <bits/stdc++.h>
using namespace std;

void solve() {
  int l, r; cin >> l >> r;

  if (l <= r / 2) {
    cout << -1 << '\n';
  }
  else {
    cout << r << '\n';
  }
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