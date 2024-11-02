#include <bits/stdc++.h>
using namespace std;

const int N = 105, X = 1e6 + 9, mod = 1e9 + 7;
int n, x, value[N], dp[N][X];

// int f(int i, int cur_sum) {
//   if (i > n) return cur_sum == 0;
//   int &ans = dp[i][cur_sum];
//   if (ans != -1) return ans;
//   ans = f(i + 1, cur_sum);
//   if (cur_sum >= value[i]) {
//     ans += f(i, cur_sum - value[i]);
//     ans %= mod;
//   }
//   return ans;
// }

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> value[i];
  }
  // memset(dp, -1, sizeof dp);
  // cout << f(1, x) << '\n';

  for (int cur_sum = 0; cur_sum <= x; cur_sum++) {
    dp[n + 1][cur_sum] = cur_sum == 0;
  }

  for (int i = n; i >= 1; i--) {
    for (int cur_sum = 0; cur_sum <= x; cur_sum++) {
      dp[i][cur_sum] = dp[i + 1][cur_sum];
      if (cur_sum >= value[i]) dp[i][cur_sum] += dp[i][cur_sum - value[i]];
      dp[i][cur_sum] %= mod;
    }
  }

  cout << dp[1][x] << '\n';

  return 0;
}