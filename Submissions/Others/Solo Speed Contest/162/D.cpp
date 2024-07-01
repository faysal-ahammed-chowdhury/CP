#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int ans = 0;
  for (int i = 1; i * i <= m; i++) {
    if (m % i == 0) {
      if (1ll * i * n <= m) ans = max(ans, i);
      if (1ll * (m / i) * n <= m) ans = max(ans, m / i);
    }
  }
  cout << ans << '\n';

  return 0;
}