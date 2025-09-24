#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1][n + 1];
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      ans += a[i][j];
    }
  }

  int mn = 1e9;
  for (int i = 1, j = n; i <= n; i++, j--) {
    mn = min(mn, a[i][j]);
  }
  ans -= mn;

  cout << ans << '\n';

  return 0;
}