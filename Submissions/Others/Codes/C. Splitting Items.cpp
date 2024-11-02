#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  for (int i = 2; i <= n; i += 2) {
    int d = a[i - 1] - a[i];
    a[i] += min(d, k);
    k -= min(d, k);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i & 1) ans += a[i];
    else ans -= a[i];
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