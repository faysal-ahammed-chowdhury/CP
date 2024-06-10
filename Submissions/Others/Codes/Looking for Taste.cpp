#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    ans |= x;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  // freopen("looking.in", "r", stdin);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}