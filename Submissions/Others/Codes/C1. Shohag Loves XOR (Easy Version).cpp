#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long x, m; cin >> x >> m;
  int ans = 0;
  int msb = __lg(x);
  int go = (1 << (msb + 1)) - 1;
  for (int y = 1; y <= min(m, 1ll * go); y++) {
    if (x == y) continue;
    if (x % (x ^ y) == 0 or y % (x ^ y) == 0) ans++;
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