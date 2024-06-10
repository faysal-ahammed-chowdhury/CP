#include <bits/stdc++.h>
using namespace std;

const int N = 2000, mod = 1e9 + 7;
int fact[N], ifact[N];

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

int inverse(int x) {
  return power(x, mod - 2, mod);
}

void prec() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1ll * fact[i - 1] * i % mod;
  }
  ifact[N - 1] = inverse(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
  }
}

const int M = 22;
int n, m, x, dp[M][N];

int fun(int i, int last) {
  if (i == x + 1) {
    return 1; 
  }
  int &ans = dp[i][last];
  if (ans != - 1) return ans;

  ans = 0;
  for (int j = last; j <= n; j++) {
    ans += fun(i + 1, j);
    ans %= mod;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  prec();

  cin >> n >> m;
  x = m + m;

  // int ans = 1ll * (1ll * fact[n + x - 1] * (1ll * ifact[n - 1] * ifact[x] % mod) % mod);
  // cout << ans << '\n';

  memset(dp, -1, sizeof dp);
  cout << fun(1, 1) << '\n';

  return 0;
}