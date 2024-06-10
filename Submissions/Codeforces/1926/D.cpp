#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  map<int, int> mp;
  set<pair<int, int>> se;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x]++;
    int y = 0;
    for (int k = 0; k <= 30; k++) {
      if (!(x & (1 << k))) {
        y += (1 << k);
      }
    }
    if (x > y) swap(x, y);
    se.insert({x, y});
  }
  int ans = 0;
  for (auto [x, y] : se) {
    ans += max(mp[x], mp[y]);
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}