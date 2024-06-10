#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5005;
const ll inf = 1e18;
int n, a[N];
ll dp[N][N][2];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= n; j++) {
      for (int last = 1; last >= 0; last--) {
        if (i > j) dp[i][j][last] = 0;
        else {
          ll &ans = dp[i][j][last];
          ans = -inf;
          if (last & 1) {
            ans = max(ans, dp[i + 1][j][0]);
            ans = min(ans, dp[i][j - 1][0]);
          }
          else {
            ans = max(ans, a[i] + dp[i + 1][j][1]);
            ans = max(ans, a[j] + dp[i][j - 1][1]);
          }
        }
      }
    }
  }

  cout << dp[1][n][0] << '\n';

  return 0;
}