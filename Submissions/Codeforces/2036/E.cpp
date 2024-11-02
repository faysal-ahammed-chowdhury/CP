#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, q; cin >> n >> m >> q;
  vector<vector<int>> a(m + 1, vector<int>(n + 1, 0)),  b(m + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[j][i];
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      b[i][j] = b[i][j - 1] | a[i][j];
    }
  }

  while (q--) {
    int req; cin >> req;
    int mn = 1, mx = n;
    while (req--) {
      int r; cin >> r;
      char c; cin >> c;
      int val; cin >> val;

      if (c == '>') {
        // cout << r << '\n';
        // for (auto x : b[r]) {
        //   cout << x << ' ';
        // }
        // cout << '\n';
        auto it = upper_bound(b[r].begin(), b[r].end(), val);
        int idx = it - b[r].begin();
        // cout << idx << '\n';
        mn = max(mn, idx);
      }
      else {
        // cout << r << '\n';
        // for (auto x : b[r]) {
        //   cout << x << ' ';
        // }
        // cout << '\n';
        auto it = upper_bound(b[r].begin(), b[r].end(), val);
        int idx = it - b[r].begin() - 1;
        // cout << idx << '\n';
        mx = min(mx, idx);
      }
    }

    if (mn > mx) {
      cout << -1 << '\n';
    }
    else cout << mn << '\n';
    // cout << mn << ' ' << mx << '\n';
  }

  return 0;
}