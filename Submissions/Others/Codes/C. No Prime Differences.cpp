#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  int a[n + 1][m + 1];
  int x = 1;
  for (int i = 2; i <= n; i += 2) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = x++;
    }
  }
  for (int i = 1; i <= n; i += 2) {
    for (int j = 1; j <= m; j++) {
      a[i][j] = x++;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
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