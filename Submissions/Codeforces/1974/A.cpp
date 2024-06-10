#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, y; cin >> x >> y;
  int need_for_y = (y + 1) / 2;
  int rem = (15 * need_for_y) - (y * 4);
  x -= rem;
  x = max(0, x);
  int ans = (x + 14) / 15;
  ans += need_for_y;
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