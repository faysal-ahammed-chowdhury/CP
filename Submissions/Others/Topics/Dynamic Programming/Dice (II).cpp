#include <bits/stdc++.h>
using namespace std;

const int N = 1005, K = 1005, S = 15005, mod = 1e8 + 7;
int n, k, s, dp[2][S];
int pref[S];

int cs = 0;
void solve() {
  cin >> n >> k >> s;
  memset(dp, 0, sizeof(dp));
  for (int i = n + 1; i >= 1; i--) {
    for (int cur_sum = 0; cur_sum <= s; cur_sum++) {
      if (i == n + 1) {
        dp[0][cur_sum] = cur_sum == 0;
      }
      else {
        int &ans = dp[0][cur_sum];
        ans = 0;
        int mn = min(k, cur_sum);
        // for (int x = 1; x <= mn; x++) {
        //   ans += 1ll * x * dp[1][cur_sum - x] % mod;
        //   ans %= mod;
        // }
        int l = cur_sum - mn, r = cur_sum - 1;
        ans = (pref[l] - pref[r + 1] + mod) % mod;
        ans -= 1ll * (s - r) * ((dp[1][r] - (l ? dp[1][l - 1] : 0) + mod) % mod) % mod;
        ans += mod;
        ans %= mod;
      }
    }
    for (int cur_sum = 0; cur_sum <= s; cur_sum++) {
      dp[1][cur_sum] = dp[0][cur_sum];
    }
    pref[0] = dp[1][0];
    for (int cur_sum = 1; i != 1 and cur_sum <= s; cur_sum++) {
      pref[cur_sum] = dp[1][cur_sum];
      dp[1][cur_sum] += dp[1][cur_sum - 1];
      dp[1][cur_sum] %= mod;
    }
    for (int cur_sum = s - 1, j = 2; i != 1 and cur_sum >= 0; cur_sum--, j++) {
      pref[cur_sum] = (1ll * pref[cur_sum] * j % mod) + pref[cur_sum + 1];
      pref[cur_sum] %= mod;
    }
  }
  cout << "Case " << ++cs << ": ";
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