#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  ll x, m; cin >> x >> m;
  ll ans = max(0ll, (m - x) / x);
  if (ans == 0 and x <= m) ans++;
  for (ll p = max(0ll, m - x + 1); p <= m + x; p++) {
    // cout << p << '\n';
    if ((p ^ x) >= 1 and (p ^ x) <= m and p % x == 0) {
      // cout << (p ^ x) << '\n';
      ans++;
    }
  }
  for (int y = 1; y <= min(m, x); y++) {
    if ((x ^ y) % y == 0) ans++;
    if ((x ^ y) % y == 0 and (x ^ y) % x == 0) ans--;
  }

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