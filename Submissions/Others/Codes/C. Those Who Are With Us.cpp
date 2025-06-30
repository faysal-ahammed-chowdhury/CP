#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1][m + 1];
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      mx = max(mx, a[i][j]);
    }
  }

  int here = 0, col = -1;
  for (int j = 1; j <= m; j++) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt += a[i][j] == mx;
    }
    if (cnt > 1) col = j;
    here += cnt > 1;
  }

  if (here >= 2) {
    cout << mx << '\n';
    return;
  }

  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j == col or a[i][j] != mx) continue;
      mp[i]++;
    }
  }

  // for (auto x : se) {
  //   cout << x << ' ';
  // } cout << '\n';

  if (here == 0) {
    bool ok = mp.size() == 2;
    if (ok) {
      bool flag = false;
      for (auto [_, x] : mp) {
        flag |= x == 1;
      }
      ok &= flag;
    }
    if (mp.size() <= 1 or ok) cout << mx - 1 << '\n';
    else cout << mx << '\n';
    return;
  }

  if (mp.size() <= 1) cout << mx - 1 << '\n';
  else cout << mx << '\n';
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