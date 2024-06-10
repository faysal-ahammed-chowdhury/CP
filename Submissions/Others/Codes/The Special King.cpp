#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  int ans = abs(x1 - x2) + abs(y1 - y2);
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