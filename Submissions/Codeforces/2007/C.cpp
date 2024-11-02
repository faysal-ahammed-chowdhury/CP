#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x, y; cin >> n >> x >> y;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int gc = __gcd(x, y);
  for (int i = 1; i <= n; i++) {
    a[i] %= gc;
  }
  sort(a + 1, a + n + 1);
  // for (int i = 1; i <= n; i++) {
  //   cout << a[i] << ' ';
  // }
  // cout << '\n';
  int ans = a[n] - a[1];
  for (int i = 1; i < n; i++) {
    ans = min(ans, a[i] + gc - a[i + 1]);
    // cout << a[i] + gc - a[i + 1] << '\n';
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}