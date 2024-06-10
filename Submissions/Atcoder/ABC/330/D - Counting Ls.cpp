#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  char s[n + 1][n + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s[i][j];
    }
  }

  int row_cnt[n + 1], col_cnt[n + 1];
  memset(row_cnt, 0, sizeof row_cnt);
  memset(col_cnt, 0, sizeof col_cnt);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i][j] == 'o') {
        row_cnt[i]++;
        col_cnt[j]++;
      }
    }
  }

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i][j] == 'o') {
        ans += 1ll * (row_cnt[i] - 1) * (col_cnt[j] - 1);
      }
    }
  }
  cout << ans << '\n';

  return 0;
}