#include <bits/stdc++.h>
using namespace std;

const int N = 505, MAX_VAL = 63000, mod = 1e9 + 7;
int dp[N][MAX_VAL];

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int sum = n * (n + 1) / 2;
  int per = sum / 2;

  if (sum & 1) {
    cout << 0 << '\n';
  }
  else {
    int x = power(2, mod - 2, mod);
    for (int i = 0; i <= n; i++) {
      for (int sum = 0; sum <= per; sum++) {
        if (i == 0) {
          if (sum == 0) dp[i][sum] = 1;
          else dp[i][sum] = 0;
        }
        else {
          int &ans = dp[i][sum];
          ans = dp[i - 1][sum];
          if (sum >= i) {
            ans += dp[i - 1][sum - i];
            ans %= mod;
          }
        }
      }
    }
    cout << (1ll * dp[n][per] * x) % mod << '\n';
  }

  return 0;
}