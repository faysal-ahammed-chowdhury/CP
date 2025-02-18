#include <bits/stdc++.h>
using namespace std;

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1][m + 1];
  map<int, set<pair<int, int>>> mp;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      mp[a[i][j]].insert({i, j});
    }
  }

  int ans = 0, mx = 0;
  for (auto [col, se] : mp) {
    int cur = 1;
    for (auto [x, y] : se) {
      bool found = false;
      for (int k = 0; k < 4; k++) {
        int nwx = x + dx[k], nwy = y + dy[k];
        if (se.find({nwx, nwy}) != se.end()) {
          cur++;
          found = true;
          break;
        }
      }
      if (found) break;
    }
    ans += cur;
    mx = max(mx, cur);
  }
  ans -= mx;

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}