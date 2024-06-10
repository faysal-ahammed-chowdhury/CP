#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int a[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  bool status[n + 1];
  for (int i = 1; i <= n; i++) {
    bool ok = true;
    for (int j = 2; j <= m; j++) {
      ok &= a[i][j] == a[i][j - 1];
    }
    status[i] = ok;
  }

  int ans[n + 1];
  int xr = 0;
  for (int i = 1; i <= n; i++) {
    xr ^= a[i][1];
    ans[i] = 1;
  }

  if (xr > 0) {
    cout << "TAK\n";
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    if (!status[i]) {
      for (int j = 1; j <= m; j++) {
        int tmp = xr;
        tmp ^= a[i][1];
        tmp ^= a[i][j];
        if (tmp > 0) {
          ans[i] = j;
          cout << "TAK\n";
          for (int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
          }
          cout << '\n';
          return 0;
        }
      }
    }
  }
  cout << "NIE\n";

  return 0;
}