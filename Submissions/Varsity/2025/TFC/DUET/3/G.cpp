#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 1005, K = 12, mod = 998244353;
int n, m, k;
int dp[N][N];
int inv;

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

int f(int i, int k) {
  if (i == n) return 1;
  if (k == 0) return 0;
  int &ans = dp[i][k];
  if (ans != -1) return ans;
  ans = 0;
  for (int j = 1; j <= m; j++) {
    int x = i + j;
    if (x > n) x = n - (x - n);
    ans += f(x, k - 1);
    ans %= mod;
  }
  ans = (1ll * ans * inv % mod);
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  inv = power(m, mod - 2, mod);

  memset(dp, -1, sizeof dp);
  // cout << power(2, mod - 2, mod) << '\n';
  // cout << 1ll * f(0, k) * power(n * m * k, mod - 2, mod) % mod << '\n';
  cout << f(0, k) << '\n';

  return 0;
}