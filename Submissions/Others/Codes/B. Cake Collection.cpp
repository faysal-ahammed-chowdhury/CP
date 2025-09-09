#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += 1ll * a[i] * max(0, (m - i + 1));
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