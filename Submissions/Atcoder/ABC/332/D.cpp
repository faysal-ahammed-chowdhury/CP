#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int a[6][6], b[6][6];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> b[i][j];
    }
  }

  int p[6], q[6];
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int j = 1; j <= m; j++) q[j] = j;

  int ans = inf;
  do {
    do {
      bool ok = true;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          if (a[p[i]][q[j]] != b[i][j]) {
            ok = false;
            break;
          }
        }
      }

      if (!ok) continue;

      int pinv = 0, qinv = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (i < j and p[i] > p[j]) pinv++;
        }
      } 
      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
          if (i < j and q[i] > q[j]) qinv++;
        }
      } 
      ans = min(ans, pinv + qinv);

    } while (next_permutation(q + 1, q + m + 1));
  } while (next_permutation(p + 1, p + n + 1));

  cout << (ans == inf ? -1 : ans) << '\n';

  return 0;
}