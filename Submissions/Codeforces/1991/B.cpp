#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int b[n];
  for (int i = 1; i < n; i++) cin >> b[i];
  int a[n + 1];
  memset(a, 0, sizeof a);
  for (int i = 1; i < n; i++) {
    a[i] |= b[i];
    a[i + 1] |= b[i];
  }
  bool ok = true;
  for (int i = 1; i < n; i++) {
    ok &= b[i] == (a[i] & a[i + 1]);
  }
  if (ok) {
    for (int i = 1; i <= n; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
  else cout << -1 << '\n';
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