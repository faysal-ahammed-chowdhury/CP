#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 9, inf = 1e18;
int n, a[N], b[N], c[N];
int dp[N][2][2][2];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  for (int i = n + 1; i >= 1; i--) {
    for (int p = 0; p < 2; p++) {
      for (int q = 0; q < 2; q++) {
        for (int r = 0; r < 2; r++) {
          if (i == n + 1) {
            if (p and q and r) dp[i][p][q][r] = 0;
            else dp[i][p][q][r] = -inf;
          }
          else {
            int &ans = dp[i][p][q][r];
            ans = dp[i + 1][p][q][r];
            if (p == 0) {
              ans = max(ans, a[i] + dp[i + 1][1][q][r]);
            }
            if (q == 0) {
              ans = max(ans, b[i] + dp[i + 1][p][1][r]);
            }
            if (r == 0) {
              ans = max(ans, c[i] + dp[i + 1][p][q][1]);
            }
          }
        }
      }
    }
  }
  cout << dp[1][0][0][0] << '\n';
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