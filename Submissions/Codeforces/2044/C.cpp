#include <bits/stdc++.h>
using namespace std;

void solve() {
  int m, a, b, c; cin >> m >> a >> b >> c;
  int ans = min(a, m);
  ans += min(b, m);
  int rem = m + m - ans;
  ans += min(rem, c);
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}