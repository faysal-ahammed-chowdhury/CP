#include <bits/stdc++.h>
using namespace std;

const int N = 105, K = 1e5 + 9, mod = 1e9 + 7;
int n, k, a[N], dp[N][K];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = n + 1; i >= 1; i--) {
    for (int remaining = 0; remaining <= k; remaining++) {
      if (i == n + 1) {
        if (remaining == 0) dp[i][remaining] = 1;
        else dp[i][remaining] = 0;
      }
      else {
        int &ans = dp[i][remaining];
        // ans = 0;
        // for (int j = 0; j <= a[i]; j++) {
        //   if (remaining >= j) {
        //     ans += dp[i + 1][remaining - j];
        //     ans %= mod;
        //   }
        // }
        int l = max(0, remaining - a[i]), r = remaining;
        ans = (dp[i + 1][r] - (l ? dp[i + 1][l - 1] : 0) + mod) % mod;
      }
    }
    for (int j = 1; i != 1 and j <= k; j++) {
      dp[i][j] += dp[i][j - 1];
      dp[i][j] %= mod;
    }
  }

  cout << dp[1][k] << '\n';

  return 0;
}