#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9, mod = 1e9 + 7;
int n, dp[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  dp[0] = 1;
  for(int i = 1; i <= n; i++) {
    int ans = 0;
    for(int j = 1; j <= 6; j++) {
      if(j <= i) {
        ans += dp[i - j] % mod;
        ans %= mod;
      }
    }
    dp[i] = ans;
  }

  cout << dp[n] << '\n';

  return 0;
}