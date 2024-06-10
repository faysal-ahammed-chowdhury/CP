#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c, k; cin >> a >> b >> c >> k;
  int ans = 0;
  ans += min(a, k);
  k -= min(a, k);
  if (k > 0) {
    k -= min(b, k);
  }
  if (k > 0) {
    ans -= min(k, c);
  }

  cout << ans << '\n';

  return 0;
}