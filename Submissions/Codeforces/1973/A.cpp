#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c; cin >> a >> b >> c;
  if ((a + b + c) % 2) {
    cout << -1 << '\n';
    return;
  }
  int ans = (a + b + c) / 2;
  if (a + b <= c) {
    ans = a + b;
  }
  cout << ans << '\n';
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