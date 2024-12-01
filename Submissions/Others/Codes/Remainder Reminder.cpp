#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  if (k == 0) {
    cout << 1ll * n * n << '\n';
    return 0;
  }
  
  ll ans = 0;
  for (int i = k + 1; i <= n; i++) {
    for (int j = 0; j <= n; j += i) {
      int l = j + k, r = j + i - 1;
      if (l > n) continue;
      r = min(r, n);
      int cur = r - l + 1;
      // cout << i << ' ' << l << ' ' << r << ' ' << cur << '\n';
      ans += max(0, cur);
    }
  }
  cout << ans << '\n';

  return 0;
}