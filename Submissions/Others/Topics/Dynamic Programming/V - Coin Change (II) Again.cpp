#include <bits/stdc++.h>
using namespace std;

const int N = 105, K = 10005, mod = 100000007;
int n, k, a[N], dp[N][K];

int cs = 0;
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n + 1; i >= 1; i--) {
    for (int sum = 0; sum <= k; sum++) {
      if (i == n + 1) dp[i][sum] = sum == 0;
      else {
        int &ans = dp[i][sum];
        ans = 0;
        // for (int cnt = 0; cnt <= sum; cnt += a[i]) {
        //   ans += dp[i + 1][sum - cnt];
        // }
        int x = sum % a[i];
        ans += dp[i + 1][sum] + (-(x - a[i] < 0 ? 0 : dp[i + 1][x - a[i]]) % mod) + mod;
        ans %= mod;
      }
    }
    int pos = i - 1;
    for (int sum = 0; i != 1 and sum <= k; sum++) {
      if (sum - a[pos] >= 0) {
        dp[i][sum] += dp[i][sum - a[pos]];
        dp[i][sum] %= mod;
      }
    }
  }
  cout << "Case " << ++cs << ": ";
  cout << dp[1][k] << '\n';
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