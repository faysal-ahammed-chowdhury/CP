#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int x[n + 1], y[n + 1];
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
  map<pair<int, int>, int> mp;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int mid_x = x[i] + x[j];
      int mid_y = y[i] + y[j];
      mp[make_pair(mid_x, mid_y)]++;
    }
  }
  long long ans = 0;
  for (auto [_, cnt] : mp) {
    ans += (1ll * cnt * (cnt - 1)) / 2;
  }
  cout << ans << '\n';

  return 0;
}