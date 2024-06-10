#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e3 + 9, inf = 1e9;
ll n, x, a[N];
int dp[N][N][2];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof dp);

  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] %= x;
  }

  for (int i = n + 1; i >= 1; i--) {
    for (int mul = x - 1; mul >= 0; mul--) {
      for (int nisi = 1; nisi >= 0; nisi--) {
        if (i == n + 1) {
          dp[i][mul][nisi] = (nisi and mul == 0) ? 0 : inf;
        }
        else {
          int &ans = dp[i][mul][nisi];
          ans = dp[i + 1][mul][nisi];
          ans = min(ans, 1 + dp[i + 1][(1ll * mul * a[i]) % x][1]);
        }
      }
    }
  }

  cout << dp[1][1][0] << '\n';

  return 0;
}