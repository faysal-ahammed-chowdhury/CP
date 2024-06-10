#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  int ans = n;
  for (int j = 2; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if ((i + j) % (j * __gcd(i, j)) == 0) {
        // cout << j << ' '  << i << '\n';
        ans++;
      }
    }
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