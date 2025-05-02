#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;

  int mn = k / n;
  int mx = (k + n - 1) / n;
  ll ans = 1ll * (mx - mn) * (mx - mn) * 2;

  char s[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      s[i][j] = '0';
    }
  }

  set<int> se[n + 1];

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      se[i].insert(j);
    }
  }

  int it = 1;
  while (true) {
    if (k <= 0) break;
    int idx = -1;
    for (int i = 1; i <= n; i++) {
      if (k <= 0) break;
      int j = i + it - 1;
      if (j > n) {
        idx = i;
        break;
      }
      // cout << i << ' ' << j << '\n';
      s[i][j] = '1';
      se[i].erase(j);
      k--;
    }
    if (k <= 0) break;
    for (int i = idx; idx != -1 and k > 0 and i <= n; i++, k--) {
      int j = *se[i].begin();
      se[i].erase(se[i].begin());
      s[i][j] = '1';
    }
    it++;
  }

  cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << s[i][j];
    }
    cout << '\n';
  }
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