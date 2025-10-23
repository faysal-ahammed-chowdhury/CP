#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  string s[n + 1];
  int x = m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '@' + s[i];
    int cnt = 0;
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '#') cnt++;
      else {
        if (cnt > 0) x = min(x, cnt);
        cnt = 0;
      }
    }
    if (cnt > 0) x = min(x, cnt);
  }

  vector<int> divs;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      divs.push_back(i);
      if (i != (x / i)) divs.push_back(x / i);
    }
  }

  sort(divs.rbegin(), divs.rend());

  for (auto d : divs) {
    int vis[n + 1][m + 1];
    memset(vis, false, sizeof vis);
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (vis[i][j]) continue;
        if (s[i][j] == '.') continue;
        if (!(i + d - 1 <= n and j + d - 1 <= m)) {
          ok = false;
          break;
        }
        for (int ii = i; ii <= i + d - 1; ii++) {
          for (int jj = j; jj <= j + d - 1; jj++) {
            if (vis[ii][jj] or s[ii][jj] == '.') {
              ok = false;
              break;
            }
            vis[ii][jj] = true;
          }
        }
      }
    }

    if (ok) {
      cout << d << '\n';
      return 0;
    }
  }

  return 0;
}