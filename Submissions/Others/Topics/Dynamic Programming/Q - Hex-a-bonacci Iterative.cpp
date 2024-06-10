#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 10005, mod = 10000007;
int dp[N];

int cs = 0;
void solve() {
  memset(dp, 0, sizeof(dp));
  int n;
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f >> n;
  dp[0] = a, dp[1] = b, dp[2] = c, dp[3] = d, dp[4] = e, dp[5] = f;

  for(int i = 6; i <= n; i++) {
    dp[i] += dp[i - 1] % mod;
    dp[i] += dp[i - 2] % mod;
    dp[i] += dp[i - 3] % mod;
    dp[i] += dp[i - 4] % mod;
    dp[i] += dp[i - 5] % mod;
    dp[i] += dp[i - 6] % mod;
    dp[i] %= mod;
  }
  cout << "Case " << ++cs << ": " << dp[n] % mod << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}