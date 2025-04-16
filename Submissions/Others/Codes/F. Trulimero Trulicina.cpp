#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  if (n % k == 0 or m % k == 0) {
    bool flag = false;
    if (n % k != 0) {
      swap(n, m);
      flag = true;
    }

    int a[n + 1][m + 1];

    for (int j = 1; j <= m; j++) {
      int st = (j & 1) ? 1 : 2;
      for (int i = 1; i <= n; i++) {
        a[i][j] = st++;
        if (st > k) st = 1;
      }
    }

    if (flag) {
      for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
          // cout << i << ' ' << j << '\n';
          cout << a[i][j] << ' ';
        }
        cout << '\n';
      }
    }
    else {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          cout << a[i][j] << ' ';
        }
        cout << '\n';
      }
    }

    return;
  }

  int st = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << st++ << ' ';
      if (st > k) st = 1;
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