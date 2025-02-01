#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  string s[n + 1], t[m + 1];
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = '.' + s[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> t[i];
    t[i] = '.' + t[i];
  }


  for (int i = 1; i + m - 1 <= n; i++) {
    for (int j = 1; j + m - 1 <= n; j++) {
      bool ok = true;
      for (int ii = 1; ii <= m; ii++) {
        for (int jj = 1; jj <= m; jj++) {
          if (s[i + ii - 1][j + jj -1] != t[ii][jj]) {
            ok = false;
            break;
          }
        }
        if (ok == false) break;
      }
      if (ok) {
        cout << i << ' ' << j << '\n';
        return 0;
      }
    }
  }

  return 0;
}