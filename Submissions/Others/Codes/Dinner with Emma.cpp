#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int a[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int mn = 2e9;
    for (int j = 1; j <= m; j++) {
      mn = min(mn, a[i][j]);
    }
    ans = max(ans, mn);
  }
  cout << ans << '\n';

  return 0;
}