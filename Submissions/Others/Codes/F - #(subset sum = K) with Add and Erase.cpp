#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 5005, mod = 998244353;
int dp[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q, k; cin >> q >> k;
  dp[0] = 1;

  while (q--) {
    char type; cin >> type;
    int x; cin >> x;
    if (type == '+') {
      for (int i = k; i - x >= 0; i--) {
        dp[i] += dp[i - x];
        dp[i] %= mod;
      }
    }
    else {
      for (int i = x; i <= k; i++) {
        dp[i] -= dp[i - x];
        if (dp[i] < 0) dp[i] += mod;
      }
    }
    cout << dp[k] << '\n';
  }

  return 0;
}