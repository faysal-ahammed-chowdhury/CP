#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    if (i & 1) ans = max(ans, x);
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