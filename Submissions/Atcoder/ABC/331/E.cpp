#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, l; cin >> n >> m >> l;
  int a[n + 1], b[m + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  set<pair<int, int>> se;
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    se.insert({b[i], i});
  }

  map<int, vector<int>> mp;
  for (int i = 1; i <= l; i++) {
    int x, y; cin >> x >> y;
    mp[x].push_back(y);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (mp.find(i) != mp.end()) {
      for (auto x : mp[i]) {
        se.erase({b[x], x});
      }
    }
    if (!se.empty()) {
      ans = max(ans, a[i] + (*se.rbegin()).first);
    }
    if (mp.find(i) != mp.end()) {
      for (auto x : mp[i]) {
        se.insert({b[x], x});
      }
    }
  }
  cout << ans << '\n';

  return 0;
}