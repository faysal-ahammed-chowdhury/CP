#include <bits/stdc++.h>
using namespace std;

void solve() {
  int m; cin >> m;
  int x, y;
  vector<pair<int, int>> a, ans;
  while (cin >> x >> y) {
    if (x == 0 and y == 0) break;
    a.push_back({x, y});
  }
  sort(a.begin(), a.end(), [&] (const pair<int, int> &p, const pair<int, int> &w) {return p.second > w.second;});
  int n = a.size();

  int start = 0;
  while (start < m) {
    int i;
    for (i = 0; i < n; i++) {
      if (a[i].first <= start and a[i].second > start) {
        ans.push_back(a[i]);
        start = a[i].second;
        break;
      }
    }
    if (i == n) break;
  }

  if (start < m) {
    cout << 0 << '\n';
    return;
  }
  cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    cout << x << ' ' << y << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}