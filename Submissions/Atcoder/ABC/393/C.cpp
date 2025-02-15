#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  map<pair<int, int>, int> mp;
  while (m--) {
    int u, v; cin >> u >> v;
    mp[{min(u, v), max(u, v)}]++;
  }

  int ans = 0;
  for (auto [p, cnt] : mp) {
    auto [u, v] = p;
    if (u == v) ans += cnt;
    else ans += cnt - 1;
  }
  cout << ans << '\n';

  return 0;
}