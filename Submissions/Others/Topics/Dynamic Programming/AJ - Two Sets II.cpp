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

int fun(int i, int sum) {
  if (i == 0) {
    if (sum == 0) return 1;
    else return 0;
  }
  int &ans = dp[i][sum];
  if (ans != -1) return ans;
  ans = fun(i - 1, sum);
  if (sum >= i) {
    ans += fun(i - 1, sum - i);
    ans %= mod;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int sum = n * (n + 1) / 2;

  if (sum & 1) {
    cout << 0 << '\n';
  }
  else {
    memset(dp, -1, sizeof dp);
    int x = power(2, mod - 2, mod);
    cout << (1ll * fun(n, sum / 2) * x) % mod << '\n';
  }

  return 0;
}