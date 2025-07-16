#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[] = { +0, +0, +1, -1, -1, +1, -1, +1};
int dy[] = { -1, +1, +0, +0, +1, +1, -1, -1};

const ll inf = 1e18;
int n, m;
bool is_valid(int i, int j) {
  return i >= 1 and i <= n and j >= 1 and j <= m;
}

void solve() {
  cin >> n >> m;
  int a[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  ll dp[n + 1][m + 1][2], pref_row[n + 1][m + 1], pref_col[m + 1][n + 1];
  memset(dp, -1, sizeof dp);
  memset(pref_row, 0, sizeof pref_row);
  memset(pref_col, 0, sizeof pref_col);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref_row[i][j] = pref_row[i][j - 1] + a[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref_col[j][i] = pref_col[j][i - 1] + a[i][j];
    }
  }

  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      for (int d = 0; d <= 1; d++) {
        if (i == n and j == m) {
          dp[i][j][d] = a[i][j];
        }
        else {
          ll &ans = dp[i][j][d];
          ans = -inf;
          if (j <= m) {
            ll x = (m - 1 >= j ? (pref_row[i][m - 1] - pref_row[i][j - 1]) : 0);
            ans = max(ans, x + dp[i][m][d]);
          }
          if (i <= n) {
            ll x = (n - 1 >= i ? (pref_col[j][n - 1] - pref_col[j][i - 1]) : 0);
            ans = max(ans, x + dp[n][j][d]);
          }
        }
      }
    }
  }

  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      for (int d = 0; d <= 1; d++) {
        if (i == n and j == m) {
          continue;
        }
        else {
          ll &ans = dp[i][j][d];
          ans = -inf;
          if (j <= m) {
            ll x = (m - 1 >= j ? (pref_row[i][m - 1] - pref_row[i][j - 1]) : 0);
            ans = max(ans, x + dp[i][m][d]);
          }
          if (i <= n) {
            ll x = (n - 1 >= i ? (pref_col[j][n - 1] - pref_col[j][i - 1]) : 0);
            ans = max(ans, x + dp[n][j][d]);
          }

          if (d == 0) {
            for (int k = 4; k < 8; k++) {
              int nwi = i + dx[k], nwj = j + dy[k];
              if (is_valid(nwi, nwj)) {
                ans = max(ans, a[i][j] + dp[nwi][nwj][1]);
              }
            }
          }
        }
      }
    }
  }

  cout << dp[1][1][0] << '\n';
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