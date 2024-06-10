#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c; cin >> a >> b >> c;
  if (a + 1 != c) {
    cout << -1 << '\n';
    return;
  }

  if (a == 0 and b == 0 and c == 1) {
    cout << 0 << '\n';
    return;
  }

  int ans = 0; 
  if (a != 0) {
    ans = __lg(a) + 1;
  }
  int total_node_possible = (1 << (ans +  1)) - 1;
  int can_put_in_last_level = (total_node_possible - ((a - 1) * 2 + 3)) / 2;
  b -= can_put_in_last_level;
  b = max(0, b);
  ans += (b + c - 1) / c;
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