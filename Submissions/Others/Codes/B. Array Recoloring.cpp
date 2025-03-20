#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (k == 1) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (i != 1) ans = max(ans, a[i] + a[1]);
      if (i != n) ans = max(ans, a[i] + a[n]);
    }
    cout << ans << '\n';
    return;
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  ll ans = 0;
  for (int i = 1; i <= k + 1; i++) {
    ans += a[i];
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