#include <bits/stdc++.h>
using namespace std;

const int N = 1005, K = 1005, S = 15005, mod = 1e8 + 7;
int n, k, s, dp[2][S];

int cs = 0;
void solve() {
  cin >> n >> k >> s;
  cout << "Case " << ++cs << ": ";
  for (int i = n + 1; i >= 1; i--) {
    for (int cur_sum = 0; cur_sum <= s; cur_sum++) {
      if (i == n + 1) {
        dp[0][cur_sum] = (cur_sum == 0);
      }
      else {
        int &ans = dp[0][cur_sum];
        int mn = min(k, cur_sum);
        ans = 0;
        // for (int x = 1; x <= mn; x++) {
        //   ans += dp[1][cur_sum - x];
        //   ans %= mod;
        // }
        ans = (dp[1][cur_sum - 1] - (cur_sum - mn - 1 < 0 ? 0 : dp[1][cur_sum - mn - 1]) + mod) % mod;
      }
    }
    for (int cur_sum = 0; cur_sum <= s; cur_sum++) {
      dp[1][cur_sum] = dp[0][cur_sum];
    }
    for (int cur_sum = 1; i != 1 and cur_sum <= s; cur_sum++) {
      dp[1][cur_sum] += dp[1][cur_sum - 1];
      dp[1][cur_sum] %= mod;
    }
  }
  cout << dp[0][s] << '\n';
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