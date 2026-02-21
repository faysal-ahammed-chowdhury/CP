#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, x, y; cin >> n >> x >> y;
  int a[n + 1];
  int contrib[n + 1];
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    contrib[i] = (a[i] / x) * y;
    sum += contrib[i];
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, sum - contrib[i] + a[i]);
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